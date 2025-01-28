#pragma once
#include <iostream>
#include <string>
#include <vector>


class item {
    public:
    std::string name;
    double weight;
    double value;
    double ratio;

    item();
    item(std::string name,double weight,double value);

};

class knapsack{
    public:
    double maxCapacity;
    double currentCapacity;
    double totalValue;
    std::vector<item> items;

    knapsack(double maxCapacity);

    void addItem(item newItem);
    void printItems();
};