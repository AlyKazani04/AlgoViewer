#pragma once
#include <algorithm>
#include <vector>

/// @brief Base class for sorting algorithms
class Algorithm 
{   
    public:
        // virtual void sort(std::vector<int>& array) = 0;
        virtual ~Algorithm() = default;
};

class BubbleSort : public Algorithm
{
    int id;
    public:
        BubbleSort() =default;
        // void sort(std::vector<int>& array) override =0;
        ~BubbleSort() = default;
};

class MergeSort : public Algorithm
{
    int id;
    public:
        MergeSort() =default;
        // void sort(std::vector<int>& array) override =0;
        ~MergeSort() = default;
};

class SelectionSort : public Algorithm
{
    int id;
    public:
        SelectionSort() =default;
        // void sort(std::vector<int>& array) override =0;
        ~SelectionSort() = default;
};

class InsertionSort : public Algorithm
{
    int id;
    public:
        InsertionSort() =default;
        // void sort(std::vector<int>& array) override =0;
        ~InsertionSort() = default;
};

class QuickSort : public Algorithm
{
    int id;
    public:
        QuickSort() =default;
        // void sort(std::vector<int>& array) override =0;
        ~QuickSort() = default;
};