class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minVal = INT_MAX;
        int negNo = 0;

        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                sum += abs(matrix[i][j]);

                if(matrix[i][j] < 0){
                    negNo++;
                }

                minVal = min(minVal, abs(matrix[i][j]));
            }
        }


        if(negNo % 2 == 0){
            // even no
            return sum;
        }
        else{
            // odd
            return sum - 2 * minVal;
        }
    }
};
