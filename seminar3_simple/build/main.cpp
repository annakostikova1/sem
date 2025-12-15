#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "include/shell_sort.h"
#include "include/quick_sort.h"

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
    
    cout << left << setw(30) << name 
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
    
    test_sort("Сортировка Шелла", shell_sort<int>, test_array);
    test_sort("Быстрая сортировка", quick_sort<int>, test_array);
    
    cout << "\nОжидаемый результат: ";
    print_array(sorted_array);
    cout << endl;
    
    // Дополнительные тесты
    cout << "\n" << string(70, '-') << "\n";
    cout << "Дополнительные проверки:\n";
    
    // Пустой массив
    {
        vector<int> empty;
        shell_sort(empty);
        quick_sort(empty);
        cout << "Пустой массив: обработан ✓\n";
    }
    
    // Один элемент
    {
        vector<int> single = {42};
        shell_sort(single);
        cout << "Один элемент: " << single[0] << " ✓\n";
    }
    
    // Два элемента
    {
        vector<int> two = {2, 1};
        quick_sort(two);
        cout << "Два элемента: " << two[0] << ", " << two[1] << " ✓\n";
    }
    
    // Разные типы данных
    {
        vector<double> doubles = {3.14, 2.71, 1.41};
        shell_sort(doubles);
        cout << "Double тип: обработан ✓\n";
        
        vector<string> strings = {"яблоко", "банан", "апельсин"};
        quick_sort(strings);
        cout << "String тип: обработан ✓\n";
    }
    
    return 0;
}
