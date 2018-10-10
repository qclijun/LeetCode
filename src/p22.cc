/*
 * p22.cc
 *
 *  Created on: 2018年9月27日
 *      Author: jun
 */

#include <string>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> result;
    	if(n<=0) return result;
    	backtrack(0, 0, n, "", result);
    	return result;
    }

private:
    void backtrack(int open, int close, int max, const string& s, vector<string>& out){
    	if(s.size() == max * 2){
    		out.push_back(s);
    		return;
    	}
    	if(open < max){
    		backtrack(open + 1, close, max, s + "(", out);
    	}
    	if(close < open){
    		backtrack(open, close + 1, max, s + ")", out);
    	}
    }

    bool is_series(const string& s){
    	for(int i=0; i<s.size()-1;++i){
    		if(s[i] == s[i+1]) return false;
    	}
    	return true;
    }
};

TEST(TestP22, Solution){
	Solution sln;
	vector<string> result = sln.generateParenthesis(4);
	testing::internal::UniversalPrint(result, &cout);
	cout << endl;
}
