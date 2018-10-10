/*
 * p52.cc
 *
 *  Created on: 2018年9月25日
 *      Author: jun
 */

#include <vector>
#include <cstdlib>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> C(n, -1);
        int cnt = 0;
        dfs(C, 0, cnt);
        return cnt;
    }

private:
    void dfs(vector<int>& C, int row, int& cnt){
    	if(row == C.size()){
    		++cnt;
    		return;
    	}

    	for(int col=0;col<C.size();++col){
    		C[row] = col;
    		if(!is_valid(C, row, col)) continue;
    		dfs(C, row + 1, cnt);
    	}
    }

    bool is_valid(const vector<int>& C, int row, int col){
    	for(int r=0;r<row;++r){
    		if(col == C[r]) return false;
    		if(abs(r-row) == abs(C[r]-col)) return false;
    	}
    	return true;
    }
};

TEST(TestP52, Solution){
	Solution sln;
	EXPECT_EQ(2, sln.totalNQueens(4));
}

