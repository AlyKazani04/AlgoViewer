#include "App.hpp"

Application::Application(int initSize) : m_visualizer(initSize), m_ui(&m_visualizer) 
{
    if(!m_modeTextureL.loadFromFile("../resources/lightmode.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_modeTextureL.setSmooth(false);

    if(!m_modeTextureD.loadFromFile("../resources/darkmode.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_modeTextureD.setSmooth(false);
}

bool Application::isDarkPressed(sf::RenderWindow& window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if(m_darkBounds.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_modeChangeCooldown.getElapsedTime().asSeconds() > 0.5f)
    {
        m_isDark = !m_isDark;
        m_modeChangeCooldown.restart();
        return true;
    }
    
    return false;
}

void Application::run()
{
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "AlgoViewer");

    sf::Clock deltaClock;
    window.setFramerateLimit(60);

    if(!ImGui::SFML::Init(window))
    {
        throw std::runtime_error("Failed to initialize ImGui-SFML");
    }

    while(window.isOpen())
    {
        while(const auto event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);

            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());
        m_visualizer.update(m_isDark);
        m_ui.showMenu();

        window.clear((m_isDark) ? sf::Color::Black : sf::Color::White);
        m_visualizer.draw(window);
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
}