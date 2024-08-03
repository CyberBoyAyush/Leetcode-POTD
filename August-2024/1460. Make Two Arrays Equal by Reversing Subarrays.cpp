// Approach 1 -> Sort and compare

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();


        // SOrting both the target and arr
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        // now comparing both 
        for(int i=0; i< n ; i++){
            if(target[i] != arr[i]){
                return 0;
            }
        }

        return 1;
    }
};


// Approach 2 -> Using Map
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;

        // pushing el of arr in mp
        for (int num : arr) {
            mp[num]++;
        }

        //comparing it with r=targets
        for (int &num : target) {
            if (mp.find(num) == mp.end())
                return false;

            mp[num]--;
            if (mp[num] == 0) {
                mp.erase(num);
            }
        }
        return mp.size() == 0;
    }
};
