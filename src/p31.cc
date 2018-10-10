/*
 * p31.cc
 *
 *  Created on: 2018年9月18日
 *      Author: jun
 */

/**
 * 31. Next Permutation
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 */

#include "gtest/gtest.h"

#include <vector>
#include <algorithm>
using namespace std;

namespace p31{
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }

private:
    template<typename BidirIt>
    bool next_permutation(BidirIt first, BidirIt last){
    	if (first == last) return false;
    	BidirIt i = last;
    	if (first == --i) return false;

    	while(true){
    		BidirIt i1 = i;
    		BidirIt i2;
    		if(*--i < *i1){
    			i2 = last;
    			while(!(*i < *--i2)) {}
    			std::iter_swap(i, i2);
    			std::reverse(i1, last);
    			return true;
    		}
    		if (i == first){
    			std::reverse(first, last);
    			return false;
    		}
    	}
    }
};
}

namespace p31_test{
	TEST(TestP32, Solution){
		p31::Solution solution;

		vector<int> nums {1, 2, 3};
		vector<int> expect {1, 3, 2};
		solution.nextPermutation(nums);
		EXPECT_EQ(expect, nums);

		nums = {3, 2, 1};
		expect = {1, 2, 3};
		solution.nextPermutation(nums);
		EXPECT_EQ(expect, nums);

		nums = {1, 1, 5};
		expect = {1, 5, 1};
		solution.nextPermutation(nums);
		EXPECT_EQ(expect, nums);
	}
}


