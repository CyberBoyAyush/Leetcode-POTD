// Binary Search with some edits in items
// TC - (n + nlogn + m logn)
class Solution {
public:
    int binarySearchFunc(vector<vector<int>>& items, int qPrice){
        int l = 0;
        int r = items.size()-1;

        int maxBeauty = 0; // final answer we return

        while(l<=r){
            int mid = (l + r)/2;

            if(items[mid][0] > qPrice){
                r = mid-1;
            }
            else{
                // if not bigger than that is a candidate
                maxBeauty = max(maxBeauty,items[mid][1]);
                l = mid+1; // maybe bigger can be on right side
            }
        }

        return maxBeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<int> results(m); // size given in question

        // step 1 : sorting items on price
        sort(items.begin(),items.end());

        // updating items acc to maxbeauty to find beauty in O(1)

        int maxBeauty = items[0][1]; // initial

        for(int i = 1; i<n ; i++){
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty; // updating  
        }

        // binary search to find
        for(int i = 0; i<m ; i++){
            int qPrice = queries[i];
            results[i] = binarySearchFunc(items, qPrice);
        }

        return results;
    }
};
