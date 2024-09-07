class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // putting all the nums element into unordred set for efficient retrival
        unordered_set<int> st(nums.begin(),nums.end());

        // now we handle the head
        while(head!= NULL && st.find(head->val) != st.end()){
            ListNode* temp = head;
            // we shift the head
            head = head -> next;

            delete(temp);
        }

        // now other nodes
        ListNode* curr = head;
        while(curr!=NULL && curr->next != NULL){
            if(st.find(curr->next->val)!=st.end()){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            }
            else{
                curr = curr->next;
            }
        }

        return head;

    }
};
