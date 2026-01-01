#include "App.hpp"

Application::Application(int initSize) : m_visualizer(initSize), m_ui(&m_visualizer) 
{
    if(!m_modeTextureL.loadFromFile("resources/lightmode.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_modeTextureL.setSmooth(false);

    if(!m_modeTextureD.loadFromFile("resources/darkmode.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    m_modeTextureD.setSmooth(false);
}

void Application::isDarkPressed(sf::RenderWindow& window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if(m_darkBounds.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_modeChangeCooldown.getElapsedTime().asSeconds() > 0.5f)
    {
        m_isDark = !m_isDark;
        m_modeChangeCooldown.restart();
    }
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
            if(event->is<sf::Event::Resized>())
            {
                auto size = event->getIf<sf::Event::Resized>()->size;
                sf::View view;
                view.setSize({ static_cast<float>(size.x), static_cast<float>(size.y) });
                view.setCenter({ static_cast<float>(size.x) / 2.f, static_cast<float>(size.y) / 2.f });
                window.setView(view);
            }
        }

        // Update
        ImGui::SFML::Update(window, deltaClock.restart());
        m_visualizer.update(m_isDark);
        isDarkPressed(window);
        m_ui.showMenu();

        // Draw
        window.clear((m_isDark) ? sf::Color(24, 24, 24, 255) : sf::Color(252, 250, 235, 255)); // dark : light
        m_visualizer.draw(window);
        ImGui::SFML::Render(window);

        sf::Sprite modeSprite(m_modeTextureD);

        if(m_isDark)
        {
            modeSprite.setTexture(m_modeTextureL);
        }
        else
        {
            modeSprite.setTexture(m_modeTextureD);
        }

        modeSprite.setScale({1,1});

        sf::Rect<float> modebounds = modeSprite.getLocalBounds();
        modeSprite.setOrigin({modebounds.size.x / 2, modebounds.size.y / 2});

        modeSprite.setPosition({ modeSprite.getLocalBounds().size.x / 2.f + 10.f, static_cast<float>(window.getSize().y) / 2.f });

        m_darkBounds = modeSprite.getGlobalBounds();

        window.draw(modeSprite);
        window.display();
    }
    ImGui::SFML::Shutdown();
}