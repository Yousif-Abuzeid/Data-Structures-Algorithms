# Counting Sort

Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array. The algorithm is efficient when the range of elements is small compared to the number of elements to be sorted.

## Algorithm

1. Find the maximum and minimum element in the array.
2. Create a count array of size `(max -min)+ 1` and initialize all elements to 0.
3. Traverse the array and increment the count of each element in the count array.
4. Modify the count array such that each element at each index stores the sum of the previous counts.
5. Create a temporary array of the same size as the input array.
6. Traverse the input array from right to left and place each element at the correct position in the temporary array.
7. Decrement the count of the element in the count array.
8. Copy the elements from the temporary array to the input array.

## Complexity

- **Time Complexity**: `O(n + k)`, where `n` is the number of elements in the array and `k` is the range of the input.
- **Space Complexity**: `O(n + k)`
- **Stability**: Stable

## Note

- Counting sort is not a comparison-based sorting algorithm.
- Counting sort is efficient when the range of elements is small compared to the number of elements to be sorted.
- Counting sort is not suitable for sorting floating point numbers.
- Counting sort is not suitable for sorting strings.
- Counting sort is not suitable for sorting objects.


- 