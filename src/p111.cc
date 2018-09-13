/*
 * p111.cc
 *
 *  Created on: 2018年9月6日
 *      Author: jun
 */

#include "tree.h"
#include "gtest/gtest.h"

#include <algorithm>

namespace p111 {
class Solution {
public:

	int minDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return minDepth0(root);
	}

private:
	int minDepth0(TreeNode* node) {
		if (node->left == nullptr && node->right == nullptr) {
			return 1;
		}
		if (node->left != nullptr && node->right == nullptr) {
			return 1 + minDepth0(node->left);
		}
		if (node->left == nullptr && node->right != nullptr) {
			return 1 + minDepth0(node->right);
		}
		return 1 + std::min(minDepth0(node->left), minDepth0(node->right));
	}

};
}

namespace p111_test {
TEST(TestP111, Solution) {
	p111::Solution solution;
	auto tree = build_tree("3,9,20,null,null,15,7");
	EXPECT_EQ(2, solution.minDepth(tree));

	auto tree2 = build_tree("1,2");
	EXPECT_EQ(2, solution.minDepth(tree));
}
}

