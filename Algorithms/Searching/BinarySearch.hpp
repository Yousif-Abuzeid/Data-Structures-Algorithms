#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

// Function template for performing binary search on a vector of any type
// T: Type of the elements in the vector (e.g., int, float, std::string)
// Parameters:
//   arr - Reference to a vector of type T
//   Target - The element to search for in the vector
// Returns:
//   The index of Target in arr if found, otherwise -1
template <typename T>
int binarySearch(std::vector<T> &arr, T Target) {
    int low = 0;                     // Initialize the lower bound of the search range
    int high = arr.size() - 1;        // Initialize the upper bound of the search range
    int mid = (low + high) / 2;       // Calculate the initial mid-point of the range

    // Loop continues as long as the search range is valid
    while (low <= high) {
        mid = (high + low) / 2;       // Recalculate mid-point at each iteration

        // Check if the mid-point element is the target
        if (arr[mid] == Target) {
            return mid;               // Target found, return the index
        }
        
        // If target is smaller than mid-point element, adjust the search range
        if (arr[mid] > Target) {
            high = mid - 1;           // Move the upper bound to the left of mid
        } else {
            low = mid + 1;            // Move the lower bound to the right of mid
        }
    }

    // Target not found in the array
    return -1;
}

// Overload of the output stream operator for printing vectors
// This template allows printing vectors of any type using std::cout
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& arr) {
    for (const auto &i : arr) {
        os << i << " ";               // Output each element followed by a space
    }
    return os;                        // Return the output stream
}


