class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        if (n == 0) {
            vs.push_back("");
        } else {
            for (int i = 0; i < n; ++i) {
                for (string left :generateParenthesis(i)) {
                    for (string right : generateParenthesis(n-i-1)){
                        vs.push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return vs;
    }
};