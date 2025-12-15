#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "include/binary_insertion_sort.h"
#include "include/shaker_sort.h"

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
    
    cout << left << setw(35) << name 
         << " | Результат: ";
    print_array(arr);
    cout << endl;
}

int main() {
    vector<int> test_array = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> sorted_array = {0, 2, 4, 6, 8, 12, 14, 15};
    
    cout << "Тестовый массив: ";
    print_array(test_array);
    cout << "\n" << string(70, '=') << "\n";
    
    test_sort("Бинарная сортировка вставками", binary_insertion_sort<int>, test_array);
    test_sort("Шейкерная сортировка", shaker_sort<int>, test_array);
    
    cout << "\nОжидаемый результат: ";
    print_array(sorted_array);
    cout << endl;
    
    return 0;
}


'''
cd ~/Desktop/seminar2_simple
g++ -std=c++17 -Iinclude main.cpp -o seminar2_demo
./seminar2_demo

cd ~/Desktop/seminar2_simple
g++ -std=c++17 -Iinclude tests/test_seminar2.cpp -lgtest -lgtest_main -pthread -o seminar2_tests
./seminar2_tests
'''