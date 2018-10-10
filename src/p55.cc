/*
 * p55.cc
 *
 *  Created on: 2018年9月30日
 *      Author: jun
 */
/**
 * 55. Jump Game
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.


分析：
最终的状态确定，可以用逆向法, 广度优先搜索
 */

#include <vector>
#include <queue>

#include "gtest/gtest.h"
using namespace std;

class JumpGame{
private:
	const vector<int>& nums;
	queue<int> q;
	vector<bool> visited;
public:
	JumpGame(const vector<int>& nums): nums(nums), visited(nums.size()){
		q.push(nums.size()-1);
		visited[nums.size()-1] = true;
	}

	bool run(){
		while(!q.empty()){
			int curr_pos = q.front();
			q.pop();

			if(curr_pos == 0)
				return true;
			for(int i =0; i < curr_pos; ++i){
				if(!visited[i] && i + nums[i] >= curr_pos){
					q.push(i);
					visited[i] = true;
				}
			}
		}
		return false;
	}
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
    	JumpGame game(nums);
    	return game.run();
    }
};

// time complexity O(n), compexity O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int start = 0;
    	int reach = 1;
    	for(int i=start, start=reach; i< reach; ++i){
    		reach = max(reach, i + 1 + nums[i]);
    		if(reach >= nums.size()) return true;

    	}
    	return reach >= nums.size();
    }
};

TEST(TestP55, Solution){
	vector<int> nums {2, 3, 1, 1, 4};
	Solution sln;
	EXPECT_TRUE(sln.canJump(nums));

	nums = {3, 2, 1, 0, 4};
	EXPECT_FALSE(sln.canJump(nums));
}

