// TC - O(log n)^2
// SC - O(log n)
class Solution {
public:
    int Count(long curr, long next, long n){
        long countNum = 0;

        while(curr<=n){
            countNum += (next - curr);

            // we go deeper one level
            curr *= 10;
            next *= 10;

            // we check next in limit
            next = min(next, long(n+1));
        }

        return countNum;
    }
    int findKthNumber(int n, int k) {
        int curr = 1; // bcz lexograhical starts from 1
        k -= 1; // bcz we already took 1

        while(k>0){
            int count = Count(curr, curr+1, n); // curr, next, n
            if(count <= k){
                curr++; // we go next lexo order
                k -= count; // skipping that count from k
            }
            else{
                // we go to next level as k is in same lexo order
                curr *= 10;
                k -= 1; // as we go depper in tree 1 element is removed from it
            }
        }

        return curr;
    }
};
