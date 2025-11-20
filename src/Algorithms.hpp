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
        virtual std::string getName() =0;
        virtual std::string getDescription() =0; 
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
        std::string getDescription() override
        {
            return "Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. Its average and worst-case time complexity is O(n^2), making it inefficient on large lists.";
        }
};

class SelectionSort : public Algorithm
{
    private:
        size_t i = 0;         // Current index being filled
        size_t j = 1;         // Index scanning for minimum
        size_t minIndex = 0;  // Index of minimum in unsorted part
        bool done = false;    // Indicates sorting is complete

    public:
        SelectionSort() = default;
        ~SelectionSort() = default;

        bool step(std::vector<int>& data) override;
        void reset(std::vector<int>& data) override;

        std::string getName() override { return "Selection Sort"; }
        std::string getDescription() override
        {
            return "Selection Sort is an in-place comparison sorting algorithm. It divides the input list into two parts: a sorted sublist and an unsorted sublist. It repeatedly selects the smallest (or largest) element from the unsorted sublist, swapping it with the leftmost unsorted element, moving the boundary of the sorted sublist one element to the right. Its time complexity is O(n^2) in all cases, making it inefficient on large lists.";
        }
};

class InsertionSort : public Algorithm
{   
    private:
        bool done = false;
        int i = 1;
        int j = 0;
        int key = 0;

    public:
        InsertionSort() = default;
        ~InsertionSort() = default;
        
        bool step(std::vector<int>& data) override;
        void reset(std::vector<int>& data) override;

        std::string getName() override { return "Insertion Sort"; }
        std::string getDescription() override
        {
            return "Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, it has several advantages, such as simple implementation, efficient for small data sets, and more efficient in practice than most other simple quadratic algorithms such as selection sort or bubble sort.";
        }
};

class CombSort : public Algorithm
{   
    private:
        int gap = 0;
        int i = 0;
        bool swapped = true;
        
    public:
        CombSort() =default;
        ~CombSort() = default;
        
        bool step(std::vector<int>& data);
        void reset(std::vector<int>& data);

        std::string getName() override { return "Comb Sort"; }
        std::string getDescription() override
        {
            return "Comb Sort is an improvement over Bubble Sort that eliminates small values near the end of the list, which slow down the sorting process. It works by comparing elements at a certain gap and reducing the gap over time until it becomes 1, at which point it performs a final pass similar to Bubble Sort. Its average-case time complexity is O(n log n), making it more efficient than simple quadratic algorithms.";
        }
};

class ShellSort : public Algorithm
{   
    private:
    int gap = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    bool initialized = false;

    public:
        ShellSort() =default;
        ~ShellSort() = default;
        
        bool step(std::vector<int>& data);
        void reset(std::vector<int>& data);

        std::string getName() override { return "Shell Sort"; }

        std::string getDescription() override
        {
            return "Shell Sort is an in-place comparison sort that generalizes insertion sort to allow the exchange of items that are far apart. The idea is to arrange the list of elements so that, starting anywhere, taking every hth element produces a sorted list. Such a list is said to be h-sorted. The time complexity of Shell Sort depends on the gap sequence used, but it generally performs better than O(n^2) algorithms like bubble sort and insertion sort.";
        }
};

class RadixSort : public Algorithm
{
    private:
        struct Node
        {
            int data;
            Node* next;
            Node(int val) : data(val), next(nullptr) {}
        };

        Node* buckets[10];
        int exp = 1;
        bool done = false;
        int maxVal = 0;
        bool swapping = false;

        int index = 0;
        int bucketIndex = 0;
        
        int getMax(const std::vector<int>& data);
        void insertBuckets(Node*& head, int val);
        void clearBuckets();
    public:
        RadixSort() =default;
        ~RadixSort() = default;

        bool step(std::vector<int>& data) override;
        void reset(std::vector<int>& data) override;

        std::string getName() override { return "Radix Sort"; }
        std::string getDescription() override
        {
            return "Radix Sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value. It processes the digits from least significant to most significant. Its time complexity is O(d*(n+b)), where d is the number of digits in the largest number, n is the number of elements to be sorted, and b is the base of the numeral system.";
        }
};

// Recursive Sorts

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
        std::string getDescription() override
        {
            return "Merge Sort is a divide-and-conquer algorithm that divides the input array into two halves, sorts each half recursively, and then merges the two sorted halves back together. It is efficient and has a time complexity of O(n log n) in all cases, making it suitable for large datasets.";
        }
};

class QuickSort : public Algorithm
{
    private:
        struct State { int low, high, i, j, pivotVal; bool partitioning;};
        State m_state;
        Stack<std::pair<int, int>> m_sortStack;

        bool done = false;
    public:
        QuickSort() =default;
        ~QuickSort() = default;

        bool partitionStep(std::vector<int>& data);
        bool step(std::vector<int>& data);
        void reset(std::vector<int>& data);
        
        bool isSorted() const { return done; }
        std::string getName() override { return "Quick Sort"; }
        std::string getDescription() override
        {
            return "Quick Sort is a highly efficient sorting algorithm and is based on partitioning of array of data into smaller arrays. A large array is partitioned into two arrays one of which holds values smaller than the specified value, called pivot, based on which the partition is made and another array holds values greater than the pivot. The sub-arrays are then sorted recursively. Its average-case time complexity is O(n log n), making it suitable for large datasets.";
        }
};