// Bruteforce 
// O(N^2)
// O(N)
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> chairs(n,-1);

        int arrivalTime = times[targetFriend][0];

        sort(times.begin(),times.end()); // based on arrival

        for(auto &time:times){
            int arrival = time[0];
            int dept = time[1];

            // loop on chairs
            for(int i = 0 ; i< n ; i++){
                if(chairs[i] <= arrival){
                    // khaali hai
                    chairs[i] = dept; // chair is occupied

                    if(arrival == arrivalTime){
                        return i; // we found the answer
                    }
                    break;
                }
            }
        }
        return -1;
    }
};

// Using Priority_Queue
// O(n * logn)
// O(n)
class Solution {
public:
    typedef pair<int,int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        // min heap for occupied and freechair
        priority_queue<P, vector<P>, greater<P>> occupied; // {dept_time,chairNo}
        priority_queue<int, vector<int>, greater<int>> free; // freechair

        int arrivalTime = times[targetFriend][0];

        int chairNo = 0; // tell us the chair number available

        sort(times.begin(), times.end()); // based on arrival time

        for(int i = 0 ; i< n ; i++){
            int arrival = times[i][0];
            int dept = times[i][1];

            // freeing occupied chairs
            while(!occupied.empty() && occupied.top().first <= arrival){
                // free it
                free.push(occupied.top().second); // pushing free chairs in free
                occupied.pop();
            }

            // if no free chairs available
            if(free.empty()){
                // push it in occupied from chairNo 
                occupied.push({dept,chairNo});
                if(arrival == arrivalTime){
                    return chairNo;
                }
                chairNo++;
            }
            else{
                // free has some chairs available
                int leastChairNo = free.top(); // getting chair
                free.pop(); // popping it from free
                if(arrival == arrivalTime){
                    return leastChairNo;
                }
                // fill occupied
                occupied.push({dept,leastChairNo});
            }
        }

        return -1;
    }
};
