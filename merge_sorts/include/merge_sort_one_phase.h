#ifndef MERGE_SORT_ONE_PHASE_H
#define MERGE_SORT_ONE_PHASE_H

#include <vector>
#include <algorithm>
using namespace std;

// Однофазная сортировка слиянием (без рекурсии, итеративная)
template <typename T>
void merge_sort_one_phase(vector<T>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    
    vector<T> temp(n);
    
    for (int curr_size = 1; curr_size < n; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < n; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            
            int left = left_start;
            int right = mid + 1;
            int index = left_start;
            
            while (left <= mid && right <= right_end) {
                if (arr[left] <= arr[right]) {
                    temp[index] = arr[left];
                    left++;
                } else {
                    temp[index] = arr[right];
                    right++;
                }
                index++;
            }
            
            while (left <= mid) {
                temp[index] = arr[left];
                left++;
                index++;
            }
            
            while (right <= right_end) {
                temp[index] = arr[right];
                right++;
                index++;
            }
            
            for (int i = left_start; i <= right_end; i++) {
                arr[i] = temp[i];
            }
        }
    }
}

#endif
