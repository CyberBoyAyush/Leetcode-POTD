class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto mycomp = [](auto &a,auto &b){
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1+s2 > s2+s1;
        };

        sort(begin(nums),end(nums),mycomp);

        if(nums[0] == 0){
            return "0";
        }

        string ans;
        for(auto it : nums){
            ans+=to_string(it);
        }
        return ans;
    }
};
