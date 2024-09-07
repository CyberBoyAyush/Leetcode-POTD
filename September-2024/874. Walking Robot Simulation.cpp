class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;

        // inserting the obstacles into an efficient data structure
        for(auto obs : obstacles){
            // firstly creating it as a string
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);

            st.insert(key);
        }

        // initally it is standing at 0,0
        int x = 0;
        int y = 0;
        int maxD = 0;

        // initially it is pointing to NORTH
        pair<int,int> dir = {0,1}; // for north movement

        // now we do operations
        for(int i = 0 ; i<commands.size(); i++){
            //if command is -2 we turn left
            if(commands[i] == -2){
                dir = {-dir.second,dir.first}; // (x,y) -> (-y,x)
            }
            // if commadn is -1 turn right
            else if(commands[i] == -1){
                dir = {dir.second, -dir.first}; // (x,y) -> (y,-x)
            }
            else{
                // move the steps written in it
                for(int steps = 0; steps<commands[i] ; steps++){
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string nextKey = to_string(newX) + "_" + to_string(newY);

                    // checking for obstacles
                    if(st.find(nextKey) != st.end()){
                        // key found -> obstacle is here
                        break;
                    }

                    // now we move x and y for further movement
                    x = newX;
                    y = newY;
                }
            }

            // now finding dist
            maxD = max(maxD, x*x + y*y);
        }
        return maxD;
    }
};
