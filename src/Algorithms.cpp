#include "Algorithms.hpp"
#include <algorithm>
#include <vector>



// -------------------- Bubble Sort --------------------
bool BubbleSort::step(std::vector<int>& data)
{
    if (done || data.empty()) return false;

    if (i < data.size() - 1)
    {
        if (j < data.size() - i - 1)
        {
            if (data[j] > data[j + 1])
                std::swap(data[j], data[j + 1]);
            ++j;
        }
        else
        {
            j = 0;
            ++i;
        }
    }
    else
    {
        done = true;
        return false;
    }

    return true;
}

void BubbleSort::reset(std::vector<int>& data)
{
    i = 0;
    j = 0;
    done = false;
}

bool SelectionSort::step(std::vector<int>& data)
{
    (void)data;
    // TODO: implement step-by-step selection sort if required
    return false;
}

void SelectionSort::reset(std::vector<int>& data)
{
    (void)data;
    // reset internal state if implemented
}
// -------------------- Insertion Sort --------------------
bool InsertionSort::step(std::vector<int>& data)
{
    if (done || data.empty()) return false;

    if (i < static_cast<int>(data.size()))
    {
        if (j == i - 1)
            key = data[i];

        if (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            --j;
        }
        else
        {
            data[j + 1] = key;
            ++i;
            j = i - 1;
        }
    }
    else
    {
        done = true;
        return false;
    }

    return true;
}

void InsertionSort::reset(std::vector<int>& data)
{
    (void)data;
    done = false;
    i = 1;
    j = 0;
    key = 0;
}
// -------------------- Comb Sort (stub) --------------------
bool CombSort::step(std::vector<int>& data)
{
    (void)data;
    return false;
}

void CombSort::reset(std::vector<int>& data)
{
    (void)data;
}

// -------------------- Shell Sort (stub) --------------------
bool ShellSort::step(std::vector<int>& data)
{
    (void)data;
    return false;
}

void ShellSort::reset(std::vector<int>& data)
{
    (void)data;
}

// -------------------- Merge Sort (recursive using callStack) --------------------
bool MergeSort::step(std::vector<int>& data)
{
    if (done == true || callStack.isEmpty())
    {
        done = true;
        return false;
    }

    Frame& f = callStack.top();
    
    if (f.phase == 0) // split left phase
    {   
        if (f.left < f.mid)
        {
            callStack.push({f.left, (f.left + f.mid) / 2, f.mid, 0});
            f.phase = 1;
            return true;
        }
        f.phase = 1; 
    }

    if (f.phase == 1) // split right phase
    {
        if (f.mid + 1 < f.right)
        {
            callStack.push({f.mid + 1, (f.mid + 1 + f.right) / 2, f.right, 0});
            f.phase = 2;
            return true;
        }
        f.phase = 2;
    }
    
    if (f.phase == 2) // merge back phase
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
    int a = left;
    int b = mid + 1;

    while (a <= mid && b <= right)
    {
        if (data[a] < data[b])
            temp.push_back(data[a++]);
        else
            temp.push_back(data[b++]);
    }
    while (a <= mid) temp.push_back(data[a++]);
    while (b <= right) temp.push_back(data[b++]);

    for (int k = 0; k < static_cast<int>(temp.size()); ++k)
        data[left + k] = temp[k];
}

void MergeSort::reset(std::vector<int>& data)
{
    done = false;
    while (!callStack.isEmpty()) callStack.pop();

    if (data.size() > 1)
        callStack.push({0, static_cast<int>(data.size()) / 2, static_cast<int>(data.size()) - 1, 0});
}

bool QuickSort::partitionStep(std::vector<int>& data)
{
    if(!m_state.partitioning)
    {
        return true;
    }

    if(m_state.j < m_state.high)
    {
        if(data[m_state.j] <= m_state.pivotVal)
        {
            m_state.i++;
            std::swap(data[m_state.i], data[m_state.j]);
        }
        m_state.j++;
        return false; // Partitioning not complete
    }
    else
    {
        std::swap(data[m_state.i + 1], data[m_state.high]);
        return true; // Partitioning complete
    }
}

bool QuickSort::step(std::vector<int>& data) 
{
    if(isSorted()) return false;

    if(!m_state.partitioning)
    {
        if(m_sortStack.isEmpty())
        {
            done = true;
            return false;
        }
        std::pair<int, int> range = m_sortStack.top();
        m_sortStack.pop();
        
        m_state.low = range.first;
        m_state.high = range.second;

        if(m_state.low >= m_state.high)
        {
            return true; // No need to sort
        }

        m_state.pivotVal = data[m_state.high];
        m_state.i = m_state.low - 1;
        m_state.j = m_state.low;
        m_state.partitioning = true;
    }

    bool partitionComplete = partitionStep(data);

    if(partitionComplete)
    {
        int pivotIndex = m_state.i + 1;

        if(pivotIndex - 1 > m_state.low)
        {
            m_sortStack.push({ m_state.low, pivotIndex - 1 });
        }
        if(pivotIndex + 1 < m_state.high)
        {
            m_sortStack.push({ pivotIndex + 1, m_state.high });
        }
        m_state.partitioning = false;
    }
    return true;
}

void QuickSort::reset(std::vector<int>& data)
{
    m_sortStack = Stack<std::pair<int, int>>();
    while(!m_sortStack.isEmpty())
    {
        m_sortStack.pop();
    }

    m_sortStack.push({0, data.size() - 1});
    done = data.size() <= 1;
    m_state.partitioning = true;
}
