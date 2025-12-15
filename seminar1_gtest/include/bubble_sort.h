#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void bubble_sort(vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif