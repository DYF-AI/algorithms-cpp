
#include <iostream>
#include <string>
#include <vector>

namespace dynamic_programming{
    template <typename T>
    int minPathSum(std::vector<std::vector<T>> &grid){
        int row = grid.size();
        int col = grid[0].size();

        // 存储每个位置的最优解
        std::vector<std::vector<T>> dp(row, std::vector<T>(col, 0));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < col; i++){
            // 前一列的最优解加上该列的值
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < row; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][col - 1];
    }
}

void test01(){
    std::vector<std::vector<int>> grid = {{1, 2, 3, 4}, {2, 4, 1, 5}, {4, 2, 4, 1}};
    int min_s = dynamic_programming::minPathSum(grid);
    std::cout << "min path sum = " << min_s << std::endl;
}

int main(){
    test01();
    return 0;
}
