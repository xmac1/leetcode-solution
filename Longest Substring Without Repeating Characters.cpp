// 考虑滑动窗口[i, j), 滑动窗口总是保存不包含重复字符的字符串
// 使用一个 map 保存字符和字符的位置 map<char, idx>
// 每当扫描到下一个字符，如果在 map中发现这个字符的位置在 i 的右侧，说明滑动窗口中出现重复的字符
// 当出现重复字符的时候，令 i 移动到重复字符的下一个位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> cmap;
        int j = 0;
        int total = 0;
        for (int i = 0; j < s.size();j++ ) {
            map<char, int>::iterator it = cmap.find(s.at(j));
            if ( it != cmap.end()) { // if exists;
                if (it -> second > i) {
                    i = it -> second;
                }
            }
             cmap[s.at(j)] = j + 1;

             int tmp = j - i+1;
             if (tmp > total) {
                total = tmp;
             }
         }

        return total;
    }
};