// Freq and XOR property
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long,long> mpp;
        int n = nums1.size();
        int m = nums2.size();

        for(auto num:nums1){
            mpp[num] += m;
        }

        for(auto num:nums2){
            mpp[num] += n;
        }

        int res = 0;
        for(auto it:mpp){
            int num = it.first;
            int freq = it.second;

            if(freq % 2 != 0){
                // odd
                res ^= num;
            }
        }

        return res;
    }
};

// Improved from prev using observtions
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int XOR = 0;

        if(n % 2 != 0){
            // num1 is odd -> XOR nums2
            for(auto num:nums2){
                XOR ^= num;
            }
        }
        if(m % 2 != 0){
            // nums2 is odd -> XOR nusm1
            for(auto num:nums1){
                XOR ^= num;
            }
        }

        return XOR;
    }
};
