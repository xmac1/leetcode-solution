// O(n2) 算法
// 遍历字符串，以每个字符为中心检测最长的回文字符串
// 注意到两个相同字符为中心的情况
// string::substr
class Solution {
public:
	string longestPalindrome(string s) {
		int size = s.size();
		int left, right;
		int maxLength = 1;
		int maxLeft, maxRight;
		maxLeft = maxRight = 0;
        int single = 0;
        int pair = 0;
		for (int i = 0; i < size; i++) {
            left = right = i;
			while (left >= 0 && right < size && s.at(left) == s.at(right)) {
                left--;
                right++;
            }
            
            single = right - left - 1;

            left = i;
            right = i + 1 ;
            while (left >= 0 && right < size && s.at(left) == s.at(right)) {
                left--;
                right++;
            }
            pair = right - left - 1;

            maxLength = max(single, pair);

            if (maxLength > maxRight - maxLeft) {
                maxRight = i + maxLength / 2;
                maxLeft = i - (maxLength - 1) / 2;
            }
            
		}

		string s.substr(maxLeft, maxLength);
	}
};
