class Solution {
public:
    bool parseBoolExpr(string expression){

        stack<char> s;
        
        for(auto c:expression){

            if(c == ')'){
                bool isTrue = false, isFalse = false;

                while(s.top() != '('){
                    char val = s.top();
                    s.pop();
                    if(val == 't') isTrue = true;
                    else if(val == 'f') isFalse = true;
                }
                s.pop();

                char op = s.top();
                s.pop();

                if(op == '&'){
                    s.push(isFalse?'f':'t');
                }
                else if(op == '|'){
                    s.push(isTrue?'t':'f');
                }
                else if(op == '!'){
                    s.push(isTrue?'f':'t');
                }
            }
            else if(c != ','){
                s.push(c);
            }
        }
        return s.top() == 't';
    }
};