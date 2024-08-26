#include "hash.hpp"

int main(){
    namespace myDs = myDataStructures;
    myDs::HashTable<int,int> hashTable;
    myDs::HashTable<std::string,int> hashTable2(7);
    hashTable.insert(55,10);
    hashTable.insert(100,20);
    hashTable.insert(27,30);
    hashTable.insert(99,40);
    hashTable.insert(5,50);
    hashTable.insert(6,60);
    hashTable.insert(7,70);
    hashTable.insert(8,80);
    hashTable.insert(9,90);
    hashTable.insert(10,100);
    hashTable.insert(11,110);
    std::cout<<hashTable<<std::endl;
    
    hashTable2.insert("hello",10);
    hashTable2.insert("world",20);
    hashTable2.insert("this",30);
    hashTable2.insert("is",40);
    hashTable2.insert("a",50);
    hashTable2.insert("hash",60);
    hashTable2.insert("table",70);
    hashTable2.insert("using",80);
    hashTable2.insert("universal",90);
    hashTable2.insert("hash",100);
    hashTable2.insert("function",110);

    
    hashTable[55] = 1000;
    hashTable[100] = 2000;
    std::cout<<hashTable<<std::endl;

    std::cout<<hashTable2<<std::endl;
    return 0;
}