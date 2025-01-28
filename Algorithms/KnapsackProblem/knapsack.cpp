#include "Knapsack.hpp"
#include <iostream>
#include <vector>

item::item(){

}
item::item(std::string name,double weight,double value){
    this->name=name;
    this->weight = weight;
    this->value = value;
    ratio = value/weight; 
}

knapsack::knapsack(double maxCapacity){
    this->maxCapacity= maxCapacity;
}
void knapsack::addItem(item newItem){
    if(newItem.weight>maxCapacity-currentCapacity){
        float diff = maxCapacity-currentCapacity;
        newItem.weight = diff;
        newItem.value = diff*newItem.ratio;
    }
items.push_back(newItem);
currentCapacity+=newItem.weight;
totalValue+=newItem.value;
}

void knapsack::printItems(){
    std::cout<<"-----------------------------------"<<std::endl;
    std::cout<<"Knapsack: "<<std::endl;
    std::cout<<"Max Capacity: "<<maxCapacity<<"KG"<<std::endl;
    std::cout<<"Current Capacity: "<<currentCapacity<<"KG"<<std::endl;
    std::cout<<"Total Value: "<<totalValue<<"$"<<std::endl;
    std::cout<<"Items: "<<std::endl;
    for(int i=0;i<items.size();i++){
        std::cout<<items[i].name<<" "<<items[i].weight<<"KG "<<items[i].value<<"$"<<std::endl;
    }
}
