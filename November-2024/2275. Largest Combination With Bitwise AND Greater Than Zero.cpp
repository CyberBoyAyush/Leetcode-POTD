class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxSize = INT_MIN;

        for(int bitsPos = 0; bitsPos < 24; bitsPos++){
            int count = 0;
            for(auto &num : candidates){
                if((num & (1<<bitsPos)) != 0){ // find the bit which is set at that bitPos
                    // that bit is set
                    count++;
                }
                maxSize = max(maxSize,count);
            }
        }
        return maxSize;
    }
};
