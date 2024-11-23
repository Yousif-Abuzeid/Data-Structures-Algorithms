#include "huffman.hpp"
#include <vector>

int main() {
    std::vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::vector<double> probabilities = {0.35, 0.3,0.2,0.1,0.04,0.005,0.005};
    Huffman h(characters,probabilities);
    h.printCodes();
    return 0;
}