/*
 * p72.cc
 *
 *  Created on: 2018年10月5日
 *      Author: jun
 */

/**
 * 72. Edit Distance
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 */

#include <string>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using std::string;
using std::vector;
using std::min;

// 动态规划
// time complexity O(n^2), space complexity O(n^2)
class Solution {
public:
    int minDistance(string word1, string word2) {
    	int len1 = word1.size();
    	int len2 = word2.size();

    	// f[i][j] 表示word1[0, i), word2[0, j)之间最小编辑距离 0<=i<=len1, 0<=j<=len2
    	vector<vector<int>> f(len1+1, vector<int>(len2+1));

    	// 初始化第一行，第一列
    	for(int i = 0; i <= len1; ++i){
    		f[i][0] = i;
    	}
    	for(int j = 0; j <= len2; ++j){
    		f[0][j] = j;
    	}
    	for(int i = 1; i <= len1; ++i){
    		for(int j = 1; j <= len2; ++j){
    			if(word1[i-1] == word2[j-1]){
    				f[i][j] = f[i-1][j-1];
    			}else{
    				// 1. 在f[i-1][j-1]基础上执行replace, f[i][j] = f[i-1][j-1] + 1
    				// 2. 在f[i-1][j]基础上执行delete, f[i][j] = f[i-1][j] + 1
    				// 3. 在f[i][j-1]基础上执行insert, f[i][j] = f[i][j-1] + 1
    				f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1;
    			}
    		}
    	}
    	return f[len1][len2];
    }
};

TEST(TestP72, Solution){
	Solution sln;
	string word1 = "horse";
	string word2 = "ros";
	EXPECT_EQ(3, sln.minDistance(word1, word2));

	word1 = "intention";
	word2 = "execution";
	EXPECT_EQ(5, sln.minDistance(word1, word2));
}

