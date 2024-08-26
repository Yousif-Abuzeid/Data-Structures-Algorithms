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
        Val& operator[](const K& key){
            int index = universalHash(key,capacity,p,a,b);
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





