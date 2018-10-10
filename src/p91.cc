/*
 * p91.cc
 *
 *  Created on: 2018年10月6日
 *      Author: jun
 */

/**
 * 91. Decode Ways
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6)
 */

#include <string>

#include "gtest/gtest.h"

using std::string;

class Solution {
public:
    int numDecodings(string s) {
    	if(s.empty() || s[0] == '0') return 0;
    	int prev = 0;
    	int cur = 1;
    	for (size_t i = 1; i <= s.size(); ++i){
    		if(s[i-1] == '0') cur = 0;
    		if(i < 2 || !(s[i-2] == '1' ||
    				(s[i-2] == '2' && s[i-1] <= '6')))
    			prev = 0;
    		int tmp = cur;
    		cur += prev;
    		prev = tmp;
    	}
    	return cur;
    }
};

TEST(TestP91, Solution){
	Solution sln;

	EXPECT_EQ(2, sln.numDecodings("12"));
	EXPECT_EQ(3, sln.numDecodings("226"));
	EXPECT_EQ(2, sln.numDecodings("1026"));
}

