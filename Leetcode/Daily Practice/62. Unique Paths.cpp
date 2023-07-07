/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/


class Solution {
public:

 

    /*   APPRAOCH 1 : RECURSIVE 
    int countUniquePaths(int row, int col, int i , int j)
    {
        if(i == row-1 && j == col-1) return 1;
        if(i >= row || j >= col) return 0;


        return countUniquePaths(row, col, i+1, j) + countUniquePaths(row, col, i, j+1);
    }
    int uniquePaths(int m, int n) {
        return countUniquePaths(m, n, 0, 0);
    }
1. The time complexity of this code is exponential, specifically O(2^(n+m)), where n and m are the dimensions of the grid.

The countPaths function is a recursive function that calculates the number of unique paths from the top-left corner (0,0) to the bottom-right corner (n-1,m-1) of a grid.

In each recursive call, the function checks if it has reached the destination or has gone out of bounds. If it has reached the destination, it returns 1 to signify that a unique path has been found. If it has gone out of bounds, it returns 0 to signify that no valid path exists.

For each other case, the function recursively calls itself with two different positions: moving down by incrementing i and moving right by incrementing j. It then sums the results of these recursive calls, representing the total number of unique paths that can be found by moving down or right from the current position.

Since each recursive call branches into two new recursive calls, the number of function calls grows exponentially with the dimensions of the grid. Therefore, the time complexity is exponential.

2. The space complexity is O(n + m)

*/

//APPOACH 2 : USING DP
int countUniquePaths(int row, int col, int i , int j, vector<vector<int>> &dp)
    {
        if(i == row-1 && j == col-1) return 1;
        if(i >= row || j >= col) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] =  countUniquePaths(row, col, i+1, j, dp) + countUniquePaths(row, col, i, j+1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countUniquePaths(m, n, 0, 0, dp);
    }

    /*Since each position in the grid is visited once and its result is stored in the dp matrix, the time complexity is O(m * n). Similarly, the space complexity is also O(m * n) to store the results in the dp matrix.
*/
};
