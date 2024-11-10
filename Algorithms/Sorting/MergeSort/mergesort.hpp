#pragma once

#include <functional>
#include <vector>
#include <iterator>

/*
  *   @Yousif-Abuzeid
 * @brief: Merge Sort Algorithm
 * @param start: Iterator pointing to the start of the range
 * @param end: Iterator pointing to the end of the range
 * @param comp: Comparator function to determine the sorting order (defaults to std::less)
 * @return: void
 * @timeComplexity: O(nlogn)
 */

namespace myDataStructures {
    
    template <typename RandomAccessIterator, typename Comparator>
    void merge(RandomAccessIterator start, RandomAccessIterator mid, RandomAccessIterator end, Comparator comp) {
        using T = typename std::iterator_traits<RandomAccessIterator>::value_type;

        // Copy the left and right halves
        std::vector<T> left(start, mid);
        std::vector<T> right(mid, end);

        auto left_iter = left.begin();
        auto right_iter = right.begin();
        auto output = start;

        // Merge the two sorted halves
        while (left_iter != left.end() && right_iter != right.end()) {
            if (comp(*left_iter, *right_iter)) {
                *output++ = *left_iter++;
            } else {
                *output++ = *right_iter++;
            }
        }

        // Copy any remaining elements in the left half
        while (left_iter != left.end()) {
            *output++ = *left_iter++;
        }

        // Copy any remaining elements in the right half
        while (right_iter != right.end()) {
            *output++ = *right_iter++;
        }
    }

    template <typename RandomAccessIterator, typename Comparator = std::less<>>
    void mergeSort(RandomAccessIterator start, RandomAccessIterator end, Comparator comp = Comparator()) {
        // Check base case
        if (end - start <= 1) { // Only one element or empty range
            return;
        }

        // Calculate midpoint
        RandomAccessIterator mid = start + (end - start) / 2;

        // Call mergeSort recursively on both halves
        mergeSort(start, mid, comp);
        mergeSort(mid, end, comp);

        // Merge the two halves
        merge(start, mid, end, comp);
    }
}
