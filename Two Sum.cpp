// 使用 map 保存数组中的值和下标
// 遍历数组，每次都计算目标值与当前元素的差值，
// 在 map 中查找这个差值，如果找到这说明满足条件。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator iter;
        vector<int> returnVector;
        int i = 0;
        
        map<int, int> m;
        map<int, int>::iterator keyIter;
        for (iter = nums.begin(); iter != nums.end(); iter++) {
            int value = *iter;
            int left = target - value;
            keyIter = m.find(left);
            if (keyIter == m.end()) {
                m.insert(map<int, int>::value_type(value, i));
                i++;
                continue;
            } else {
                returnVector.push_back(keyIter->second);
                returnVector.push_back(i);
                return returnVector;
            }
        }

        return returnVector;
    }
};