
class Solution {
public:
    std::vector<std::vector<int>> modifiedMatrix(std::vector<std::vector<int>>& matrix) {
        std::vector<int> v(matrix[0].size(), 0);
        std::vector<std::vector<int>> a;

        for (int i = 0; i < matrix[0].size(); i++) {
            int max = 0;
            for (int j = 0; j < matrix.size(); j++) {
                if (matrix[j][i] == -1) {
                    std::vector<int> c = {j, i};
                    a.push_back(c);
                }
                if (matrix[j][i] > max) {
                    max = matrix[j][i];
                }
            }
            v[i] += max;
        }

        for (int i = 0; i < a.size(); i++) {
            int x = a[i][1];
            int y = a[i][0];
            matrix[y][x] = v[x];
        }

        return matrix;
    }
};
