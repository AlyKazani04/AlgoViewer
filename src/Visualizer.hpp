#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include "Algorithms.hpp"

class Visualizer
{
    private:
        Algorithm* m_algorithm;
        std::vector<int> m_array;
    public:
        Visualizer();
        // void update(); // TODO: Update the array
        void draw(sf::RenderWindow& window);
        void setAlgorithm(Algorithm* algo);
        ~Visualizer();
};
    