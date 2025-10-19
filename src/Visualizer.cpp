#include "Visualizer.hpp"

Visualizer::Visualizer(int initsize = DEFAULT_DATASET_SIZE) : m_array(initsize), m_algorithm(nullptr) 
{
    for(size_t i = 0; i < m_array.size(); i++)
    {
        m_array[i] = i + 1;
    }
}

void Visualizer::update()
{
    m_algorithmName = m_algorithm ? m_algorithm->getName() : "Select an Algorithm";
    // m_algorithm.sort(m_array);
}

void Visualizer::draw(sf::RenderWindow& window) 
{
    sf::Font font("resources/RobotoSlab-Medium.ttf");

    sf::Text title(font, m_algorithmName, 48);

    title.setFillColor(sf::Color::White);
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
        bar.setFillColor(sf::Color::White);

        window.draw(bar);
    }

    window.draw(title);
}

void Visualizer::setAlgorithm(Algorithm* algo)
{
    if(m_algorithm != nullptr)
    {
        delete m_algorithm;
    }
    m_algorithm = algo;
}

Visualizer::~Visualizer()
{
    if(m_algorithm != nullptr)
    {
        delete m_algorithm;
    }
}