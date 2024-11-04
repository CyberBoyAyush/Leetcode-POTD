class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;

        int n = word.length();

        while(i<n){
            char ch = word[i];
            int count = 0;

            while(i<n && count < 9 && word[i] == ch){
                i++;
                count++;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};
