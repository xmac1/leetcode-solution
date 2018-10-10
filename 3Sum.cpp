// 思路是先将给定数组排序，小的在左边，大的在右边
// 从小到大遍历排序后的数组
// 因为数组已经排序，所以每次遍历开始的时候，只需要检测当前元素右边的组合是否满足条件即可
// 找出满足条件的组合的关键：双指针分别指向数组末尾以及下一个元素，如果两个元素之和大于当前元素，说明右侧太大应该减少
// 每次完成一个元素的查找，需要跳过下一个重复的元素
// 注意空数组的情况
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> arrs;
        if (nums.size() < 3) {
            return arrs;
        }

        int left, right;
        for (int i = 0; i < nums.size() - 1 && nums[i] <= 0;) {
            int target = -nums[i];
            int left = i+1;
            int right = nums.size() - 1;
            while (right > left) {
                if (nums[left] + nums[right] == target) { // 相加为零
                    vector<int> arr = {nums[left], nums[right], nums[i]};
                    arrs.push_back(arr);
                    while(nums[right] == nums[--right]) {};
                    while(nums[left] == nums[++left]) {};
                } else if (nums[left] + nums[right] > target) { // 右边太大
                    right--;
                } else { // 左边太大
                    left++;
                }


            }
            while(nums[i]==nums[++i]){};
        }
        return arrs;
    }
};