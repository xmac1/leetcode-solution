static const map<char, int> cmap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

class Solution {
public:
    int romanToInt(string s) {


        int number = 0;
        int start = s.size() - 1;
        for (int i = s.size() -1 ; i >= 0; ) {
            int n = 0;
            int startNum = cmap[s.at(start)];
            while (i == start || (cmap[s.at(i)] / 10) <= (cmap[s.at(i-1)] / 10) {
                if (cmap[s.at(i)] < startNum) {
                    n -= cmap[s.at(i)];
                } else {
                    n += cmap[s.at(i)];
                }
            }
            start = i;

        }
    }

};


