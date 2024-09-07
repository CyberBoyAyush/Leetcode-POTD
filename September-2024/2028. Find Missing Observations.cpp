class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);
        
        // Subtract the sum of the known rolls
        for (int i = 0; i < m; i++) {
            sum -= rolls[i];
        }

        // Check if it's possible to distribute the remaining sum
        if (sum < n || sum > 6 * n) {
            return {}; // Return empty vector if it's not possible
        }

        vector<int> result(n, sum / n);
        int remainder = sum % n;

        // Distribute the remainder across the result array
        for (int i = 0; i < remainder; i++) {
            result[i]++;
        }

        return result;
    }
};
