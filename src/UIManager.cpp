#include "UIManager.hpp"

void UIManager::showMenu()
{
    if(!m_isMenuOpen)
        return;
    
    ImGui::Begin("Menu");
    if(ImGui::Combo("Algorithm", &m_selectedAlgoIndex, "Bubble Sort\0Merge Sort\0Selection Sort\0Insertion Sort\0Quick Sort\0", 5))
    {
        switch(m_selectedAlgoIndex)
        {
            case 0:
                visuals->setAlgorithm(new BubbleSort());
                break;
            case 1:
                visuals->setAlgorithm(new MergeSort());
                break;
            case 2:
                visuals->setAlgorithm(new SelectionSort());
                break;
            case 3:
                visuals->setAlgorithm(new InsertionSort());
                break;
            case 4:
                visuals->setAlgorithm(new QuickSort());
                break;
            default:
                break;
        }
    }

    ImGui::End();
}