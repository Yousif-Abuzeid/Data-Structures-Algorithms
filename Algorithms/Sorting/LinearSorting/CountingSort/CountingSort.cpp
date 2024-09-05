#include <algorithm>
#include <vector>

namespace myAlgorithms {
    void CountingSort(std::vector<int> &arr) {
        if (arr.empty()) return;  // Handle edge case where input is empty

        // Find the minimum and maximum elements to handle negative numbers
        int min = *std::min_element(arr.begin(), arr.end());
        int max = *std::max_element(arr.begin(), arr.end());

        // Create counting array of size (max - min + 1)
        std::vector<int> counting(max - min + 1, 0);

        // Count occurrences of each element
        for (auto element : arr) {
            counting[element - min]++;  // Shift by min to handle negative numbers
        }

        // Overwrite the original array with the sorted values
        int index = 0;
        for (int i = 0; i < counting.size(); i++) {
            while (counting[i] > 0) {
                arr[index++] = i + min;  // Shift back by min
                counting[i]--;
            }
        }
    }
}
