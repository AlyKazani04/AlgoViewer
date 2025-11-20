#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>
#include "Algorithms.hpp"

const int DEFAULT_DATASET_SIZE = 50;
const int MAX_DATASET_SIZE = 200;
const int DEFAULT_STEP_TIME = 100; // 100 milliseconds

class Visualizer
{
    private:
        Algorithm* m_algorithm;
        std::string m_algorithmName;
        std::vector<int> m_array;
        int m_datasetSize;

        bool m_isSorting = false;

        sf::Clock m_stepClock;
        sf::Time m_elapsedTime;
    public:
        Visualizer(int initsize);
        ~Visualizer();

        void update();
        void draw(sf::RenderWindow& window);

        void randomizeData();
        void beginSort();
        void setDataSize(int size);
        void resetData();
        void setAlgorithm(Algorithm* algo);
        std::string getAboutInfo();
};
    