#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

#include "../include/merge_sort_simple.h"
#include "../include/merge_sort_one_phase.h"
#include "../include/natural_merge_sort.h"

// ===== ПРОСТАЯ СОРТИРОВКА СЛИЯНИЕМ =====
TEST(MergeSortSimpleTest, EmptyArray) {
    vector<int> arr;
    merge_sort_simple(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortSimpleTest, SingleElement) {
    vector<int> arr = {5};
    merge_sort_simple(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(MergeSortSimpleTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    merge_sort_simple(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortSimpleTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    merge_sort_simple(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortSimpleTest, WithDuplicates) {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    merge_sort_simple(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

TEST(MergeSortSimpleTest, ReverseOrder) {
    vector<int> arr = {5, 4, 3, 2, 1};
    merge_sort_simple(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

// ===== ОДНОФАЗНАЯ СОРТИРОВКА СЛИЯНИЕМ =====
TEST(MergeSortOnePhaseTest, EmptyArray) {
    vector<int> arr;
    merge_sort_one_phase(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortOnePhaseTest, SingleElement) {
    vector<int> arr = {5};
    merge_sort_one_phase(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(MergeSortOnePhaseTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    merge_sort_one_phase(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortOnePhaseTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    merge_sort_one_phase(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortOnePhaseTest, WithDuplicates) {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    merge_sort_one_phase(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

// ===== ЕСТЕСТВЕННАЯ СОРТИРОВКА СЛИЯНИЕМ =====
TEST(NaturalMergeSortTest, EmptyArray) {
    vector<int> arr;
    natural_merge_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(NaturalMergeSortTest, SingleElement) {
    vector<int> arr = {5};
    natural_merge_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(NaturalMergeSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    natural_merge_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(NaturalMergeSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    natural_merge_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(NaturalMergeSortTest, AlreadyHasNaturalRuns) {
    vector<int> arr = {1, 3, 5, 2, 4, 6, 0, 7};
    natural_merge_sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

TEST(NaturalMergeSortTest, ReverseOrder) {
    vector<int> arr = {5, 4, 3, 2, 1};
    natural_merge_sort(arr);
    EXPECT_TRUE(is_sorted(arr.begin(), arr.end()));
}

// ===== СРАВНИТЕЛЬНЫЕ ТЕСТЫ =====
TEST(CompareMergeSortsTest, SameResults) {
    vector<int> test_array = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    
    vector<int> arr1 = test_array;
    vector<int> arr2 = test_array;
    vector<int> arr3 = test_array;
    
    merge_sort_simple(arr1);
    merge_sort_one_phase(arr2);
    natural_merge_sort(arr3);
    
    EXPECT_EQ(arr1, expected);
    EXPECT_EQ(arr2, expected);
    EXPECT_EQ(arr3, expected);
    
    EXPECT_EQ(arr1, arr2);
    EXPECT_EQ(arr2, arr3);
    EXPECT_EQ(arr1, arr3);
}

TEST(CompareMergeSortsTest, LargeArray) {
    vector<int> arr1(1000);
    vector<int> arr2(1000);
    vector<int> arr3(1000);
    
    for (int i = 0; i < 1000; i++) {
        arr1[i] = arr2[i] = arr3[i] = rand() % 10000;
    }
    
    merge_sort_simple(arr1);
    merge_sort_one_phase(arr2);
    natural_merge_sort(arr3);
    
    EXPECT_TRUE(is_sorted(arr1.begin(), arr1.end()));
    EXPECT_TRUE(is_sorted(arr2.begin(), arr2.end()));
    EXPECT_TRUE(is_sorted(arr3.begin(), arr3.end()));
    EXPECT_EQ(arr1, arr2);
    EXPECT_EQ(arr2, arr3);
}

TEST(CompareMergeSortsTest, DifferentTypes) {
    vector<double> arr1 = {3.14, 2.71, 1.41, 1.73};
    vector<double> arr2 = arr1;
    vector<double> arr3 = arr1;
    
    merge_sort_simple(arr1);
    merge_sort_one_phase(arr2);
    natural_merge_sort(arr3);
    
    EXPECT_TRUE(is_sorted(arr1.begin(), arr1.end()));
    EXPECT_TRUE(is_sorted(arr2.begin(), arr2.end()));
    EXPECT_TRUE(is_sorted(arr3.begin(), arr3.end()));
}
