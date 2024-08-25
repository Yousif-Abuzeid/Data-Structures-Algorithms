//divison hash function
// h(k) = k mod m

//universal hash function

//h(p,m) ={h_ab(k) ab belong to [0,p-1]}
//h_ab(k) = ((ak+b) mod p) mod m
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../LinkedList/LinkedList.hpp"


namespace myDataStructures {
    template <typename K>
    int universalHash(const K& key, int m, int p,int a,int b) {
       
        int hashValue = 0;
        hashValue = ((a * key + b) % p) % m;
        return hashValue % m;
    }
    int universalHash(const std::string& key, int m, int p,int a,int b) {
        int hashValue = 0;
        for (char c : key) {
            hashValue = (hashValue * a + c) % p;
        }
        return hashValue % m;
    }
    template<typename K ,typename Val>
    class HashTable{
        private:
        std::vector<myDataStructures::LinkedList<std::pair<K,Val>>> Table;
        int size;
        int capacity;
        int a;
        int b;
        const int p = 100;
        public:
        HashTable():size(0),capacity(10){
        a = rand() % (p - 1) + 1;
        b = rand() % p;
            Table.resize(capacity);
        }
        HashTable(int capacity):size(0),capacity(capacity){
            Table.resize(capacity);
            a = rand() % (p - 1) + 1;
            b = rand() % p;
        }
        void insert(const K& key,const Val& value){
            int index = universalHash(key,capacity,p,a,b);
            Table[index].insert(std::make_pair(key,value));
            size++;
        }
        void remove(const K& key){
            int index = universalHash(key,capacity,p,a,b);
            auto& list = Table[index];
            for(int i = 0;i<list.size();i++){
                if(list[i].first == key){
                    list.remove(i);
                    size--;
                    return;
                }
            }
        }
        Val operator[](const K& key){
            int index = universalHash(key,capacity,p,a,b);
            std::cout<<index<<std::endl;
            auto& list = Table[index];
            for(int i = 0;i<list.size();i++){
                if(list[i].first == key){
                    return list[i].second;
                }
            }
            throw std::out_of_range("Key not found");
        }
        bool contains(const K& key){
            int index = universalHash(key,capacity,100);
            auto& list = Table[index];
            for(int i = 0;i<list.size();i++){
                if(list[i].first == key){
                    return true;
                }
            }
            return false;
        }
        int getSize() const{
            return size;
        }
        int getCapacity() const{
            return capacity;
        }


        friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTable){
            for(int i = 0;i<hashTable.capacity;i++){
                os<<"["<<i<<"] : ";
                auto& list = hashTable.Table[i];
                for(int j = 0;j<list.size();j++){
                    os<<"("<<list[j].first<<","<<list[j].second<<") ";
                }
                os<<std::endl;
            }
            return os;
        }
    };


}


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
    std::cout<<hashTable2<<std::endl;
    return 0;
}


