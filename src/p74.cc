/*
 * p74.cc
 *
 *  Created on: 2018年9月13日
 *      Author: jun
 */

/**
 * 74. Search a 2D Matrix
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 Example 1:

 Input:
 matrix = [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 target = 3
 Output: true
 Example 2:

 Input:
 matrix = [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 target = 13
 Output: false
 */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

namespace p74 {

// time complexity O(log(m*n)), space complexity O(1)
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		int m = matrix.size();
		int n = matrix[0].size();

		int first = 0;
		int last = m * n;
		while (first < last) {
			int mid = first + (last - first) / 2;
			int val = matrix[mid / n][mid % n];
			if (target == val) {
				return true;
			} else if (target < val) {
				last = mid;
			} else {
				first = mid + 1;
			}
		}
		return false;
	}
};

// time complexity O(max(m, logn)), space complexity O(m)
class Solution2 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		int m = matrix.size();
		int n = matrix[0].size();

		int tmp[m];
		for (int i = 0; i < m; ++i) {
			tmp[i] = matrix[i][0];
		}
		int row_pos = (upper_bound(tmp, tmp + m, target) - tmp) - 1;
		if (row_pos < 0) {
			return false;
		}
		auto b = begin(matrix[row_pos]);
		auto e = end(matrix[row_pos]);
		auto col_iter = lower_bound(b, e, target);
		if (col_iter == e)
			return false;
		return matrix[row_pos][col_iter - b] == target;
	}
};

// time complexity O(log(max(m, n))), space complexity O(1)
class Solution3 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		int m = matrix.size();
		int n = matrix[0].size();

		// upper bound search along first column
		// time complexity O(logm)
		int first = 0;
		int last = m;
		while (first != last) {
			int mid = first + (last - first) / 2;
			if (target == matrix[mid][0]) {
				return true;
			} else if (target > matrix[mid][0]) {
				first = mid + 1;
			} else {
				last = mid;
			}
		}
		int row_pos = first - 1;
//		cout << "row_pos: " << row_pos << endl;
		if (row_pos < 0)
			return false;

		// O(logn)
		auto b = matrix[row_pos].begin();
		auto e = matrix[row_pos].end();
		auto col_iter = lower_bound(b, e, target);
		return (col_iter != e) && (target == *col_iter);
	}
};
}

namespace p74_test {
TEST(TestP74, Solution) {
	vector<vector<int>> matrix
	{
		{ 1, 3, 5, 7 },
		{ 10, 11, 16, 20 },
		{ 23, 30,34, 50 }
	};
	p74::Solution3 solution;

	EXPECT_TRUE(solution.searchMatrix(matrix, 1));
	EXPECT_TRUE(solution.searchMatrix(matrix, 3));
	EXPECT_FALSE(solution.searchMatrix(matrix, 13));
	EXPECT_FALSE(solution.searchMatrix(matrix, 55));



}
}

