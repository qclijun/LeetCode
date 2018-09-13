/*
 * p112.cc
 *
 *  Created on: 2018年9月9日
 *      Author: jun
 */

#include "tree.h"
#include "gtest/gtest.h"

namespace p112 {
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) {
			return false;
		}
		return hasPathSum0(root, sum);
	}

private:
	bool hasPathSum0(TreeNode* node, int sum){
		sum -= node->val;
		if(node->left == nullptr && node->right == nullptr){
			return sum == 0;
		}
		if(node->left != nullptr && node->right != nullptr){
			return hasPathSum0(node->left, sum) || hasPathSum0(node->right, sum);
		}
		if(node->left != nullptr){
			return hasPathSum0(node->left, sum);
		}
		return hasPathSum0(node->right, sum);
	}
};
}

namespace p112_test{
	TEST(TestP112, Solution){
		TreeNode* root = build_tree("5,4,8,11,null,13,4,7,2,null,null,null,1");
		p112::Solution solution;
		EXPECT_TRUE(solution.hasPathSum(root, 22));

		root = build_tree("1,2");
		EXPECT_FALSE(solution.hasPathSum(root, 1));


	}
}

