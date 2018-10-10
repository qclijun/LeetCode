/*
 * p85.cc
 *
 *  Created on: 2018年10月4日
 *      Author: jun
 */

/**
 * 85. Maximal Rectangle
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
 */

#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using std::vector;
using std::min;
using std::max;

// time complexity O(n^2), space complexity O(n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if(matrix.empty()) return 0;
    	const int m = matrix.size();
    	const int n = matrix[0].size();

    	// L(i), R(i), H(i) 表示从第一行到当前行的范围内， 第i列元素
    	// 所在的矩形区域的左端点，右端点及高度。
    	vector<int> L(n, 0);
    	vector<int> R(n, n);
    	vector<int> H(n, 0);

    	int ret = 0;
    	// 按行更新
    	for(int i = 0; i < m; ++i){

    		// 按列从左至右更新
    		int left = 0;
    		for(int j = 0; j < n; ++j){
    			if(matrix[i][j] == '1'){
    				++H[j];
    				L[j] = max(L[j], left);
    			}else{
    				left = j + 1;
    				L[j] = 0;
    				H[j] = 0;
    				R[j] = n;
    			}
    		}
    		// 按列从右至左更新R
    		int right = n;
    		for(int j = n-1; j >= 0; --j){
    			if(matrix[i][j] == '1'){
    				R[j] = min(R[j], right);
    				ret = max(ret, H[j] * (R[j] - L[j]));
    			}else{
    				right = j;
    			}
    		}
    	}
    	return ret;

    }
};

TEST(TestP85, Solution){
	Solution sln;
	vector<vector<char>> matrix {
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}
	};

	EXPECT_EQ(6, sln.maximalRectangle(matrix));
}

