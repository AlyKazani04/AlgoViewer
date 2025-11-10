#include "Algorithms.hpp"

// Iterative Sorts

bool BubbleSort::step(std::vector<int>& data)
{

}

void BubbleSort::reset(std::vector<int>& data)
{

}

bool SelectionSort::step(std::vector<int>& data)
{

}

void SelectionSort::reset(std::vector<int>& data)
{

}

bool InsertionSort::step(std::vector<int>& data)
{

}

void InsertionSort::reset(std::vector<int>& data)
{

}

bool CombSort::step(std::vector<int>& data)
{

}

void CombSort::reset(std::vector<int>& data)
{

}

bool ShellSort::step(std::vector<int>& data)
{

}

void ShellSort::reset(std::vector<int>& data)
{
    
}

// Recursive Sorts

bool MergeSort::step(std::vector<int>& data)
{
    if(done == true || callStack.isEmpty())
    {
        done = true;
        return false;
    }

    Frame& f = callStack.top();
    
    if(f.phase == 0) // split left phase
    {   
        if(f.left < f.mid)
        {
            callStack.push({f.left, (f.left + f.mid) / 2, f.mid, 0});
            f.phase = 1;
            return true;
        }
        f.phase = 1; 
    }

    if(f.phase == 1) // split right phase
    {
        if(f.mid + 1 < f.right)
        {
            callStack.push({f.mid + 1, (f.mid + 1 + f.right) / 2, f.right, 0});
            f.phase = 2;
            return true;
        }
        f.phase = 2;
    }
    
    if(f.phase == 2) // merge back phase
    {
        mergeStep(data, f.left, f.mid, f.right);
        callStack.pop();
        return true;
    }

    return true;
}

void MergeSort::mergeStep(std::vector<int>& data, int left, int mid, int right)
{
    std::vector<int> temp;
    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right)
    {
        if(data[i] < data[j])
        {
            temp.push_back(data[i++]);
        }
        else
        {
            temp.push_back(data[j++]);
        }
    }
    while(i <= mid)
    {
        temp.push_back(data[i++]);
    }

    while(j <= right)
    {
        temp.push_back(data[j++]);
    }

    for(int k = 0; k < (int)temp.size(); k++)
    {
        data[left + k] = temp[k];
    }
}

void MergeSort::reset(std::vector<int>& data)
{
    done = false;
    while(!callStack.isEmpty())
    {
        callStack.pop();
    }

    if(data.size() > 1)
    {
        callStack.push({0, (int)data.size() / 2, (int)data.size()- 1, 0});
    }

}

bool QuickSort::step(std::vector<int>& data) 
{
    if(!initialized) reset(data);
    if(callStack.isEmpty()) return false;

    Frame& f = callStack.top();

    // TODO: COMPLETE QUICK SORT
}

void QuickSort::reset(std::vector<int>& data)
{
    callStack = Stack<Frame>();
    if(!data.empty())
    {
        callStack.push({ 0, (int)data.size() - 1, 0, 0, 0, false });
    }

    initialized = true;
}