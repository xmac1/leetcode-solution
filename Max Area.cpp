class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        vector<int> minHeight(len);
        int left, right;
        int maxSum = 0;

        for (int i = 0; i < len; i++) {
            
            for (int j = i+1; j < len; j++) {
                int width = j - i;
                if (height.at(i) <= minHeight.at(width)) {
                    break;
                }
                minHeight[width] = min(height.at(i), height.at(j));
                
                if (width*minHeight.at(width) > maxSum) {
                    maxSum = width*minHeight.at(width);
                }
            }
        }
        return maxSum;
    }
};