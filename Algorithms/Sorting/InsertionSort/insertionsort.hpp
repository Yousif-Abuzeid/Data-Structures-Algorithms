#pragma once


#include <functional>

/*
  *   @Yousif-Abuzeid
  * @brief: Insertion Sort Algorithm
  *  @param start: Iterator pointing to the start of the range
  *  @param end: Iterator pointing to the end of the range
  *  @param comp: Comparator function to determine the sorting order (defaults to std::less)
  *  @return: void
  *  @timeComplexity: O(n^2)
*/

namespace myDataStructures {
    template <typename RandomAccessIterator, typename Comparator = std::less<>>
    void InsertionSort(RandomAccessIterator start,RandomAccessIterator end,Comparator comp = Comparator()){
        for(auto i = start+1;i<end;i++){
            auto key = *i;
            auto j = i-1;
            while(j>=start && comp(key,*j)){
                *(j+1) = *j;
                j--;
            }
            *(j+1) = key;
        }
    }
    
}