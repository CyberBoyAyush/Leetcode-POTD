class Solution {
public:
    bool isPossible(int mid, int shops, vector<int>& quantities){
        for(int & prod : quantities){
            shops -= (prod + mid - 1) / mid;
            
            if(shops < 0){
                return false;
            }
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        int l = 1;
        int r = *max_element(begin(quantities), end(quantities));

        int ans = 0;

        while(l<=r){
            int mid = l + (r-l) / 2;

            if(isPossible(mid, n, quantities)){
                ans = mid;
                r = mid - 1; // bcz we need to minimize it
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};
