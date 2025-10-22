#include "Algorithms.hpp"

// Implementations for sorting algorithms will go here

void MergeSort::step(std::vector<int>& data)
{

}

void MergeSort::reset(std::vector<int>& data)
{
    done = false;
    while(!callStack.isEmpty())
    {
        callStack.pop();
    }
    callStack.push({0, (int)data.size() / 2, (int)data.size()- 1, 0});
}