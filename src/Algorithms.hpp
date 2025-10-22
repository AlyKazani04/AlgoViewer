#pragma once
#include <string>
#include <vector>
#include "Stack.hpp"

/// @brief Base class for sorting algorithms
class Algorithm 
{   
    public:
        Algorithm() =default;
        virtual ~Algorithm() = default;
        
        virtual void step(std::vector<int>& data) =0;
        virtual void reset(std::vector<int>& data) =0;
        virtual std::string getName() = 0;
};

class BubbleSort : public Algorithm
{
    public:
        BubbleSort() =default;
        ~BubbleSort() = default;
        
        std::string getName() override { return "Bubble Sort"; }
};

class MergeSort : public Algorithm
{
    private:
        struct Frame { int left, mid, right, count; };
        Stack<Frame> callStack;
        bool done = false;
    public:
        MergeSort() =default;
        ~MergeSort() = default;

        void step(std::vector<int>& data) override;
        void reset(std::vector<int>& data) override;
        std::string getName() override { return "Merge Sort"; }
};

class SelectionSort : public Algorithm
{
    public:
        SelectionSort() =default;
        ~SelectionSort() = default;

        std::string getName() override { return "Selection Sort"; }
};

class InsertionSort : public Algorithm
{   
    public:
        InsertionSort() =default;
        ~InsertionSort() = default;
        
        std::string getName() override { return "Insertion Sort"; }
};

class QuickSort : public Algorithm
{
    public:
        QuickSort() =default;
        ~QuickSort() = default;
        
        std::string getName() override { return "Quick Sort"; }
};