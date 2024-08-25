#include <iostream>
#include <vector>


template<typename T>
int count(std::vector<T> v) {
    if(v.size() == 0) {
        return 0;
    }
    
    v.pop_back();
    
    return 1 + count(v);
}


int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << count(v) << std::endl;
    return 0;
}