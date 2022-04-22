//只能向右或下走，根据已知最短结点，慢慢推出新的最短结点。最后matrix就是从(0, 0)到(i, j)所需的最短花费


class Solution {
  public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */

    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        int maxrow = matrix.size(), maxcol = matrix.front().size();

        for (int row = 0; row < maxrow; ++row) {
            bool hasup = row >= 1;
            for (int col = 0; col < maxcol; ++col) {
                bool hasleft = col >= 1;

                if (hasleft && hasup) {
                    matrix[row][col] += min(matrix[row][col - 1], matrix[row - 1][col]);
                } else if (hasleft && !hasup) {
                    matrix[row][col] += matrix[row][col - 1];
                } else if (hasup && !hasleft) {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }
        }
        return matrix[maxrow - 1][maxcol - 1];
    }
};