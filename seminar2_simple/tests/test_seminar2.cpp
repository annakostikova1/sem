#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

#include "../include/binary_insertion_sort.h"
#include "../include/shaker_sort.h"

// ===== БИНАРНАЯ СОРТИРОВКА ВСТАВКАМИ =====
TEST(BinaryInsertionSortTest, EmptyArray) {
    vector<int> arr;
    binary_insertion_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(BinaryInsertionSortTest, SingleElement) {
    vector<int> arr = {5};
    binary_insertion_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(BinaryInsertionSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    binary_insertion_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(BinaryInsertionSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    binary_insertion_sort(arr);
    EXPECT_EQ(arr, expected);
}

// ===== ШЕЙКЕРНАЯ СОРТИРОВКА =====
TEST(ShakerSortTest, EmptyArray) {
    vector<int> arr;
    shaker_sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(ShakerSortTest, SingleElement) {
    vector<int> arr = {5};
    shaker_sort(arr);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(ShakerSortTest, AlreadySorted) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = arr;
    shaker_sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(ShakerSortTest, MainTestArray) {
    vector<int> arr = {4, 0, 15, 6, 12, 2, 14, 8};
    vector<int> expected = {0, 2, 4, 6, 8, 12, 14, 15};
    shaker_sort(arr);
    EXPECT_EQ(arr, expected);
}