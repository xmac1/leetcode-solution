// 基本思想，求解一个数字或者两个数字对应的字母串数组是简单，使用分治法，将原本多个数字字符串分解为左右两份
// 分别对左右两份字符串递归的进行处理
// 对左右两边处理的结果进行合并.
// 注意传入字符串为空的情况;
static unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() < 1) {
            vector<string> vs;
            return vs;
        }
        if (digits.size() == 2) {
            vector<string> vs;
            for (int i=0; i < m[digits[0]].size() ; i++) {
                for (int j = 0; j < m[digits[1]].size(); j++) {
                    string s =  {m[digits[0]][i], m[digits[1]][j]};
                    vs.push_back(s); 
                }
            }
            return vs;
        } else if (digits.size() == 1) {
            vector<string> vs;
            for(int i = 0; i < m[digits[0]].size() ; i++) {
                string s = {m[digits[0]][i]};
                vs.push_back(s);
            }
            return vs;
        } else {
            string left(digits.begin(), digits.begin() + digits.size() / 2);
            vector<string> ls = letterCombinations(left);
            string right(digits.begin() + digits.size() / 2, digits.end());
            vector<string> rs = letterCombinations(right);
            vector<string> vs;
            for (int i = 0; i < ls.size(); i++) {
                for (int j =0; j < rs.size(); j++) {
                    
                    string s = ls[i] + rs[j];
                    vs.push_back(s);
                }
            }
            return vs;
        }
    }
    
};

