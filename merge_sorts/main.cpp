#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "include/merge_sort_simple.h"
#include "include/merge_sort_one_phase.h"
#include "include/natural_merge_sort.h"

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
    sort_func(arr);
    
    cout << left << setw(45) << name 
         << " | Результат: ";
    print_array(arr);
    cout << endl;
}

int main() {
    vector<int> test_array = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> sorted_array = {0, 2, 4, 6, 8, 12, 14, 15};
    
    cout << "Тестовый массив: ";
    print_array(test_array);
    cout << "\n" << string(50, '=') << "\n";
    
    test_sort("Сортировка простым слиянием (двухфазная)", merge_sort_simple<int>, test_array);
    test_sort("Однофазная сортировка слиянием", merge_sort_one_phase<int>, test_array);
    test_sort("Естественная сортировка слиянием", natural_merge_sort<int>, test_array);
    
    cout << "\nОжидаемый результат: ";
    print_array(sorted_array);
    cout << endl;
    
    return 0;
}

'''
g++ -std=c++17 -Iinclude main.cpp -o merge_sorts_demo
./merge_sorts_demo

g++ -std=c++17 -Iinclude tests/test_merge_sorts.cpp -lgtest -lgtest_main -pthread -o merge_sorts_tests
./merge_sorts_tests
'''
