#pragma once
#include <map>
#include <queue>
#include <string>
#include <vector>
class HeapNode {

    public:
        char data;
        int freq;
        HeapNode *left, *right;

        HeapNode(char data,int freq);


};

struct compareNodes {
    bool operator()(HeapNode* l, HeapNode* r) {
        return (l->freq > r->freq);
    }
};
class Huffman{
    private:
        char internalChar = char(0);
        std::priority_queue<HeapNode*, std::vector<HeapNode*>,compareNodes> minHeap;
        std::map<char,std::string> huffmanCodes;
        void generateCodes(HeapNode* root,std::string str);
    public: Huffman(std::string message);
    std::map<char,std::string> getCodes();
    void printCodes();

};