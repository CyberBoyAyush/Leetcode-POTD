class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int L = 0; // length of LL
        while(temp){
            L++;
            temp = temp->next;
        }

        int EBR = L / k; // Each bucket Nodes
        int remNodes = L % k; // remaning nodes

        vector<ListNode*> res(k,NULL);

        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i = 0 ; curr && i < k ; i++){
            res[i] = curr;

            for(int count = 1; count <= EBR + (remNodes > 0 ? 1 : 0) ; count++){
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL; // remove pointer of prev
            remNodes--; // decrease remNodes beacuse one node is already assigned

        }

        return res;
    }
};
