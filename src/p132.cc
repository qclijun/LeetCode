/*
 * p132.cc
 *
 *  Created on: 2018年10月4日
 *      Author: jun
 */

/**
 * 132. Palindrome Partitioning II
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */

#include <string>
#include <algorithm>

#include "gtest/gtest.h"

using std::string;
using std::fill_n;
using std::min;

// time complexity O(n^2), space complexity O(n^2)
class Solution {
public:
    int minCut(string s) {
        const int n = s.size();

        // p[i][j]表示子串[i,j]是否是回文
        bool p[n][n];
        fill_n(&p[0][0], n * n, false);

        // f[i]表示子串[i, n-1]的最小cut数
        int f[n+1];
        // 初始化为最坏的情况，即每个字符都需要分割
        // f[n]=-1， 为特殊情况
        for(int i = 0; i <= n; ++i){
        	f[i] = n - 1 - i;
        }

        // DP, 从右到左构建
        for(int i = n - 1; i >= 0; --i){
        	for(int j = i; j < n; ++j){
        		// 如果[i, j]是回文，则更新f
        		if(s[i] == s[j] && (j - i < 2 || p[i+1][j-1])){
        			p[i][j] = true;
        			f[i] = min(f[i], f[j+1] + 1);
        		}
        	}
        }
        return f[0];
    }
};

TEST(TestP132, Solution){
	Solution sln;
	string s = "aab";
	EXPECT_EQ(1, sln.minCut(s));
}

