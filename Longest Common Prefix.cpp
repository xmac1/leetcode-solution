// 很简单，注意字符串数组为空以及字符串为空的情况即可
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common;
        int i = 0;

        if (strs.size() < 1) {
            return common;
        }
        while(true) {
            char c;
            bool prefix = true;
            for (int j =  0; j < strs.size(); j++) {
                if (i >= strs.at(j).size()) {
                    prefix = false;
                    break;
                }

                if (j == 0)  {
                    c = strs.at(0).at(i);
                    continue;
                }

                if (strs.at(j).at(i) != c) {
                    prefix = false;
                    break;
                }
            }

            if (!prefix) {
                break;
            }
            common = common.append(1, strs[0].at(i));
            i++;
        }
        return common;
    }
};