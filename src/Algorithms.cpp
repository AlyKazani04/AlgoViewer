#include "Algorithms.hpp"
#include <algorithm>
#include <vector>

// Iterative Sorts

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
    if (done || data.empty()) return false;

    // Outer loop: current index to fill
    if (i < data.size() - 1)
    {
        // Inner loop: find minimum in the unsorted part
        if (j < data.size())
        {
            if (data[j] < data[minIndex])
                minIndex = j;
            j++;
        }
        else
        {
            // Swap the found minimum with data[i]
            std::swap(data[i], data[minIndex]);
            i++;             // Move to next index
            j = i + 1;       // Reset scanning index
            minIndex = i;    // Reset minIndex for next pass
        }
    }
    else
    {
        done = true;  // Sorting is complete
        return false;
    }

    return true; // Step completed, sorting not done yet
}

void SelectionSort::reset(std::vector<int>& data)
{
    i = 0;
    j = 1;
    minIndex = 0;
    done = false;
}

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
    done = false;
    i = 1;
    j = 0;
    key = 0;
}

bool CombSort::step(std::vector<int>& data)
{
    return false;
}

void CombSort::reset(std::vector<int>& data)
{

}

bool ShellSort::step(std::vector<int>& data)
{
    if (data.empty()) return false;

    if (!initialized)
    {
        gap = data.size() / 2;
        i = gap;
        j = i;
        temp = 0;
        initialized = true;
    }

    if (gap == 0)
        return false; // sorting done

    if (i < (int)data.size())
    {
        if (j == i)
            temp = data[i];

        if (j >= gap && data[j - gap] > temp)
        {
            data[j] = data[j - gap];
            j -= gap;
        }
        else
        {
            data[j] = temp;
            i++;
            j = i;
        }
        return true;
    }
    else
    {
        gap /= 2;
        i = gap;
        j = i;
        return true;
    }
}


void ShellSort::reset(std::vector<int>& data)
{
    gap = data.size() / 2;
    i = gap;
    j = i;
    temp = 0;
    initialized = false;
}

void RadixSort::insertBuckets(Node*& head, int val)
{
    Node* newNode = new Node(val);
    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int RadixSort::getMax(const std::vector<int>& data)
{
    int max = data[0];
    for(int x : data)
    {
        if(x > max)
        {
            max = x;
        }
    }
    return max;
}

void RadixSort::clearBuckets()
{
    Node* temp;
    for(int i = 0; i < 10; i++)
    {
        while(buckets[i] != nullptr)
        {
            temp = buckets[i];
            buckets[i] = buckets[i]->next;
            delete temp;
        }
    }
}

bool RadixSort::step(std::vector<int>& data)
{
    if(done) return false;

    if(exp == 1)
    {
        maxVal = getMax(data);
    }

    if(maxVal / exp > 0 && swapping == false) // filling the buckets
    {
        for(int i = 0; i < data.size(); i++)
        {
            int digit = (data[i] / exp) % 10;
            insertBuckets(buckets[digit], data[i]);
        }

        swapping = true;
        index = 0;
        bucketIndex = 0;

        return true;
    }

    if(swapping && index < data.size()) // emptying buckets, one by one
    {
        if(bucketIndex < 10)
        {
            if(buckets[bucketIndex] != nullptr)
            {
                Node* node = buckets[bucketIndex];   
                data[index++] = node->data;
                buckets[bucketIndex] = node->next;
                delete node;

            }
            else
            {
                bucketIndex++;
            }

            return true;
        }    
    } 
    else
    {
        swapping = false;
        index = 0;
        bucketIndex = 0;

        exp *= 10;
        clearBuckets();
    }

    if(maxVal / exp == 0)
    {
        done = true;
        return false;
    }

    return true;
}

void RadixSort::reset(std::vector<int>& data)
{
    exp = 1;
    done = false;
    swapping = false;
    index= 0;
    bucketIndex = 0;
    clearBuckets();
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
        if (data[i] < data[j])
            temp.push_back(data[i++]);
        else
            temp.push_back(data[j++]);
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
        data[left + k] = temp[k];
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
        callStack.push({0, (int)data.size() / 2, (int)data.size() - 1, 0});
    }
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
