/*
 * p97.cc
 *
 *  Created on: 2018年10月5日
 *      Author: jun
 */

/**
 * 97. Interleaving String
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"

using std::string;
using std::vector;

// 二维动态规划
// time complexity O(n^2), space complexity O(n^2)
class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;

        // f[i][j]表示子串s1[0, i)，s2[0, j)是否匹配s3[0, i+j)
        vector<vector<bool>> f(s1.size() + 1, vector<bool>(s2.size() + 1, true));

        // 初始化
        for(int i = 1; i <= s1.size(); ++i){
        	f[i][0] = f[i-1][0] && s1[i-1] == s3[i-1];
        }
        for(int j = 1; j <= s2.size(); ++j){
        	f[0][j] = f[0][j-1] && s2[j-1] == s3[j-1];
        }

        for(int i = 1; i <= s1.size(); ++i){
        	for(int j = 1; j <= s2.size(); ++j){
        		f[i][j] = (s1[i-1] == s3[i+j-1] && f[i-1][j]) ||
        				(s2[j-1] == s3[i+j-1] && f[i][j-1]);
        	}
        }
        return f[s1.size()][s2.size()];
    }
};

// 动态规划， 滚动数组
// time complexity O(n^2), space complexity O(n)
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3){
		if(s1.size() + s2.size() != s3.size()) return false;

		vector<bool> f(s2.size() + 1, true);
		for(int j = 1; j <= s2.size(); ++j){
			f[j] = f[j-1] && s2[j-1] == s3[j-1];
		}

		for(int i = 1; i <= s1.size(); ++i){
			f[0] = f[0] && (s1[i-1] == s3[i-1]);
			for(int j = 1; j <= s2.size(); ++j){
				f[j] = (s1[i-1] == s3[i+j-1] && f[j]) ||
						(s2[j-1] == s3[i+j-1] && f[j-1]);
			}
		}
		return f[s2.size()];
	}

};

TEST(TestP97, Solution){
	Solution sln;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";

	EXPECT_TRUE(sln.isInterleave(s1, s2, s3));

	s3 = "aadbbbaccc";
	EXPECT_FALSE(sln.isInterleave(s1, s2, s3));
}

