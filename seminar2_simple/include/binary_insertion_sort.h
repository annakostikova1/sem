#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
int find_position(const vector<T>& arr, const T& item, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

template <typename T>
void binary_insertion_sort(vector<T>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        
        int pos = find_position(arr, key, 0, j);
        
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

#endif
