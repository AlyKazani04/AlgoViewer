#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 800}), "AlgoViewer");

    ImGui::SFML::Init(window);

    sf::Clock deltaTime;
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

        ImGui::SFML::Update(window, deltaTime.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();
        
        window.clear(sf::Color::Black);

        ImGui::SFML::Render(window);
        window.display();

    }

    ImGui::SFML::Shutdown(window);
    return 0;
}