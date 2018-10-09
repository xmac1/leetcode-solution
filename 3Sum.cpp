class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> arrs;

        map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]]++;
        }

        map<int, int>::iterator left = numMap.begin();
        map<int, int>::reverse_iterator right;

        for(;left != numMap.end() && left->first < 0;left++) {
            for (right = numMap.rbegin(); right != numMap.rend() && right -> first > 0; right++) {
                int target = 0 - (left -> first + right -> first);

                map<int, int>::iterator pair = numMap.find(target);
                if (pair != numMap.end()) {
                    if (abs(pair->first) > min(abs(left->first), abs(right->first))) {
                        continue;
                    }

                    if (pair->first == left->first && left->second < 2) {
                        continue;
                    }

                    if (pair->first == right->first && right->second < 2) {
                        continue;
                    }

                    vector<int> arr = {left->first, right->first, pair->first};
                    arrs.push_back(arr);
                }
            }
        }
        if (numMap[0] >= 3) {
                arrs.push_back({0,0,0});
        }
        return arrs;
    }
};