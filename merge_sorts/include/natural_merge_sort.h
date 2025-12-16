#ifndef NATURAL_MERGE_SORT_H
#define NATURAL_MERGE_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

// Естественная сортировка слиянием
template <typename T>
void natural_merge_sort(vector<T>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    
    vector<T> temp(n);
    
    while (true) {
        // Находим все возрастающие серии
        vector<pair<int, int>> runs;
        int start = 0;
        
        while (start < n) {
            int end = start;
            while (end + 1 < n && arr[end] <= arr[end + 1]) {
                end++;
            }
            runs.push_back({start, end});
            start = end + 1;
        }
        
        // Если осталась только одна серия - массив отсортирован
        if (runs.size() <= 1) break;
        
        // Сливаем пары серий
        vector<pair<int, int>> new_runs;
        
        for (size_t i = 0; i < runs.size(); i += 2) {
            if (i + 1 >= runs.size()) {
                // Нечетное количество серий - последняя остается без изменений
                new_runs.push_back(runs[i]);
                break;
            }
            
            int left_start = runs[i].first;
            int left_end = runs[i].second;
            int right_start = runs[i + 1].first;
            int right_end = runs[i + 1].second;
            
            int left = left_start;
            int right = right_start;
            int index = left_start;
            
            // Слияние двух серий
            while (left <= left_end && right <= right_end) {
                if (arr[left] <= arr[right]) {
                    temp[index] = arr[left];
                    left++;
                } else {
                    temp[index] = arr[right];
                    right++;
                }
                index++;
            }
            
            // Дописываем остаток левой серии
            while (left <= left_end) {
                temp[index] = arr[left];
                left++;
                index++;
            }
            
            // Дописываем остаток правой серии
            while (right <= right_end) {
                temp[index] = arr[right];
                right++;
                index++;
            }
            
            // Копируем обратно в исходный массив
            for (int j = left_start; j <= right_end; j++) {
                arr[j] = temp[j];
            }
            
            new_runs.push_back({left_start, right_end});
        }
        
        runs = new_runs;
    }
}

#endif
