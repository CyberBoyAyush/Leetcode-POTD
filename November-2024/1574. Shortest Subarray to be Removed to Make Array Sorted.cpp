class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // step 1 -> find j pointer from right hand side
        int j = n-1;

        while(j > 0 && arr[j] >= arr[j-1]){
            j--;
        }

        int i = 0;
        int res = j; // we initialize it from j as after j the array is sorted and we have checked it so it will work for both already sorted case and case where before j elemets should be removed

        // start finding i and j and deleted elements j - i - 1
        while(i < j && (i == 0 || arr[i] >= arr[i-1])){ // we use this condition as i pointer only go in sorted

            // if arr[j] < arr[i] -> it means we need to move j for better and correect pointer
            while(j < n && arr[j] < arr[i]){
                j++; // go and find coreect j so it will create a sorted arr with combining with i
            }

            // we have a correct j (arr[i] <= arr[j])
            res = min(res, j-i-1);
            i++; // yeh toh hota hi rhega
        }
        return res;
    }
};
