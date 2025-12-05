#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include "UIManager.hpp"
#include "Visualizer.hpp"

class Application
{
    private:
        UIManager m_ui;
        Visualizer m_visualizer;

        sf::Rect<float> m_darkBounds;
        sf::Texture m_modeTextureL;
        sf::Texture m_modeTextureD;
        bool m_isDark = true;
        sf::Clock m_modeChangeCooldown;

        void isDarkPressed(sf::RenderWindow& window);
    public:
        Application(int initSize = DEFAULT_DATASET_SIZE);
        void run();
};