// 思路是先将给定数组排序，小的在左边，大的在右边
// 从小到大遍历排序后的数组
// 因为数组已经排序，所以每次遍历开始的时候，只需要检测当前元素右边的组合是否满足条件即可
// 找出满足条件的组合的关键：双指针分别指向数组末尾以及下一个元素，如果两个元素之和大于当前元素，说明右侧太大应该减少
// 每次完成一个元素的查找，需要跳过下一个重复的元素
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, j, k;
        vector<vector<int> > result;
        if (nums.size() < 3)
        	return result;
        sort(nums.begin(), nums.end()); 
        while(i < nums.size() - 2 && nums[i] <= 0)
        {
            j = i + 1;
            k = nums.size() - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] == -nums[i])
                {
                    vector<int> vecTemp = {nums[i], nums[j], nums[k]};
                    result.push_back(vecTemp);
                    while(nums[j] == nums[--j]){}
                    while(nums[k] == nums[--k]){}
                }
                else if (nums[j] + nums[k] > -nums[i])
                    k--;
                else
                    j++;
            }
            while(nums[i] == nums[++i]) {}
        }
        return result;
    }
};