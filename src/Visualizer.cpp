#include "Visualizer.hpp"

Visualizer::Visualizer(int initsize = DEFAULT_DATASET_SIZE) : m_array(initsize), m_algorithm(nullptr) 
{
    for(size_t i = 0; i < m_array.size(); i++)
    {
        m_array[i] = i + 1;
    }

    m_stepClock.reset();
}

Visualizer::~Visualizer()
{
    if(m_algorithm != nullptr)
    {
        delete m_algorithm;
    }
}

void Visualizer::update(bool darkFlag)
{
    m_algorithmName = m_algorithm ? m_algorithm->getName() : "Select an Algorithm";
    m_isDark = (darkFlag) ? true : false;

    if(m_isSorting && m_algorithm)
    {
        if(m_stepClock.getElapsedTime().asMilliseconds() >= DEFAULT_STEP_TIME)
        {
            if(!m_algorithm->step(m_array))
            {
                m_isSorting = false;
            }

            m_elapsedTime += m_stepClock.restart();
        }
    }
    else
    {
        m_stepClock.reset();
    }
}

void Visualizer::draw(sf::RenderWindow& window) 
{
    sf::Font font("resources/RobotoSlab-Medium.ttf");

    sf::Text title(font, m_algorithmName, 48);

    title.setFillColor((m_isDark) ? sf::Color::White : sf::Color::Black);
    title.setOrigin({title.getLocalBounds().size.x / 2.f, title.getLocalBounds().size.y / 2.f});
    title.setPosition({window.getSize().x / 2.f, 60.f});


    sf::Vector2f basePos = {window.getSize().x / 4.f, window.getSize().y - 100.f};
    
    float barWidth = (window.getSize().x / 2) / static_cast<float>(m_array.size());
    float maxBarHeight = window.getSize().y / 2.f;

    for (size_t i = 0; i < m_array.size(); i++)
    {
        sf::RectangleShape bar({barWidth - 1, float(m_array[i]) / m_array.size() * maxBarHeight});
        bar.setOrigin({0, bar.getSize().y});
        bar.setPosition({i * barWidth + basePos.x, basePos.y});
        bar.setFillColor((m_isDark) ? sf::Color::White : sf::Color::Black);

        window.draw(bar);
    }

    sf::Text elapsedTimeText(font, "Step Duration: " + std::to_string(DEFAULT_STEP_TIME) + " ms\nElapsed Time: " + std::to_string(m_elapsedTime.asSeconds()) + " seconds", 22);
    elapsedTimeText.setFillColor(sf::Color::White);
    elapsedTimeText.setPosition({10.f, window.getSize().y - elapsedTimeText.getLocalBounds().size.y - 10.f});

    window.draw(elapsedTimeText);
    window.draw(title);
}

void Visualizer::randomizeData()
{
    std::shuffle(m_array.begin(), m_array.end(), std::mt19937(std::random_device{}()));
}

void Visualizer::beginSort()
{
    if(m_algorithm && !m_isSorting)
    {
        m_isSorting = true;
        m_algorithm->reset(m_array);
        m_stepClock.restart();
        m_elapsedTime = sf::Time::Zero;
    }
}

void Visualizer::setDataSize(int size)
{
    m_array.resize(size);
    for(size_t i = 0; i < m_array.size(); i++)
    {
        m_array[i] = i + 1;
    }

    randomizeData();

    if(m_algorithm)
    {
        m_algorithm->reset(m_array);
    }
}

void Visualizer::resetData()
{
    for(size_t i = 0; i < m_array.size(); i++)
    {
        m_array[i] = i + 1;
    }

    randomizeData();
    if(m_algorithm)
    {
        m_algorithm->reset(m_array);
    }

    m_isSorting = false;
    m_stepClock.reset();
}

void Visualizer::setAlgorithm(Algorithm* algo)
{
    if(m_algorithm != nullptr)
    {
        delete m_algorithm;
    }
    m_algorithm = algo;
}

std::string Visualizer::getAboutInfo()
{
    if(m_algorithm)
    {
        return m_algorithm->getDescription();
    }

    return "";
}