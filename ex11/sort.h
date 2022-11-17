#ifndef SORT_H
#define SORT_H
#include <iostream>

namespace PL4
{
    // Insertion sort
    template <class BiDirIt>
    void sort(BiDirIt begin, BiDirIt end)
    {
        for (BiDirIt i = begin; i != end; i++)
        {
            BiDirIt j = i;
            while (j != begin && *j < *std::prev(j))
            {
                std::swap(*j, *std::prev(j));
                j--;
            }
        }
    }
}

#endif