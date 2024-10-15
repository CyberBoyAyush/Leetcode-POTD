class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
       priority_queue<int> pq(nums.begin(), nums.end());

       long long sum = 0;

       while(k--){
            int maxEl = pq.top();
            pq.pop();

            sum += (maxEl);
            maxEl = ceil(maxEl / 3.0);
            pq.push(maxEl);
       } 

       return sum;
    }
};
