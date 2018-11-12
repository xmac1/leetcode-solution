class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ']' || s[i] == ')' || s[i] == '}') {
                if (cs.empty()) {
                    return false;
                }

                bool b = true;
                switch (s[i]) {
                case ']':
                    if (cs.top()!='['){
                        b = false;
                    }
                    break;
                case ')':
                    if (cs.top()!='('){
                        b = false;
                    } 
                    break;
                case '}':
                    if (cs.top()!='{'){
                        b = false;
                    }
                    break;
                }

                if (!b) {
                    return b;
                }
                cs.pop();
                continue;
            }
            cs.push(s[i]);
            
        }
        if (!cs.empty()) {
            return false;
        }
        return true;
    }
};