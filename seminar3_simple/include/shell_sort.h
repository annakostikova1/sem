#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void shell_sort(vector<T>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    
    // Последовательность Кнута
    int gap = 1;
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }
    
    while (gap >= 1) {
        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 3;
    }
}

#endif
