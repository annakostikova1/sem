#ifndef EXCHANGE_SORT_H
#define EXCHANGE_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void exchange_sort(vector<T>& arr) {
    for (size_t i = 0; i + 1 < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

#endif