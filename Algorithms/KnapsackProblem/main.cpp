#include "Knapsack.hpp"
#include <algorithm>
void solveKnapsackProblem(knapsack &bag ,std::vector<item> items){
    std::sort(items.begin(),items.end(),[](item a, item b){
        return a.ratio>b.ratio;
    });
    int i=0;
    while (bag.currentCapacity<bag.maxCapacity)
    {
      bag.addItem(items[i]);
        i++;
    }
    bag.printItems();
}
int main(){
    item item1("item1",2,40);
    item item2("item2",3,50);
    item item3("item3",5,70);
    item item4("item4",7,30);
    item item5("item5",1,60);
    item item6("item6",4,80);
    item item7("item7",1,10);
    item item8("item8",6,20);
    item item9("item9",3,90);
    item item10("item10",2,100);

    std::vector<item> items;
    items.push_back(item1);
    items.push_back(item2);
    items.push_back(item3);
    items.push_back(item4);
    items.push_back(item5);
    items.push_back(item6);
    items.push_back(item7);
    items.push_back(item8);
    items.push_back(item9);
    items.push_back(item10);

   

    knapsack bag(10);

    solveKnapsackProblem(bag,items);
     

    
    return 0;
}