// Approach 1 -> Sorting and Find
// TC - O(nlogn + m-n)
// SC - O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // base edge case
        if(n > m){
            return false;
        }

        // sort string s1
        sort(s1.begin(),s1.end());

        for(int i = 0; i<=m-n ; i++){
            string substring = s2.substr(i,n);

            sort(begin(substring),end(substring));

            // now we check
            if(s1 == substring){
                return true;
            }
        }

        return false;
    }
};
