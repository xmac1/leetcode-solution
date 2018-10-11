// 使用栈保存左边的符号
// 每次遇到左边的符号就push进入栈
// 每次遇到右边的符号就pop栈，如果pop出来的符号和当前符号不成对，则无效字符串
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