class Solution {
public:
    string fractionAddition(string expression) {
        int nume = 0;
        int denom = 1;

        int i = 0;
        int n = expression.length();
        while(i<n){
            int currNume = 0; // stores current numirator
            int currDenom = 0; // stores curr denominator
            bool isNegative = (expression[i] == '-'); // tells us if expression is negative or not

            // skipping the + and - symbols
            if(expression[i] == '+' || expression[i] == '-'){
                i++;
            }

            // bulding the nume
            while(i<n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currNume = (currNume * 10) + val;
                i++;
            }

            i++; // we added it because it is divisor to skip it we i++

            // checking negative
            if(isNegative==true){
                // nume becomes negative
                currNume *= -1;
            }

            // building the currDenom
            while(i<n && isdigit(expression[i])){
                int val = expression[i] - '0';
                currDenom = (currDenom * 10) + val;
                i++;
            }

            // now we are doing multiplication
            nume = nume * currDenom + currNume * denom;
            denom = denom * currDenom;
        }
        
        // to simplify the function as we are asked in question

        int GCD = abs(__gcd(nume,denom));

        nume /= GCD;
        denom /= GCD;

        // creating the final string -> ans
        return to_string(nume) + "/" + to_string(denom);

    }
};
