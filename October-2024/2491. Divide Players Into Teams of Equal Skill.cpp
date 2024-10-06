// Approach 1 -> Sorting and making pairs
// TC - O(nlogn) 
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(begin(skill),end(skill));

        int i = 0;
        int j = n-1;
        int s = skill[i] + skill[j];

        long long chem = 0;

        while(i<j){
            int currSkill = skill[i] + skill[j];

            if(currSkill != s){
                return -1; // skill level does not match
            }

            // add in chem
            chem += ((long long)skill[i] * (long long)skill[j]);

            i++;
            j--;
        }

        return chem;
    }
};



// Approach 2 -> Counting Sort and Freq with Observations
// TC - O(n)
// SC - O(1001)

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
       int n = skill.size();

       // count freq vector
       vector<int> vec(1001,0);

       int SUM = 0;

       for(auto i : skill){
            SUM += i; // calcualting sum
            vec[i]++; // updating freq in vec vector
       } 

       int teams = n / 2; // total number of teams can be there
       
       // edge case
       if(SUM % teams != 0){
        // teams cant be possible
        return -1;
       }

       int s = SUM / teams; // skill which will be of each team

       long long chem = 0;

       for(int i = 0; i<n ; i++){
        int currSkill = skill[i];
        int remSkill = s - currSkill;

        if(vec[remSkill] <= 0){
            return -1; // skill not present cant be possible
        }

        chem += (long long)(currSkill) * (long long)(remSkill);

        // now decrease remSkill freq
        vec[remSkill]--;
       }

       return chem / 2; // bca duplicates will be there
    }
};
