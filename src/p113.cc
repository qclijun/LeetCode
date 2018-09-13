/*
 * p113.cc
 *
 *  Created on: 2018年9月9日
 *      Author: jun
 *
 *  113. Path Sum II
 *
 *  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
 */

#include "tree.h"
#include "util.hpp"
#include "gtest/gtest.h"

#include <vector>
#include <iostream>
using namespace std;

namespace p113{
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> output;
    	if(root==nullptr){
    		return output;
    	}
    	vector<int> path;
    	pathSum0(root, sum, path, output);
    	return output;
    }

private:
    void pathSum0(TreeNode* node, int sum, vector<int> currPath, vector<vector<int>>& output){
    	cout<<"sum: "<<sum<<", curr:";
    	print_list(currPath)<<endl;
    	cout<<"size of output: " << output.size() <<endl;
    	sum -= node->val;
    	currPath.push_back(node->val);
    	if(node->left == nullptr && node->right == nullptr){
    		if(sum == 0){
    			output.push_back(currPath);
    		}
    		return ;
    	}
    	if(node->left != nullptr && node->right != nullptr){
    		pathSum0(node->left, sum, currPath, output);
    		vector<int> copyPath(currPath);
    		pathSum0(node->right, sum, copyPath, output);
    		return;
    	}

    	if(node->left != nullptr){
    		pathSum0(node->left, sum, currPath, output);
    		return;
    	}

		pathSum0(node->right, sum, currPath, output);

    }
};

class Solution2{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> result;
    	vector<int> cur;
    	pathSum(root, sum, cur, result);
    	return result;
    }

private:
    void pathSum(TreeNode* node, int sum, vector<int>& cur, vector<vector<int>> result){
    	if(node == nullptr){
    		return;
    	}
    	cur.push_back(node->val);
    	sum -= node->val;
    	if(node->left==nullptr && node->right==nullptr){
    		if(sum==0){
    			result.push_back(cur);
    		}
    	}
    	pathSum(node->left, sum, cur, result);
    	pathSum(node->right, sum, cur, result);
    	cur.pop_back();

    }
};

}

namespace p113_test{
	TEST(TestP113, Solution){
		TreeNode* root = build_tree("5,4,8,11,null,13,4,7,2,null,null,5,1");
		p113::Solution solution;

		vector<vector<int>> result = solution.pathSum(root, 22);
		EXPECT_EQ(2, result.size());

		print_list(result[0])<<endl;
		print_list(result[1])<<endl;
	}
}

