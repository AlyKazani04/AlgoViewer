#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include "Visualizer.hpp"

class UIManager
{
    private:
        Visualizer* visuals;
        int m_selectedAlgoIndex;
        bool m_isMenuOpen;
    public:
        
        UIManager(Visualizer* vis) : m_selectedAlgoIndex(0), m_isMenuOpen(true), visuals(vis) {}
        void showMenu();
        // TODO: Add more UI functionalities like start, pause, reset buttons, and speed control
};