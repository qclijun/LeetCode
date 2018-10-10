/*
 * p115.cc
 *
 *  Created on: 2018年10月6日
 *      Author: jun
 */

/**
 * 115. Distinct Subsequences
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"

using std::string;
using std::vector;

// time complexity O(n^2), space complexity O(n)
class Solution {
public:
    int numDistinct(string s, string t) {
    	vector<int> f(t.size() + 1, 0);
    	f[0] = 1;

    	for(int i = 0; i < s.size(); ++i){
    		for(int j = t.size()-1; j >= 0; --j){
    			if(s[i] == t[j]) {
    				f[j+1] += f[j];
    			}
    		}
    	}
    	return f[t.size()];
    }
};

TEST(TestP115, Solution){
	Solution sln;
	string s = "rabbbit";
	string t = "rabbit";

	EXPECT_EQ(3, sln.numDistinct(s, t));

}
