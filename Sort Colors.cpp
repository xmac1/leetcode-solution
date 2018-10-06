// 大体思路：知道数组中不同元素排序后的位置，只需要把蓝色元素交换到元素末尾即可
class Solution {
public:
    void sortColors(vector<int>& nums) {
        size_t size = nums.size();
        int blueIdx =  0;
        int whiteIdx = 0;
        for (int i = 0; i < size;) {
            if (nums[i] == 0) {
                i++;
                continue;
            }

            if (nums[i] == 2) {
                if (i == size - blueIdx) {
                    break;
                }
                
                blueIdx++;
                int tmp = nums[i];
                nums[i] = nums[size - blueIdx];
                if (nums[i] == 1 && whiteIdx > 0) {
                    whiteIdx--;
                }
                nums[size-blueIdx] = tmp;
                
                
                continue;
            }

            if (i == size - blueIdx - whiteIdx) {
                break;
            }
            whiteIdx++;
            int tmp = nums[i];
            nums[i] = nums[size - blueIdx - whiteIdx];
            nums[size - blueIdx-  whiteIdx] = tmp;
            
        }
    }
};