class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mpp;

        for(auto &s : arr){
            mpp[s]++;
        }

        int count = 0;
        for(string &s : arr) {
            if(mpp[s] == 1) {
                count++;
                if(count == k) {
                    return s;
                }
            }
        }

        return "";
    }
};
