class Solution {
public:
    vector<vector<int>> directions = {
        {0,1}, // EAST
        {1,0}, //South
        {0,-1}, //West
        {-1,0} //north
    };
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;

        int steps = 0;
        int dir = 0 ; // 0 -> east, 1-> south, 2->west, 3-> north

        result.push_back({rStart,cStart});

        while(result.size() < rows * cols){
            if(dir == 0 || dir == 2){
                steps++;
            }

            for(int count = 0 ; count < steps ; count++){
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                // Pushing in reuslt
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    result.push_back({rStart,cStart});
                }
            }

            dir = (dir+1) % 4; // changing directions
            
        }

        return result;
    }
};
