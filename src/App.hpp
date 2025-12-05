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

        sf::Texture m_modeTextureL;
        sf::Texture m_modeTextureD;
    public:
        Application(int initSize = DEFAULT_DATASET_SIZE);
        void run();
};