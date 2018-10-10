/*
 * p45.cc
 *
 *  Created on: 2018年9月30日
 *      Author: jun
 */

/**
 * 45. Jump Game II
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
 */

#include <vector>
#include "gtest/gtest.h"
using namespace std;

// time complexity O(n), space complexity O(1)
class Solution2 {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
    	int step = 0;
        int left = 0;
        int right = 0;
        while(left <= right){
        	++step;
        	const int old_right = right;
        	for(int i=left, left=old_right + 1; i <= old_right; ++i){
        		right = max(right, i + nums[i]);
        		if(right >= nums.size() - 1) return step;
        	}

        }
        return 0;
    }
};

class Solution {
public:
	int jump(vector<int>& nums){
		int result = 0;
		int last = 0;
		int cur = 0;

		for(int i = 0; i < nums.size(); ++i){
			if(i > last){
				last = cur;
				++result;
			}
			cur = max(cur, i + nums[i]);
		}
		return result;
	}
};

TEST(TestP45, Solution){
	vector<int> nums {2, 3, 1, 1, 4};
	Solution sln;
	EXPECT_EQ(2, sln.jump(nums));
}
