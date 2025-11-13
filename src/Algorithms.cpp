#include "Algorithms.hpp"
#include <algorithm>
#include <vector>

// -------------------- Insertion Sort --------------------
bool InsertionSort::step(std::vector<int>& data)
{
    static bool done = false;
    static int i = 1, j = i - 1;
    static int key;

    if (done || data.empty()) return false;

    if (i < (int)data.size())
    {
        if (j == i - 1)
            key = data[i];

        if (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        else
        {
            data[j + 1] = key;
            i++;
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
}
