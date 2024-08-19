class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        
        int remaining = n; //initially
        int buffer    = 0;
        int count_A   = 1; //initially we have 1 'A'
        int steps     = 0;
        
        while(count_A < n) {
            remaining = n-count_A;
            if(remaining%count_A == 0) {
                buffer     = count_A;
                count_A   *= 2;
                steps     += 2; //copy+paste
            } else {
                count_A   += buffer;
                steps++;
            }
        }
        
        return steps;
    }
};
