#include "CountingSort.hpp"
#include <ostream>
#include <vector>




std::ostream& operator<<(std::ostream& os, const std::vector<int>& arr){
    for(auto element:arr){
        os<<element<<" ";
    }
    return os;
}

int main(){
    std::vector<int> arr = {1,4,1,2,7,5,2};
    myAlgorithms::CountingSort(arr);
    std::cout<<arr<<std::endl;
    return 0;
}