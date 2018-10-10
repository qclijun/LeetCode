/*
 * p40.cc
 *
 *  Created on: 2018年9月26日
 *      Author: jun
 */

#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, path, result);
        return result;
    }

private:
    void dfs(vector<int>& candidates, int start, int target, vector<int>& path, vector<vector<int>>& result){
    	if(target == 0){
    		result.push_back(path);
    		return;
    	}
    	int previous = -1;
    	for(int i=start; i<candidates.size(); ++i){
    		if(previous == candidates[i]) continue;
    		if(target < candidates[i]) return;
    		previous = candidates[i];
    		// 选中i
    		path.push_back(candidates[i]);
    		dfs(candidates, i+1, target - candidates[i], path, result);

    		// 不选中i
    		path.pop_back();
    	}
    }
};

TEST(TestP40, Solution){
	Solution sln;
	vector<int> candidates {10,1,2,7,6,1,5};
	int target = 8;
	vector<vector<int>> result = sln.combinationSum2(candidates, target);
	testing::internal::UniversalPrint(result, &cout);
	cout << endl;
}
