#include <gtest/gtest.h>
#include <vector>
using namespace std;

#include "../include/insertion_sort.h"
#include "../include/selection_sort.h"
#include "../include/exchange_sort.h"
#include "../include/bubble_sort.h"
#include "../include/optimized_bubble_sort.h"

// Вспомогательная функция
bool is_sorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// ==================== ТЕСТЫ ДЛЯ ВСТАВОК ====================
TEST(InsertionSortTest, EmptyArray) {
    vector<int> arr;
    insertion_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(InsertionSortTest, SingleElement) {
    vector<int> arr = {5};
    insertion_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(InsertionSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    insertion_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(InsertionSortTest, ReverseOrder) {
    vector<int> arr = {5, 4, 3, 2, 1};
    insertion_sort(arr);
    EXPECT_TRUE(is_sorted(arr));
}

TEST(InsertionSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    insertion_sort(arr);
    EXPECT_EQ(arr, expected);
}

// ==================== ТЕСТЫ ДЛЯ ВЫБОРА ====================
TEST(SelectionSortTest, EmptyArray) {
    vector<int> arr;
    selection_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(SelectionSortTest, SingleElement) {
    vector<int> arr = {5};
    selection_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(SelectionSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    selection_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(SelectionSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    selection_sort(arr);
    EXPECT_EQ(arr, expected);
}

// ==================== ТЕСТЫ ДЛЯ ОБМЕНА ====================
TEST(ExchangeSortTest, EmptyArray) {
    vector<int> arr;
    exchange_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(ExchangeSortTest, SingleElement) {
    vector<int> arr = {5};
    exchange_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(ExchangeSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    exchange_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(ExchangeSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    exchange_sort(arr);
    EXPECT_EQ(arr, expected);
}

// ==================== ТЕСТЫ ДЛЯ ПУЗЫРЬКА ====================
TEST(BubbleSortTest, EmptyArray) {
    vector<int> arr;
    bubble_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(BubbleSortTest, SingleElement) {
    vector<int> arr = {5};
    bubble_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(BubbleSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    bubble_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(BubbleSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    bubble_sort(arr);
    EXPECT_EQ(arr, expected);
}

// ==================== ТЕСТЫ ДЛЯ УЛУЧШЕННОГО ПУЗЫРЬКА ====================
TEST(OptimizedBubbleSortTest, EmptyArray) {
    vector<int> arr;
    optimized_bubble_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(OptimizedBubbleSortTest, SingleElement) {
    vector<int> arr = {5};
    optimized_bubble_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(OptimizedBubbleSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    optimized_bubble_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(OptimizedBubbleSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    optimized_bubble_sort(arr);
    EXPECT_EQ(arr, expected);
}

// ==================== СРАВНИТЕЛЬНЫЕ ТЕСТЫ ====================
TEST(AllSortsTest, CompareResults) {
    vector<int> test_array = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    
    vector<int> arr1 = test_array;
    vector<int> arr2 = test_array;
    vector<int> arr3 = test_array;
    vector<int> arr4 = test_array;
    vector<int> arr5 = test_array;
    
    insertion_sort(arr1);
    selection_sort(arr2);
    exchange_sort(arr3);
    bubble_sort(arr4);
    optimized_bubble_sort(arr5);
    
    EXPECT_EQ(arr1, expected);
    EXPECT_EQ(arr2, expected);
    EXPECT_EQ(arr3, expected);
    EXPECT_EQ(arr4, expected);
    EXPECT_EQ(arr5, expected);
    
    EXPECT_EQ(arr1, arr2);
    EXPECT_EQ(arr2, arr3);
    EXPECT_EQ(arr3, arr4);
    EXPECT_EQ(arr4, arr5);
}