/*
 * p62.cc
 *
 *  Created on: 2018年9月24日
 *      Author: jun
 */

/**
 * 62. Unique Paths
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 */

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"


using namespace std;

// time complexity O(min(m,n)), space complexity O(1)
// 数学法， 组合数(m-1+n-1中选出m-1)
class Solution {
public:
	int uniquePaths(int m, int n){
		if(m < n) return uniquePaths(n, m);
		--m;
		--n;
		int k = m + n;
		uint64_t s = 1;
		for(int i = 1; i <= n; ++i){
			s *= k - i + 1;
		}
		for(int i = 1; i <= n; ++i){
			s /= i;
		}
		return static_cast<int>(s);
	}
};

// 动态规划
// time complexity O(m*n), space complexity O(m*n)
class Solution2 {

public:
	int uniquePaths(int m, int n){
		// 表示从(0,0)到(i,j)的路径条数
		int** f = new int*[m];
		for(int r = 0; r < m; ++r){
			f[r] = new int[n];
		}
		// 第一行全为1
		for(int c = 0; c < n; ++c){
			f[0][c] = 1;
		}
		// 第一列全为1
		for(int r = 0; r < m; ++r){
			f[r][0] = 1;
		}

		for(int r = 1; r < m; ++r){
			for(int c = 1; c < n; ++c){
				f[r][c] = f[r-1][c] + f[r][c-1];
			}
		}
		int result = f[m-1][n-1];


		for(int r=0; r<m; ++r){
			delete[] f[r];
 		}
		delete[] f;
		return result;
	}
};

// 动态规划, 滚动数组, 把Solution2的矩阵压缩成数组
// time complexity O(m*n), space complexity O(n)
class Solution3 {

public:
	int uniquePaths(int m, int n){
		// 表示从(0,0)到(i,j)的路径条数
		vector<int> f(n, 1);

		// 按行更新
		for(int r = 1; r < m; ++r){
			for(int c = 1; c < n; ++c){
				f[c] = f[c] + f[c-1]; // 等式右边的f[c]表示上一行的f[c], 即f[r-1][c]
			}
		}
		return f[n-1];

	}
};

TEST(TestP62, Solution){
	Solution3 sln;
	int m = 7, n = 3;
	EXPECT_EQ(28, sln.uniquePaths(m, n));

	m = 10;
	n = 10;
	EXPECT_EQ(48620, sln.uniquePaths(m, n));
}


