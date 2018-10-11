// 思路是排序数组
// 然后从左往右遍历数组
// 对每个元素执行另外一次遍历
// 找到三个元素使得他们的和与给定值之差最小
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT32_MAX;
        int size = nums.size();
        int sum;

        for (int i = 0; i < size - 2; i++) {
            int l = i + 1;
            int r = size - 1;

            while (r > l) {
                if (abs(nums[l] + nums[r] + nums[i] - target) < diff) {
                    diff = abs(nums[l] + nums[r] + nums[i] - target);
                    sum = nums[l] + nums[r] + nums[i];
                 }
                 if (nums[l] + nums[r] + nums[i] > target) {
                    r--;
                 } else if (nums[l] + nums[r] + nums[i] < target) {
                    l++;
                 } else {
                    sum = nums[r] + nums[l] + nums[i];
                    return sum;
                 }
            }

        }

        return sum;
    }
};