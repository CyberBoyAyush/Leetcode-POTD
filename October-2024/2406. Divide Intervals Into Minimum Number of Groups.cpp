// TC - O(nlogn)
// SC - O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // sorting based on starting point
        sort(intervals.begin(),intervals.end());

        // min heap for optimized grouping
        priority_queue<int , vector<int>, greater<int>> pq;

        // processing intervals
        for(auto &vec : intervals){
            int start = vec[0];
            int end = vec[1];

            // checking start
            if(!pq.empty() && start > pq.top()){
                pq.pop();
            }

            pq.push(end);
        }

        return pq.size();
    }
};
