#include "huffman.hpp"
#include <unordered_map>
#include <iostream>

HeapNode::HeapNode(char data,int freq) {
            left = right = nullptr;
            this->data = data;
            this->freq = freq;
            this->probability = 0.0; // not used in this constructor
        }

HeapNode::HeapNode(char data,double probability) {
            left = right = nullptr;
            this->data = data;
            this->probability = probability;
            this->freq = 0; // not used in this constructor
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

std::unordered_map<char,std::string> Huffman::getCodes() {
    return huffmanCodes;
}

void Huffman::printCodes() {
    for (auto i : huffmanCodes) {
        std::cout << i.first << " " << i.second << std::endl;
    }
}

// Constructor that builds the tree using symbols and probabilities
Huffman::Huffman(const std::vector<char>& symbols, const std::vector<double>& probabilities) {
    if (symbols.size() != probabilities.size()) {
        throw std::invalid_argument("Symbols and probabilities must have the same size.");
    }

    // Add all symbols to the priority queue as leaf nodes
    for (size_t i = 0; i < symbols.size(); ++i) {
        minHeap.push(new HeapNode(symbols[i], probabilities[i]));
    }

    // Build the Huffman tree
    while (minHeap.size() > 1) {
        HeapNode* left = minHeap.top();
        minHeap.pop();
        HeapNode* right = minHeap.top();
        minHeap.pop();

        HeapNode* merged = new HeapNode(internalChar, left->probability + right->probability); // Internal node
        merged->left = left;
        merged->right = right;

        minHeap.push(merged); // Add the merged node back to the priority queue
    }

    // The root of the tree is the last remaining node
    HeapNode* root = minHeap.top();
    generateCodes(root, ""); // Generate codes for the symbols
}


// Destructor to free memory allocated for the tree nodes
Huffman::~Huffman() {
    while (!minHeap.empty()) {
        HeapNode* node = minHeap.top();
        minHeap.pop();
        delete node;
    }
}

