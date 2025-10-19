#pragma once
#include <string>
#include <algorithm>
#include <vector>

/// @brief Base class for sorting algorithms
class Algorithm 
{   
    public:
        Algorithm() =default;
        // virtual void sort(std::vector<int>& array) = 0;  // TODO: Define sorting for each algorithm and make this virtual
        virtual std::string getName() = 0;
        virtual ~Algorithm() = default;
};

class BubbleSort : public Algorithm
{
    int id;
    public:
        BubbleSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
        std::string getName() override { return "Bubble Sort"; }
        ~BubbleSort() = default;
};

class MergeSort : public Algorithm
{
    int id;
    public:
        MergeSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
        std::string getName() override { return "Merge Sort"; }
        ~MergeSort() = default;
};

class SelectionSort : public Algorithm
{
    int id;
    public:
        SelectionSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
        std::string getName() override { return "Selection Sort"; }
        ~SelectionSort() = default;
};

class InsertionSort : public Algorithm
{
    int id;
    public:
        InsertionSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
        std::string getName() override { return "Insertion Sort"; }
        ~InsertionSort() = default;
};

class QuickSort : public Algorithm
{
    int id;
    public:
        QuickSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
        std::string getName() override { return "Quick Sort"; }
        ~QuickSort() = default;
};