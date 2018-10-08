// 双指针法
// 从数组的两段逐渐向中心靠拢
// 每次都选择高度低的一端向中心靠近，因为较低的一端可能变高，使得容量变大
// 面积大小取决于较小的一端

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left, right;
        left = 0;
        right = height.size() - 1;
        int maxarea = 0;

        while (left < right) {
            maxarea = max(maxarea, min(height[left], height[right]) * (right - left));
            height[left] < height[right] ? ++left : --right;
        }
        return maxarea;
    }
};