#include "Visualizer.hpp"

Visualizer::Visualizer() : m_algorithm(nullptr) {}

void Visualizer::draw(sf::RenderWindow& window) 
{
    float barWidth = (window.getSize().x / 2) / static_cast<float>(m_array.size());
    for (size_t i = 0; i < m_array.size(); ++i)
    {
        sf::RectangleShape bar({barWidth - 1, static_cast<float>(m_array[i])});
        bar.setPosition({i * barWidth + 10, window.getSize().y - 100});
        bar.setFillColor(sf::Color::White);
        window.draw(bar);
    }
}

void Visualizer::setAlgorithm(Algorithm* algo)
{
    m_algorithm = algo;
}

Visualizer::~Visualizer()
{
    delete m_algorithm;
}