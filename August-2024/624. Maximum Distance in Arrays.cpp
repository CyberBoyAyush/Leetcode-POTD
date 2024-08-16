class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();

        int res = 0;

        for(int i = 1 ; i<arrays.size(); i++){
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            res = max({res,abs(currMin - MAX) , abs(currMax - MIN)});
 
            // updating MIN and MAX
            MIN = min(currMin,MIN);
            MAX = max(currMax,MAX);
        }

        return res;
    }
};
