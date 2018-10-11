// 和其它给定值求元素之和一样，先将数组排序
// 然后固定收尾两个指针
// 在两个指针之间找出所有匹配的元素
// 然后跳过重复的元素
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vvi;
        if (nums.size() < 4) {
            return vvi;
        }
        sort(nums.begin(), nums.end());

        
        for (int i = 0; i < nums.size() - 3;) {
            int first = nums[i];
            for (int j = nums.size() - 1; j > i + 2;) {
                int last = nums[j];
                int left, right;
                left = i+1;
                right = j - 1;
                while (right > left) {
                    if (first + last + nums[left] + nums[right] > target) {
                        right--;
                    } else if (first + last + nums[left] + nums[right] < target) {
                        left++;
                    } else {
                        vector<int> v = {first, last, nums[left], nums[right]};
                        vvi.push_back(v);
                        while(nums[left] == nums[++left]){};
                        while(nums[right] == nums[--right]) {};
                    }
                }
                while(nums[j] == nums[--j]){};
            }
            while(nums[i] == nums[++i]);
        }
        return vvi;
    }
};