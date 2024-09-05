#include <iostream>
#include <vector>

template<typename T>
int sum(std::vector<T> v) {
    if(v.size() == 0) {
        return 0;
    }
    
    int first = v[0];
    v.erase(v.begin());
    
    return first + sum(v);
    

}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << sum(v) << std::endl;
    return 0;
}