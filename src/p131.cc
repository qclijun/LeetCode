/*
 * p131.cc
 *
 *  Created on: 2018年9月24日
 *      Author: jun
 */


/**
 * 131. Palindrome Partitioning
 *
 Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
 */
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;

// time complexity O(2^n), space complexity O(n)
class Solution {
public:
	vector<vector<string>> partition(string s){
		vector<vector<string>> result;
		vector<string> path;
		partition(s, 0, path, result);
		return result;
	}

private:
	void partition(const string& s, int start, vector<string>& path, vector<vector<string>>& out){
		if(start == s.size()){
			out.push_back(path);
			return;
		}

		for(int i=start; i<s.size(); ++i){
			if(is_palindrome(s, start, i)){
				path.push_back(s.substr(start, i - start + 1));
				partition(s, i+1, path, out);
				path.pop_back();
			}
		}
	}

	bool is_palindrome(const string& s, int begin, int end){
		while(begin < end && s[begin] == s[end]){
			++begin;
			--end;
		}
		return begin >= end;
	}
};

// 动态规划
class Solution2{
public:
	vector<vector<string>> partition(string s){
		int n = s.size();
		bool p[n][n];
		fill_n(&p[0][0], n*n, false);
		for(int i=n-1; i>=0; --i){
			for(int j=i; j<n; ++j){
				p[i][j] = (s[i] == s[j]) && (j-i < 2 || p[i+1][j-1]);
			}
		}
		vector<vector<string>> sub_palins[n];
		for(int i=n-1;i>=0;--i){
			for(int j=i;j<n;++j){
				if(p[i][j]){
					string palindrome = s.substr(i, j-i+1);
					if(j==n-1){
						sub_palins[i].push_back(vector<string>{palindrome});
					}else{
						for(vector<string> v : sub_palins[j+1]){
							v.insert(v.begin(), palindrome);
							sub_palins[i].push_back(v);
						}
					}
				}
			}
		}
		return sub_palins[0];
	}
};

TEST(TestP131, Solution){
	Solution2 sln;
	string s = "aab";
	vector<vector<string>> result = sln.partition(s);
	set<vector<string>> expect = {
			{"aa", "b"},
			{"a", "a", "b"},
	};
	set<vector<string>> result_set {result.begin(), result.end()};
	EXPECT_EQ(expect, result_set);
}

