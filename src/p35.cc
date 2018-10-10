/*
 * p35.cc
 *
 *  Created on: 2018年9月13日
 *      Author: jun
 */
#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 35. Search Insert Position
 *
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
 */

namespace p35{

// time complexity O(logn), space complexity O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return distance(begin(nums), lower_bound(begin(nums), end(nums), target));
    }

private:
    template<typename ForwardIter, typename T>
    ForwardIter lower_bound(ForwardIter first, ForwardIter last, T val){
    	while(first != last){
    		auto mid = next(first, distance(first, last) / 2);
    		if(val > *mid){
    			first = next(mid);
    		}else{
    			last = mid;
    		}
    	}
    	return first;
    }
};
}

namespace p35_test{
TEST(TestP35, Solution){
	vector<int> nums{1, 3, 5, 6};
	p35::Solution solution;

	EXPECT_EQ(2, solution.searchInsert(nums, 5));
	EXPECT_EQ(1, solution.searchInsert(nums, 2));
	EXPECT_EQ(4, solution.searchInsert(nums, 7));
	EXPECT_EQ(0, solution.searchInsert(nums, 0));
}
}
