/*
 * p53.cc
 *
 *  Created on: 2018年10月3日
 *      Author: jun
 */

/**
 * 53. Maimum Subarray
 *
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <vector>
#include <algorithm>
#include <numeric>

#include "gtest/gtest.h"

using std::vector;
using std::max;
using std::numeric_limits;

// time complexity O(n), space complexity O(1)
// 动态规划，f[i]表示以i结束的最大连续子段的和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = numeric_limits<int>::min();
        int f = 0;
        for(int i = 0; i < nums.size(); ++i){
        	f = max(nums[i], f + nums[i]);
        	result = max(result, f);
        }
        return result;
    }
};


TEST(TestP53, Solution){
	vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
	Solution sln;
	EXPECT_EQ(6, sln.maxSubArray(nums));
}
