#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;

#include "include/insertion_sort.h"
#include "include/selection_sort.h"
#include "include/exchange_sort.h"
#include "include/bubble_sort.h"
#include "include/optimized_bubble_sort.h"

void print_array(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

template <typename Func>
void test_sort(const string& name, Func sort_func, vector<int> arr) {
    auto start = chrono::high_resolution_clock::now();
    sort_func(arr);
    auto end = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << left << setw(30) << name 
         << " | Время: " << setw(8) << duration.count() << " мкс | Результат: ";
    print_array(arr);
    cout << endl;
}

int main() {
    vector<int> test_array = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> sorted_array = {0, 2, 4, 6, 8, 12, 14, 15};
    
    cout << "Тестовый массив: ";
    print_array(test_array);
    cout << "\n" << string(70, '=') << "\n";
    
    test_sort("Сортировка вставками", insertion_sort<int>, test_array);
    test_sort("Сортировка выбором", selection_sort<int>, test_array);
    test_sort("Сортировка обменом", exchange_sort<int>, test_array);
    test_sort("Сортировка пузырьком", bubble_sort<int>, test_array);
    test_sort("Улучшенный пузырёк", optimized_bubble_sort<int>, test_array);
    
    cout << "\nОжидаемый результат: ";
    print_array(sorted_array);
    cout << endl;
    
    return 0;
}