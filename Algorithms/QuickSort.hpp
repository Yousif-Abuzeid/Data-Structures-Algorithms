
#include <iostream>
#include <ostream>
#include <vector>



template<typename T>
std::vector<T> quickSort(std::vector<T> &V) {
    int size = V.size();
    if (size < 2) {
        return V;
    }

    // Choose the middle element as pivot
    T pivot = V[size / 2];
    std::vector<T> Left, Right, Equal;

    // Partition the elements into Left, Right, and Equal
    for (const auto &it : V) {
        if (it < pivot) {
            Left.push_back(it);
        } else if (it > pivot) {
            Right.push_back(it);
        } else {
            Equal.push_back(it);  // Handles elements equal to the pivot
        }
    }

    // Recursively sort the Left and Right subarrays
    Left = quickSort(Left);
    Right = quickSort(Right);

    // Merge the Left, Equal, and Right into the original vector
    V.clear();
    V.insert(V.end(), Left.begin(), Left.end());
    V.insert(V.end(), Equal.begin(), Equal.end());
    V.insert(V.end(), Right.begin(), Right.end());

    return V;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[";
    for(int i = 0; i < v.size(); i++) {
        os << v[i];
        if(i != v.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}


