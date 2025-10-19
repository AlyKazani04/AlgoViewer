#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include "Algorithms.hpp"

const int DEFAULT_DATASET_SIZE = 10;
const int MAX_DATASET_SIZE = 50;

class Visualizer
{
    private:
        Algorithm* m_algorithm;
        std::vector<int> m_array;
        std::string m_algorithmName;
    public:
        Visualizer(int initsize);
        void update();
        void draw(sf::RenderWindow& window);
        void setAlgorithm(Algorithm* algo);
        ~Visualizer();
};
    