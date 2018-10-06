// 使用 map 保存宝石代表的字符。。。。很简单
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, bool>jmap;
        int total = 0;
        for (string::iterator it = J.begin(); it != J.end(); it++) {
            jmap[*it] = true;
        }
        
        for (string::iterator it = S.begin(); it != S.end(); it++) {
            map<char, bool>::iterator v = jmap.find(*it);
            if (v == jmap.end()) {
                continue;
            }
           
            total++;
            
            
        }
        return total;
    }
};