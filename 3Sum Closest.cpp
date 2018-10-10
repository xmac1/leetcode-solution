class Solution {
public:
    vector<int> threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT32_MAX;
        int left, right, mid;
        int size = nums.size();
        vector<int> arr;

        for (int i = 0; i < size - 1; i++) {
            if (nums[i] >= 0 && nums[i] + nums[size-1] > target) {
                left = i;
                mid = left + 1;
                right = mid + 1;
                arr = {nums[left], nums[right], nums[mid]};
                return arr;
            }

            int l = i + 1;
            int r = size - 1;

            while(r > l) {
                int tmp = nums[i] + nums[r] + nums[l] - target;
                if (tmp == 0) {
                    left = i;
                    right = r;
                    mid = l;
                    arr = {nums[left], nums[right], nums[mid]};
                    return arr;
                }

                diff = (diff < tmp)?diff:tmp;

                if (tmp > 0) {
                    l++;
                } else {
                    r--;
                }
            }

        }

        return
    }
};