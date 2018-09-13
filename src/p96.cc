/*
 * p96.cc
 *
 *  Created on: 2018年9月2日
 *      Author: jun
 */

/**
 * 96. Unique Binary Search Trees
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */

#include "gtest/gtest.h"
#include <vector>

using namespace std;

namespace p96{

// 动态规划，时间复杂度O(n^2), 空间复杂度O(n)
class Solution {
public:
    int numTrees(int n) {
    	vector<int> f(n+1, 0);
    	f[0] = 1;
    	f[1] = 1;
    	for(int i=2;i<=n;++i){
    		for(int k=1;k<=i;++k){
    			f[i] += f[k-1] * f[i - k];
    		}
    	}
    	return f[n];
    }
};
}

namespace p96_test{
TEST(TestP96, Solution){
	p96::Solution solution;

	EXPECT_EQ(2, solution.numTrees(2));
	EXPECT_EQ(5, solution.numTrees(3));
}
}

