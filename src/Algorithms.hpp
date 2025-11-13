#pragma once
#include <algorithm>
#include <vector>

/// @brief Base class for sorting algorithms
class Algorithm 
{   
    public:
        // virtual void sort(std::vector<int>& array) = 0;  // TODO: Define sorting for each algorithm and make this virtual
        virtual ~Algorithm() = default;
};

class BubbleSort : public Algorithm
{
    int id;
    public:
        BubbleSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
        ~BubbleSort() = default;
};

class MergeSort : public Algorithm
{
    int id;
    public:
        MergeSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
        ~MergeSort() = default;
};

class SelectionSort : public Algorithm
{
    int id;
    public:
        SelectionSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
        ~SelectionSort() = default;
};

class InsertionSort : public Algorithm
{
    int id;
    public:
        InsertionSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
       bool step(std::vector<int>& data);
       void reset(std::vector<int>& data); 
        ~InsertionSort() = default;
};

class QuickSort : public Algorithm
{
    int id;
    public:
        QuickSort() =default;
        // void sort(std::vector<int>& array) override =0;  // TODO: Sort Implementation
        ~QuickSort() = default;
};