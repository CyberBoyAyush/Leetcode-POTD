// Approach 1 -> Iterative
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)    return head;

        ListNode* currNode = head;
        ListNode* nextNode = head->next;

        while(nextNode){
            ListNode* temp = new ListNode(__gcd(currNode->val,nextNode->val));

            currNode->next = temp;
            temp->next = nextNode;

            currNode = nextNode;
            nextNode = nextNode->next;
        }

        return head;
    }
};

// Approach 2 -> Recursion
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // base case
        if(!head || !head->next){
            return head;
        }

        // recursive call
        ListNode* temp = insertGreatestCommonDivisors(head->next);

        // gcd node
        ListNode* gcdNode = new ListNode(__gcd(head->val,head->next->val));

        // now creating connections
        gcdNode->next = temp;
        head->next = gcdNode;

        return head;

    }
};
