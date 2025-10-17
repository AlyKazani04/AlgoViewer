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
    public:
        Application();
        void run();
};