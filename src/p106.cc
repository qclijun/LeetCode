/*
 * p106.cc
 *
 *  Created on: 2018年9月2日
 *      Author: jun
 */

/**
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.

 Note:
 You may assume that duplicates do not exist in the tree.

 For example, given

 inorder = [9,3,15,20,7]
 postorder = [9,15,7,20,3]
 Return the following binary tree:

  3
 / \
9  20
  /  \
 15   7

 */

#include <vector>
#include <algorithm>
#include "tree.h"

#include "gtest/gtest.h"

using namespace std;

namespace p106 {
	class Solution {
	public:
		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
			return buildTree0(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
		}

		template<typename RandomIterator>
		TreeNode* buildTree0(RandomIterator in_begin, RandomIterator in_end,
				RandomIterator post_begin, RandomIterator post_end){
			if(in_begin == in_end) return nullptr;
			//if(post_begin == post_end) return nullptr;

			auto post_root = std::prev(post_end);
			TreeNode* root = new TreeNode(*post_root);
			auto in_split = std::find(in_begin, in_end, *post_root);

			int leftSize = std::distance(in_begin, in_split);
			auto post_split = std::next(post_begin, leftSize);

			root->left = buildTree0(in_begin, in_split, post_begin, post_split);
			root->right = buildTree0(std::next(in_split), in_end, post_split, post_root);
			return root;
		}
	};
}

namespace p106_test{
	TEST(TestP106, Solution){
		p106::Solution solution;
		auto expected_tree = build_tree("3,9,20,null,null,15,7");

		vector<int> inorder = {9, 3, 15, 20, 7};
		vector<int> postorder = {9, 15, 7, 20, 3};
		auto acture_tree = solution.buildTree(inorder, postorder);
		EXPECT_TRUE(is_same_tree(expected_tree, acture_tree));
	}
}

