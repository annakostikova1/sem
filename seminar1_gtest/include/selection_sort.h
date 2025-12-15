#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void selection_sort(vector<T>& arr) {  // ← vector<T>, а не vector<int>
    if (arr.empty() || arr.size() == 1) return;
    
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

#endif