/*
 * p120.cc
 *
 *  Created on: 2018年10月3日
 *      Author: jun
 */

/**
 * 120. Triangle
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using std::vector;
using std::min;
using std::swap;

// time complexity O(depth^2), space complexity O(depth^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int depth = triangle.size();
        vector<vector<int>> buf(depth);

        buf[0].push_back(triangle[0][0]);
        for(int i = 1; i < depth; ++i){
        	// the first
        	buf[i].push_back(buf[i-1][0] + triangle[i][0]);
        	for(int j = 1; j < i; ++j){
        		int min_path = min(buf[i-1][j-1], buf[i-1][j]) + triangle[i][j];
        		buf[i].push_back(min_path);
        	}
        	// the last
        	buf[i].push_back(buf[i-1][i-1] + triangle[i][i]);

        }
        int result = buf[depth-1][0];
        for(int i = 1; i < depth; ++i){
        	result = min(result, buf[depth-1][i]);
        }
        return result;
    }
};

// time complexity O(n^2), space complexity O(n), n is depth
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int depth = triangle.size();

        vector<int> prev(depth);
        vector<int> curr(depth);

        prev[0] = triangle[0][0];
        for(int i = 1; i < depth; ++i){
        	// the first
        	curr[0] = prev[0] + triangle[i][0];
        	for(int j = 1; j < i; ++j){
        		curr[j] = min(prev[j-1], prev[j]) + triangle[i][j];
        	}
        	// the last
        	curr[i] = prev[i-1] + triangle[i][i];
        	swap(prev, curr);
        }
        int result = prev[0];
        for(int i = 1; i < depth; ++i){
        	result = min(result, prev[i]);
        }
        return result;
    }
};

TEST(TestP120, Solution){
	vector<vector<int>> triangle{
		{2},
		{3, 4},
		{6, 5, 2},
		{4, 1, 8, 3},
	};

	Solution2 sln;
	EXPECT_EQ(11, sln.minimumTotal(triangle));
}

