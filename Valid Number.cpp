class Solution {
public:
    bool isNumber(string s) {
        bool preEmpty, preSign, midE, oneDot, oneE, noDigit, afterEmpty;
        preEmpty = preSign =  true;
        midE = false;
        oneDot = oneE = false;
        noDigit = true;
        preEmpty = true;
        afterEmpty = false;

        for (string::iterator it = s.begin(); it != s.end(); it++) {
            char c = *it;
            if (c == ' ') {
                if (preEmpty) {
                    continue;
                } else {
                    afterEmpty = true;
                    continue;
                }
                return false;
            }

            preEmpty = false;

            if (c == '-' || c == '+') {
                if (preSign) {
                    continue;
                }
                return false;
            }

            preSign = false;

            if (c == '.') {
                if ( oneDot) {
                    return false;
                }
                oneDot = true;
                continue;
            }

            if (c == 'e') {
                if (!midE || oneE) {
                    return false;
                }
                midE = false;
                oneE = true;
            } else if (c < '0' || c > '9') {
                return false;
            } else {
                midE = true;
                noDigit = false;
                if (afterEmpty) {
                    return false;
                }
            }
        }
        if (noDigit) {
            return false;
        }
        return true;
    }
};