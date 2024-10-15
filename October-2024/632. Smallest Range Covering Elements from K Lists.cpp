class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // we use minheap in this case in which we use pairs to store data, row, col -> 
        //we store row and col to push the next data in the heap after pop
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        // we need two variable to store the min and max for range creation
        int minimum, maximum = INT_MIN;

        // now we push the values of first element of first row in heap
        for(int i = 0;i<nums.size();i++){
            pq.push(make_pair(nums[i][0],make_pair(i,0)));
            // as we are using minheap we have to calculte our maximum here only
            maximum = max(maximum,nums[i][0]);
        } 

        // updating the minimum 
        minimum = pq.top().first; // as we are using min heap

        // creating our ans
        vector<int> ans(2);
        ans[0] = minimum;
        ans[1] = maximum;

        pair<int,pair<int,int>> temp;
        int row,col,elem;
        // operations happens here
        while(pq.size() == nums.size()){ 
            // how many k arr in 3d arrays if less than that means 1 arr exhausted

            //extracting the pair
            temp = pq.top();
            pq.pop(); // removal

            //extracting the deatils from the pair
            elem = temp.first;
            row = temp.second.first;
            col = temp.second.second;

            // pushing the cvlaue next to popped data
            if(col+1<nums[row].size()){
                pq.push(make_pair(nums[row][col+1],make_pair(row,col+1)));
                // updating min and max also
                maximum = max(maximum,nums[row][col+1]);
                minimum = pq.top().first;

                // checking for do we get smaller range
                if(maximum-minimum < ans[1] - ans[0]){
                    ans[0] = minimum;
                    ans[1] = maximum;
                }
            }
        }

        return ans;

    }
};
