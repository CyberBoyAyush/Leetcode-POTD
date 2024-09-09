// TC - O(m*n)
// SC - O(m*n)
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        //creating result 2d matrix
        vector<vector<int>> res(m, vector<int>(n,-1));

        int id = 0; // 0,1,2,3 -> pointer that tells us where are we going
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;

        while(left<=right && top<=down){
            if(id == 0){
                // left to right
                for(int i = left; head != nullptr && i<=right ; i++){
                    res[top][i] = head->val;
                    head = head->next;
                }
                top++; // increaing top for next time operation
            }

            if(id == 1){
                // top to down
                for(int i = top; head != nullptr && i<=down ; i++){
                    res[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }

            if(id == 2){
                //right to left
                for(int i = right; head != nullptr && i>=left ; i--){
                    res[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }

            if(id == 3){
                // down to top
                for(int i = down; head != nullptr && i>=top ; i--){
                    res[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            id = (id+1) % 4; // 0,1,2,3
        }

        return res;
    }
};
