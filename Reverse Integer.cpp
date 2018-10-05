// 模 10 得到个位上的数
// 除以 10 去掉个位上的数
// 每次pop都累计乘以10，达到翻转的效果
// 防止整数溢出，只需要判每次*10之前判断是否大于MAX / 10
class Solution {
public:
    int reverse(int x) {
        int pop, tmp, rev, pop;
        rev = 0;
        while (x) {
            pop = x % 10;
            x /= 10;

            tmp = rev * 10 + pop;
            if (rev > INT32_MAX / 10 || (rev == INT32_MAX / 10 && pop > 7)) {
                return 0;
            }

            if (rev < INT32_MIN / 10 || (rev == INT32_MIN / 10 && pop < -8)) {
                return 0;
            }

            rev = tmp;
        }

        return rev;
    }
};