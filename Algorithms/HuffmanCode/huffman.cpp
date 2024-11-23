#include "huffman.hpp"
#include <unordered_map>
#include <iostream>

HeapNode::HeapNode(char data,int freq) {
            left = right = nullptr;
            this->data = data;
            this->freq = freq;
        }

Huffman::Huffman(std::string message) {
    std::unordered_map<char , int> freqHash;
    for (char c : message) {
        if(freqHash.find(c) == freqHash.end()) {
            freqHash[c] = 1;
        } else {
            freqHash[c]++;
        }

    }
    for (auto i : freqHash) {
        minHeap.push(new HeapNode(i.first,i.second));
    }

    HeapNode *left, *right, *top; 
    int newFreq;

    while(minHeap.size() !=1){
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        newFreq = left->freq + right->freq;
        top = new HeapNode(internalChar,newFreq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    this->generateCodes(minHeap.top(),"");
}

void Huffman::generateCodes(HeapNode* root,std::string str) {
    if(root == nullptr) {
        return;
    }
    if(root->data != internalChar) {
        huffmanCodes[root->data] = str;
    }
    generateCodes(root->left,str + "0");
    generateCodes(root->right,str + "1");
}

std::map<char,std::string> Huffman::getCodes() {
    return huffmanCodes;
}

void Huffman::printCodes() {
    for (auto i : huffmanCodes) {
        std::cout << i.first << " " << i.second << std::endl;
    }
}