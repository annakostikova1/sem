#ifndef SHAKER_SORT_H
#define SHAKER_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void shaker_sort(vector<T>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    
    while (swapped) {
        swapped = false;
        
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) break;
        
        swapped = false;
        end--;
        
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        
        start++;
    }
}

#endif
