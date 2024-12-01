// Bruteforce
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n ; j++){
                if(i != j){
                    if(arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};

// Using extra space (hash set)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int i = 0; i<n ; i++){
            if(st.find(arr[i] * 2) != st.end() || (arr[i]%2 == 0 && st.find(arr[i] / 2) != st.end())){
                return 1;
            }
            st.insert(arr[i]); // Add current element to the set after checks
        }

        return 0;
    }
};

// Binary Search
class Solution {
public:
    int binarySearch(vector<int>& arr, int target){
        int l = 0;
        int r = arr.size()-1;

        while(l<=r){
            int mid = (l + r)/2;

            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return -1;
    }
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(),arr.end());

        for(int i = 0; i<n ; i++){
            int j = binarySearch(arr,arr[i] * 2); // finding multiple

            if(j != -1 && j != i){
                return 1;
            }
        }

        return 0;
    }
};
