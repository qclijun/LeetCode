/*
 * p78.cc
 *
 *  Created on: 2018年9月14日
 *      Author: jun
 */

/**
 * 78. Subsets
 *
 * Given a set of distinct integers, nums, return all possible subsets (the power set).

 Note: The solution set must not contain duplicate subsets.

 Example:

 Input: nums = [1,2,3]
 Output:
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
 */

#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace p78 {
// time complexity 2^n, space complexity O(1)
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		subsets0(nums.begin(), nums.end(), result);
		return result;
	}
private:
	void subsets0(vector<int>::iterator b, vector<int>::iterator e,
			vector<vector<int>>& out) {
		if (b == e) {
			out.push_back( { });
			return;
		}
		e = prev(e);
		subsets0(b, e, out);
		int sz = out.size();

		for (int i = 0; i < sz; ++i) {
			out.push_back(out[i]);
		}
		for(int i = sz; i < out.size(); ++i){
			out[i].push_back(*e);
		}
	}
};

//class Solution2{
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int>> result;
//
//	}
//};
}

namespace p78_test {
TEST(TestP78, Solution) {
	vector<int> nums { 1, 2, 3 };
	p78::Solution solution;
	vector<vector<int>> result = solution.subsets(nums);

	for (int i = 0; i < result.size(); ++i) {
		testing::internal::UniversalPrint(result[i], &cout);
	}
}
}

