#ifndef OPTIMIZED_BUBBLE_SORT_H
#define OPTIMIZED_BUBBLE_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void optimized_bubble_sort(vector<T>& arr) {
    bool swapped;
    
    for (size_t i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        
        for (size_t j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
}

#endif