// TC - O(N) -> SC - O(1)
class Solution {
public:
    long func(long firstHalf , bool isEven){
        long resultNum = firstHalf; // till now we only have first half with us so we assign into it
        // case 1 -> odd len
        if(isEven == false){
            firstHalf /= 10; // as we take last num as center if len is odd
        }

        while(firstHalf > 0){
            int digit = firstHalf % 10; // it extracts the digit
            
            // creation of resultNum
            resultNum = (resultNum * 10) + digit;

            firstHalf /= 10; // to removes the last digit and process it further

        }
        return resultNum;
    }

    string nearestPalindromic(string n) {
        // finding the length of string.
        int len = n.length();

        int mid = len / 2; // take half of the string n

        // not finding the first half length. even -> mid , odd->mid+1

        int firstHalfLength = (len % 2 == 0) ? mid : mid + 1;

        // now we take the subscrupt till the half part 

        long firstHalf = stol(n.substr(0,firstHalfLength)); // converting string into long

        // storing all possible results in a vector
        vector<long> possibleResults;

        // now we call function for all cases (present in notes)

        possibleResults.push_back(func(firstHalf , len %2 ==0)); // first half , even / odd
        possibleResults.push_back(func(firstHalf+1 , len %2 ==0)); // first half + 1 , even / odd
        possibleResults.push_back(func(firstHalf-1 , len %2 ==0)); // first half - 1 , even / odd
        possibleResults.push_back((long)pow(10, len - 1) - 1); // 10^n + 1 // for 999..999
        possibleResults.push_back((long)pow(10, len) + 1); // 10^n - 1 // for 1000....0001

        // now we have all possible result in possibleResults so we check and send ficnal result

        long diff = LONG_MAX; // stores the difference (min)

        long result = LONG_MAX; // stores the final result

        long originalNum = stol(n); // stores the original num from string n converted in long

        for(long num : possibleResults){
            // case 1 num and original num are same
            if(num == originalNum)  continue;

            // finding the diff (min)
            if(abs(num - originalNum) < diff){
                diff = abs(num - originalNum); // asigining the diff (min)
                result = num; // assignning the num
            }

            // condt -> if diff is same we send the mininum one
            else if(abs(num - originalNum) == diff){
                // tie in numbers
                result = min(result , num); // which is smallest
            }
        }

        // return final result as string
        return to_string(result);
    }
};
