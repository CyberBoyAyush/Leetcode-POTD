class Solution {
public:
    bool check(ListNode* head,TreeNode* root){
        if(head==NULL){
            // we found the complete LL in BT
            return 1;
        }
        if(root==NULL){
            // BT got finsihed and we cant find LL in it
            return 0;
        }

        if(root->val != head->val){
            /// value not matched return false
            return false;
        }

        return check(head->next,root->left) || check(head->next,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL)    return false;
        return check(head,root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
