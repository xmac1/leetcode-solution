// 模 10 得到个位上的数
// 除以 10 去掉个位上的数
// 每次pop都累计乘以10，达到翻转的效果
// 防止整数溢出，只需要判每次*10之前判断是否大于MAX / 10
// 编译报错：expected unqualified-id before string constant，少写了某个花括号导致的
// 注意题目要求的非数字字符的位置（只包含一个符号）

class Solution {
public:
    int myAtoi(string str) {
        string::iterator it;
        bool sign = false;
        bool firstSign = false;
        bool preEmpty = true;
        bool preSign = true;
        int number, i;
        number=i=0;

        for (it = str.begin(); it != str.end(); it++) {
            if (*it == ' ') {
                if (preEmpty) {
                    continue;
                } else {
                    break;
                }
            }
            preEmpty = false;
            if (*it == '-') {
                if (firstSign) {
                    break;
                } else if (!preSign) {
                    break;
                } else {
                    sign = true;
                    firstSign = true;
                }
            } else if (*it == '+'){
                if (firstSign) {
                    break;
                }else if (!preSign) {
                    break;
                } else {
                    firstSign = true;
                }
            }else if (*it > '9' || *it < '0') {
                break;
            } else {
                preSign = false;
                int add = (int)(*it - '0');
                if (sign) {
                    add *= -1;
                }
                if ((number > INT32_MAX / 10) || (number == INT32_MAX / 10 && add > 7)) {
                    return INT32_MAX;
                }
                if (number < INT32_MIN / 10 || (number == INT32_MIN / 10 && add < -8)) {
                    return INT32_MIN;
                }
                number = add + number * 10;
                i++;
            }
        }
        
        return number;
    }
};