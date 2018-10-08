// 注意4，9的边界条件即可
// 每次pop出最后一位数字
class Solution {
public:
    string intToRoman(int num) {
        int i = 0;

        string one, five;
        string roma;
        string tmp;
        while (num != 0) {
            tmp.clear();
            int pop = num % 10;
            num /= 10;

            int idx = pop / 5 + i;
            if (pop != 0) {
                if (pop == 4) {
                    tmp.append(1, sign[idx]);
                    tmp.append(1, sign[idx+1]);
                } else if (pop == 9) {
                    tmp.append(1, sign[idx-1]);
                    tmp.append(1, sign[idx+1]);
                } else {
                    tmp.append(1, sign[idx]);
                    if (pop >= 5) {
                        tmp.append((pop - (1+4*(idx % 2))), sign[idx - 1]);
                    } else {
                         tmp.append((pop - (1+4*(idx % 2))), sign[idx]);
                    }
                }
            }

            roma = tmp.append(roma);

            i += 2;

        }

        return roma;
    }
    string sign = "IVXLCDM";
 };