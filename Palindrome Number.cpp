// 考虑翻转给定的整数，比较翻转后的整数和原整数的值，但是会遇到整数溢出的问题
// 因此考虑只翻转整数的一半，如果翻转的一半等于另一半，那么就是回文数
// 使用 x / 10来考虑到 x 为奇数的情况，当 x 是 10 的整数倍的时候失效
// 当 x 是 10 的整数倍的时候不可能是回文数
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }      

        int rev = 0;
        while(x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return x == rev || rev / 10 == x;
    }
};