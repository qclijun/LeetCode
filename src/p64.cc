/*
 * p64.cc
 *
 *  Created on: 2018年10月5日
 *      Author: jun
 */

/**
 * 64. Minimum Path Sum
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */
#include <iostream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using std::vector;
using std::min;

// 动态规划， 滚动数组
// time complexity O(n^2), space complexity O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int m = grid.size();
    	if(m == 0) return 0;
    	int n = grid[0].size();
    	if(n == 0) return 0;

    	// f[i][j] 表示从左上角元素到(i,j)位置的最小路径和
    	// f[i][j] = min{f[i-1][j], f[i][j-1]} + grid[i][j]
        vector<int> f(n, 0);
        f[0] = grid[0][0];
        for(int col = 1; col < n; ++col){
        	f[col] = f[col-1] + grid[0][col];
        }

        for(int row = 1; row < m; ++row){
        	f[0] = f[0] + grid[row][0];
        	for(int col = 1; col < n; ++col){
        		f[col] = min(f[col], f[col-1]) + grid[row][col];
        	}
        }
        return f[n-1];

    }
};

TEST(TestP64, Solution){
	Solution sln;
//	vector<vector<int>> grid{
//		{1, 3, 1},
//		{1, 5, 1},
//		{4, 2, 1}
//	};
	vector<vector<int>> grid {
		{7,0,8,8,0,3,5,8,5,4},
		{4,1,2,9,9,6,0,8,6,9},
		{9,7,1,1,0,1,2,4,1,7}
	};
//	[[7,0,8,8,0,3,5,8,5,4],[4,1,2,9,9,6,0,8,6,9],[9,7,1,1,0,1,2,4,1,7]]

//	EXPECT_EQ(7, sln.minPathSum(grid));
	std::cout << sln.minPathSum(grid) << std::endl;


}

