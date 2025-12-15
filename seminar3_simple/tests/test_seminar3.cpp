#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

#include "../include/shell_sort.h"
#include "../include/quick_sort.h"

// ===== СОРТИРОВКА ШЕЛЛА =====
TEST(ShellSortTest, EmptyArray) {
    vector<int> arr;
    shell_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(ShellSortTest, SingleElement) {
    vector<int> arr = {5};
    shell_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(ShellSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    shell_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(ShellSortTest, ReverseOrder) {
    vector<int> arr = {5, 4, 3, 2, 1};
    shell_sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

TEST(ShellSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    shell_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(ShellSortTest, WithDuplicates) {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    shell_sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

TEST(ShellSortTest, DoubleType) {
    vector<double> arr = {3.14, 2.71, 1.41, 1.73};
    shell_sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

// ===== БЫСТРАЯ СОРТИРОВКА =====
TEST(QuickSortTest, EmptyArray) {
    vector<int> arr;
    quick_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(QuickSortTest, SingleElement) {
    vector<int> arr = {5};
    quick_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(QuickSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    quick_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(QuickSortTest, ReverseOrder) {
    vector<int> arr = {5, 4, 3, 2, 1};
    quick_sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

TEST(QuickSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    quick_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(QuickSortTest, WithDuplicates) {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    quick_sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

TEST(QuickSortTest, FloatType) {
    vector<float> arr = {3.14f, 2.71f, 1.41f, 1.73f};
    quick_sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

TEST(QuickSortTest, StringType) {
    vector<string> arr = {"банан", "яблоко", "апельсин"};
    quick_sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

// ===== СРАВНИТЕЛЬНЫЕ ТЕСТЫ =====
TEST(CompareSortsTest, SameResults) {
    vector<int> test_array = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    
    vector<int> arr1 = test_array;
    vector<int> arr2 = test_array;
    
    shell_sort(arr1);
    quick_sort(arr2);
    
    EXPECT_EQ(arr1, expected);
    EXPECT_EQ(arr2, expected);
    EXPECT_EQ(arr1, arr2);
}

TEST(CompareSortsTest, LargeArray) {
    vector<int> arr1(100);
    vector<int> arr2(100);
    
    for (int i = 0; i < 100; i++) {
        arr1[i] = arr2[i] = rand() % 1000;
    }
    
    shell_sort(arr1);
    quick_sort(arr2);
    
    EXPECT_TRUE(is_sorted(arr1.begin(), arr1.end()));
    EXPECT_TRUE(is_sorted(arr2.begin(), arr2.end()));
    EXPECT_EQ(arr1, arr2);
}
