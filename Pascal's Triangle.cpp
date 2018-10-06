// 生成杨辉三角
// 注意到下一层的数和上一层数之间的关系即可
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            vector<int> line;
            for (int j = 0; j <= i; j++) {
                if (j ==0 || j == i) {
                    line.push_back(1);
                } else {
                    line.push_back(triangle.at(i-1).at(j-1)+triangle.at(i-1).at(j));
                }
            }
            triangle.push_back(line);
        }
        return triangle;
    }
};