#include "huffman.hpp"

int main() {
    Huffman h("CAABCDCBCCDCACACDCAEBAACBCACAABBCADFCAABBACBBBCCAABDAAAACBCBCAAABBAAAAACCAACCABACACBBBAADAAACCBDCBBBABAAABBABAAAAABCBCBCBAADBDDCAAAAAABABBBCAECBABAABBAABBACBAACDDBBCAAAAABBBBEBAABACCBABBBCCAADDCACBDBAAABBABBDCAAAABEEDAAABBFBBDECBADAAABBBDEBAADABAABABCACADBBDBBBADBAEDDCAADBADABBBBBAACBCBAAADCABDAABABAACBBBCABADCABECBBCACCDCACBBAABBEAABAAADAEABCCBBFCEDAAABACABDBBEADBABCCBDBEBAABCABABDDCBDAAECABAAACBDCAAAABAAADCAEABCAAEEDCDBBAABCCBBBGCACABBBEAAABBBCCACECDABABCCCCBAECABBBBBBBDECDBABDBEACBBCDAABECCAE");
    h.printCodes();
    return 0;
}