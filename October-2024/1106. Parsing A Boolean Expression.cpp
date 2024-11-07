class Solution {
public:
    char solveOp(char op, vector<char> &values){
        // if ! operator (not)
        if(op == '!'){
            return values[0] == 't' ? 'f' : 't';
        }

        // if & operator (and)
        if(op == '&'){
            for(auto &c : values){
                if(c == 'f'){
                    return 'f';
                }
            }
            return 't';
        }

        // if | operator (or)
        if(op == '|'){
            for(auto &c : values){
                if(c == 't'){
                    return 't';
                }
            }
            return 'f';
        }
        return 't'; // random value
    }
    bool parseBoolExpr(string expression) {
        int n = expression.length();

        stack<char> st;

        for(int i = 0; i<n; i++){
            if(expression[i] == ','){
                // ignore it
                continue;
            }
            
            if(expression[i] == ')'){
                // we pop it to evaluate
                vector<char> values;

                while(!st.empty() && st.top() != '('){
                    values.push_back(st.top());
                    st.pop();
                }

                st.pop(); // pop open bracket also

                char op = st.top(); // operator for evaluation (! , | , &)
                st.pop();

                st.push(solveOp(op,values)); // pushing final after evaluation for further evaluation
            }

            else{
                st.push(expression[i]);
            }
        }
        return st.top() == 't' ? true : false;
    }
};
