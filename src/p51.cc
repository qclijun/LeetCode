/*
 * p51.cc
 *
 *  Created on: 2018年9月25日
 *      Author: jun
 */

#include <string>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

// time complexity O(n!*n), 空间复杂度 O(n)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> C(n, -1);
        vector<vector<string>> result;
        dfs(C, 0, result);
        return result;
    }

private:


    void dfs(vector<int>& C, int row, vector<vector<string>>& result){
    	int n = C.size();
    	if(row == n){
    		vector<string> one_result;
    		for(int i=0;i<row;++i){
    			string s(n, '.');
    			s[C[i]] = 'Q';
    			one_result.push_back(s);
    		}
    		result.push_back(one_result);
    		return;
    	}
    	for(int col=0;col<n;++col){
    		C[row] = col;
    		if(!is_valid(C, row, col)) continue;
    		dfs(C, row + 1, result);
    	}

    }

    bool is_valid(vector<int>& C, int row, int col){
    	for(int i=0;i<row;++i){
    		if(C[i] == col) return false;
    		if(abs(i-row) == abs(C[i]-col)) return false;
    	}
    	return true;
    }
};

TEST(TestP51, Solution){
	Solution sln;
	vector<vector<string>> result = sln.solveNQueens(4);
	testing::internal::UniversalPrint(result, &cout);
	cout << endl;
}
