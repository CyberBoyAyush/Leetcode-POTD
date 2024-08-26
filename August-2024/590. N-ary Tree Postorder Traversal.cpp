class Solution {
public:
    vector<int> ans;

    void traversal(Node* root){
        if(!root){
            return;
        }

        for(Node* &x : root -> children){
            traversal(x);
        }

        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        ans.clear();
        traversal(root);
        return ans;
    }
};
