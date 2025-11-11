#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "Stack.hpp"

/// @brief Base class for sorting algorithms
class Algorithm 
{   
    public:
        Algorithm() =default;
        virtual ~Algorithm() = default;
        
        virtual bool step(std::vector<int>& data) =0;
        virtual void reset(std::vector<int>& data) =0;
        virtual std::string getName() = 0;
};

// Iterative Sorts

class BubbleSort : public Algorithm
{
    private:
    size_t i = 0;
    size_t j = 0;
    bool done = false;
    
    public:
        BubbleSort() =default;
        ~BubbleSort() = default;
        
        bool step(std::vector<int>& data);
        void reset(std::vector<int>& data);
        
        std::string getName() override { return "Bubble Sort"; }
};

class SelectionSort : public Algorithm
{
    public:
    SelectionSort() =default;
    ~SelectionSort() = default;

    bool step(std::vector<int>& data);
    void reset(std::vector<int>& data);
    
    std::string getName() override { return "Selection Sort"; }
};

class InsertionSort : public Algorithm
{   
    public:
    InsertionSort() =default;
    ~InsertionSort() = default;
    
    bool step(std::vector<int>& data);
    void reset(std::vector<int>& data);

    std::string getName() override { return "Insertion Sort"; }
};

class CombSort : public Algorithm
{   
    public:
    CombSort() =default;
    ~CombSort() = default;
    
    bool step(std::vector<int>& data);
    void reset(std::vector<int>& data);

    std::string getName() override { return "Comb Sort"; }
};

class ShellSort : public Algorithm
{   
    public:
    ShellSort() =default;
    ~ShellSort() = default;
    
    bool step(std::vector<int>& data);
    void reset(std::vector<int>& data);

    std::string getName() override { return "Shell Sort"; }
};

// Recursive Sorts (uses CallStack)

class MergeSort : public Algorithm
{
    private:
        struct Frame { int left, mid, right, phase; };
        Stack<Frame> callStack;
        bool done = false;

        void mergeStep(std::vector<int>& data, int left, int mid, int right);
    public:
        MergeSort() =default;
        ~MergeSort() = default;

        bool step(std::vector<int>& data) override;
        void reset(std::vector<int>& data) override;
        std::string getName() override { return "Merge Sort"; }
};

class QuickSort : public Algorithm
{
    public:
        QuickSort() =default;
        ~QuickSort() = default;

        bool step(std::vector<int>& data);
        void reset(std::vector<int>& data);
        
        std::string getName() override { return "Quick Sort"; }
};