class Solution {
public:
    int maxScore(string s) {
        int oneCnt = count(s.begin(),s.end(),'1');
        int zeroCnt = 0;
        int maxRes = 0;

        for(int i = 0; i<s.length()-1 ; i++){
            if(s[i] == '0'){
                zeroCnt++;
            }
            else{
                oneCnt--;
            }

            maxRes = max(maxRes, zeroCnt + oneCnt);
        }
        return maxRes;
    }
};
