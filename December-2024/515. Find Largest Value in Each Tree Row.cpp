// BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root){
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<int> res;

        while(!q.empty()){
            int n = q.size();
            int maxEl = INT_MIN;
            while(n--){
                TreeNode *curr = q.front();
                q.pop();

                maxEl = max(maxEl, curr->val);

                // push left and right
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }

            // level traversed put the maxEl
            res.push_back(maxEl);
        }

        return res;
    }
};

// DFS
class Solution {
public:
    vector<int> ans; // final ans vector
    vector<int> largestValues(TreeNode* root) {
        DFS(root,0);
        return ans;
    }

    void DFS(TreeNode* root, int depth){
        if(!root)   return;
        if(depth == ans.size()){
            // first time aaye hai 
            ans.push_back(root->val); // curr max maan lete hai
        }

        else{
            ans[depth] = max(ans[depth], root->val);
        }

        // dfs maar do
        DFS(root->left,depth+1);
        DFS(root->right,depth+1);
    }
};
