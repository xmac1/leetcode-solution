// char 强制转 int 表示的是ascii 码点的数值
// 字面值为数字的char-‘0’时表示的就是字面值数字，因为0-9是按照连续顺序表示的
// 判断是否溢出只需要每次*10之前检查是否大于MAX/10
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