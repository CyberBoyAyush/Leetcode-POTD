// Appraoch 1 -> flipping all bits one by one
// TC - O (log2(num))
class Solution {
public:
    int findComplement(int num) {
        int numBits = (int)(log2(num)) + 1; // it finds the number of bits

        for(int i = 0; i< numBits; i++){
            num = num ^ (1<<i);
        }

        return num;
    }
};

// Appraoch 2 -> mask
class Solution {
public:
    int findComplement(int num) {
        int numBits = (int)(log2(num)) + 1; // it finds the number of bits

        unsigned int mask = (1U << numBits) - 1; // to safe than int overflow we use unsigned int

        return num ^ mask;
    }
};
