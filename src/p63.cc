/*
 * p63.cc
 *
 *  Created on: 2018年9月25日
 *      Author: jun
 */

/**
 * 63. Unique Paths II
 *
 */

#include <vector>
#include "gtest/gtest.h"
using namespace std;

// time complexity O(m*n), space complexity O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if( n == 0) return 0;
        // 第一行
        vector<int> p(n, 1);
        for(int c = 0;c < n;++c){
        	if(obstacleGrid[0][c] == 1){
        		for(;c<n;++c){
        			p[c] = 0;
        		}
        	}
        }

        bool first_col_has_obstacle = false;

        for(int r=1;r<m;++r){
        	if(obstacleGrid[r][0] == 1){
        		first_col_has_obstacle = true;
        	}
        	if(first_col_has_obstacle){
        		p[0] = 0;
        	}
        	for(int c=1;c<n;++c){
        		if(obstacleGrid[r][c] == 1){
        			p[c] = 0;
        		}else{
        			p[c] = p[c] + p[c-1];
        		}
        	}
        }
        return p[n-1];

    }
};

TEST(TestP63, Solution){
	Solution sln;
	vector<vector<int>> obstacleGrid {
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0},
	};

	int paths = sln.uniquePathsWithObstacles(obstacleGrid);
	EXPECT_EQ(2, paths);

	obstacleGrid  = {
			{0},
			{1},
	};
	EXPECT_EQ(0, sln.uniquePathsWithObstacles(obstacleGrid));
}
