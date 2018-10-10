class Solution {
public:
    vector<vector<int>> threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0, j = nums.size() - 1; i < j; ) {
            if (nums[j] + nums[i] > target) {
                j--;
            }
        }
    }
};