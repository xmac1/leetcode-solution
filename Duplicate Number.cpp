class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sum = 0;
        int total = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it ++) {
            total += *it;
        }

        sum = nums.size() * (nums.size() + 1) / 2;

        int diff = total - sum;

        
    }
};