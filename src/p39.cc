/*
 * p39.cc
 *
 *  Created on: 2018年9月26日
 *      Author: jun
 */

/**
 * 39.Combination Sum
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
 *
 * Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
 *
 */

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        //sort(candidates.begin(), candidates.end());
        dfs(candidates, candidates.size(), target, path, result);
        return result;
    }

private:
    void dfs(vector<int>& candidates, int sz, int target, vector<int>& path, vector<vector<int>>& out){
    	if(target == 0){
    		out.push_back(path);
    		return;
    	}
    	int min = candidates[0];
    	if(sz == 1){
    		if(target % min == 0){

    			for(int i=0;i<target/min;++i){
    				path.push_back(min);
    			}
    			out.push_back(path);

    			// 恢复path
    			for(int i=0;i<target/min;++i){
    				path.pop_back();
    			}
    		}
    		return;
    	}

    	// 包含[0, target/a]个最后一个元素
    	int a = candidates[sz - 1];
    	for(int i=0; i<=target/a; ++i){
    		// 包含i个a, target减少
    		int new_target = target - i * a;

    		// path增加
    		for(int j=0;j<i;++j){
    			path.push_back(a);
    		}

    		cout << "include " << i << "*" << a << endl;
    		cout << "target: " << new_target << endl;
    		cout << "path: ";
    		testing::internal::UniversalPrint(path, &cout);
    		cout << endl;

    		// 递归
    		dfs(candidates, sz - 1, new_target, path, out);

    		// 恢复path
    		for(int j=0;j<i;++j){
    			path.pop_back();
    		}
    	}
    }
};

// 排序 + 减枝
class Solution2 {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> path;
		dfs(candidates, path, result, target, 0);
		return result;
	}

private:
	void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, int gap, int start){
		if(gap == 0){
			result.push_back(path);
			return;
		}
		for(int i=start; i<nums.size();++i){
			// 减枝
			if(gap < nums[i]) return;
			path.push_back(nums[i]);
			dfs(nums, path, result, gap-nums[i], i);
			path.pop_back();
		}
	}
};

TEST(TestP39, Solution){
	Solution sln;
//	vector<int> candidates {2, 3, 6, 7};
//	int target = 7;
//	vector<vector<int>> result = sln.combinationSum(candidates, target);
//
//	testing::internal::UniversalPrint(result, &cout);
//	cout << endl;

	vector<int> candidates = {2, 3, 5};
	int target = 8;
	auto result = sln.combinationSum(candidates, target);
	testing::internal::UniversalPrint(result, &cout);
	cout << endl;
}
