#include <iostream>
#include <vector>

template <typename T>
void SelectionSort(std::vector<T> &arr,bool ascending = true){
    int n=arr.size();
    int minMax=0;
    for(int i=0; i<n; i++){
        minMax=i;
        for(int j=i+1; j<n; j++){
            if(ascending){
                
                if(arr[j]<arr[minMax]){
                    minMax=j;
                }
            }
            else{
                if(arr[j]>arr[minMax]){
                    minMax=j;
                }

            }
            std::swap(arr[i],arr[minMax]);

        }
    }
}


