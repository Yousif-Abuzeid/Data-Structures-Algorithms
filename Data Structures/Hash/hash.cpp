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
    int universalHash(const K& key, int m, int p){
        int a = rand() % (p - 1) + 1;
        int b = rand() % p;
        int hashValue = 0;
        hashValue = ((a * key + b) % p) % m;
        return hashValue % m;
    }
    int universalHash(const std::string& key, int m, int p) {
        int a = rand() % (p - 1) + 1;
        int b = rand() % p;
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
        public:
        HashTable():size(0),capacity(10){

        }


    };
}
