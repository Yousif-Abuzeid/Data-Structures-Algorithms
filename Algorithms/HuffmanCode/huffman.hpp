#pragma once
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>

// HeapNode represents a node in the Huffman tree
class HeapNode {
public:
    char data;          // Character symbol
    int freq;           // Frequency of the symbol
    double probability; // Probability of the symbol (used in the new constructor)
    HeapNode *left, *right; // Left and right child nodes

    // Constructor for nodes with frequencies (used in original code)
    HeapNode(char data, int freq);

    // Constructor for nodes with probabilities (new for your feature)
    HeapNode(char data, double probability);
};

// Comparator for the priority queue (min-heap)
struct compareNodes {
    bool operator()(HeapNode* l, HeapNode* r) {
        return (l->probability > r->probability); // Compare based on probability (not frequency)
    }
};

// Huffman class responsible for building the Huffman tree and generating codes
class Huffman {
private:
    char internalChar = char(0); // Internal placeholder character
    std::priority_queue<HeapNode*, std::vector<HeapNode*>, compareNodes> minHeap; // Min-heap for the tree construction
    std::unordered_map<char, std::string> huffmanCodes; // Store Huffman codes for each symbol

    // Helper method to generate Huffman codes from the tree
    void generateCodes(HeapNode* root, std::string str);

public:
    // Constructor for encoding a message (original constructor)
    Huffman(std::string message);

    // New constructor for constructing the Huffman tree with symbols and probabilities
    Huffman(const std::vector<char>& symbols, const std::vector<double>& probabilities);

    // Get the generated Huffman codes
    std::unordered_map<char, std::string> getCodes();

    // Print the Huffman codes
    void printCodes();

   

    // Encode a message using the generated Huffman codes
    std::string encodeMessage(std::string message);

    // Decode a message using the generated Huffman codes
    std::string decodeMessage(std::string message, std::unordered_map<char,std::string> huffmanCodes);

    // Destructor to free memory allocated for the tree nodes
    ~Huffman();


};
