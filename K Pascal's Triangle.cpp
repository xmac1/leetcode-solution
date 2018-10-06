// 杨辉三角的第 n 行 就包含 n 个元素，因此可以初始化含有 n 个元素的 vector
// 杨辉三角的上一行总是小于它的下一行，因此用一个 n 个元素的临时 vector 存储上一行的元素
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> line(rowIndex+1);
        vector<int> lastLine(line);
        for (int i = 0; i < rowIndex + 1; i++) {
            lastLine.insert(lastLine.begin(), line.begin(), line.end());
            for (int j = 0; j <= i; j++) {
                if (i == 0 || j == i) {
                    line[i] = 1;
                  } else {
                    int tmp = lastLine[j] + lastLine[j-1];
                    line[j] = tmp;
                 }
            }
        }
        return line;
    }
};