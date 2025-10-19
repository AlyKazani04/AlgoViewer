#include "App.hpp"

Application::Application(int initSize) : m_visualizer(initSize), m_ui(&m_visualizer) {}

void Application::run()
{
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Sorting Visualizer");

    sf::Clock deltaClock;
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
        m_visualizer.update();
        m_ui.showMenu();

        window.clear(sf::Color::Black);
        m_visualizer.draw(window);
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
}