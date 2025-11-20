#include "UIManager.hpp"

void UIManager::showMenu()
{
    if(!m_isMenuOpen)
        return;

    ImGui::Begin("Menu");

    ImGuiStyle& style = ImGui::GetStyle();
    style.FrameRounding = 5.0f;
    style.WindowRounding = 5.0f;
    style.ItemSpacing = ImVec2(10.f, 10.f);
    

    if(ImGui::Combo("Algorithm", &m_selectedAlgoIndex, "Bubble Sort\0Selection Sort\0Insertion Sort\0Comb Sort\0Shell Sort\0Radix Sort\0Merge Sort\0Quick Sort\0", 8))
    {
        switch(m_selectedAlgoIndex)
        {
            case 0:
                visuals->setAlgorithm(new BubbleSort());
                break;
            case 1:
                visuals->setAlgorithm(new SelectionSort());
                break;
            case 2:
                visuals->setAlgorithm(new InsertionSort());
                break;
            case 3:
                visuals->setAlgorithm(new CombSort());
                break;
            case 4:
                visuals->setAlgorithm(new ShellSort());
                break;
            case 5:
                visuals->setAlgorithm(new RadixSort());
                break;
            case 6:
                visuals->setAlgorithm(new MergeSort());
                break;
            case 7:
                visuals->setAlgorithm(new QuickSort());
                break;
            default:
                break;
        }
    }

    ImGui::Separator();

    static int size = DEFAULT_DATASET_SIZE;
    ImGui::SliderInt("Elements", &size, DEFAULT_DATASET_SIZE, MAX_DATASET_SIZE);

    if(ImGui::Button("Generate New Data", {150, 30}))
    {
        visuals->setDataSize(size);
    }

    if(ImGui::Button("Sort", {120, 30}))
    {
        visuals->beginSort();
    }

    ImGui::SameLine();
    if(ImGui::Button("Reset", {120, 30}))
    {
        visuals->resetData();
    }

    if(visuals->getAboutInfo() != "")
    {
        ImGui::Separator();
    
        if(ImGui::Button("About", {100, 30}))
        {
            ImGui::OpenPopup("About");
        }
        
        if(ImGui::BeginPopupModal("About", NULL, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::SetWindowFontScale(2.f);
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 40.f);
            ImGui::Text(visuals->getAboutInfo().c_str());
            ImGui::PopTextWrapPos();
            
            ImGui::Spacing();
            if(ImGui::Button("Back"))
            {
                ImGui::CloseCurrentPopup();
            }
            
            ImGui::SetWindowFontScale(1.f);
            ImGui::EndPopup();
        }
    }

    ImGui::End();
}