
#include <vector>
#include <algorithm>
#include "tree.h"

#include "gtest/gtest.h"

using namespace std;


/*
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

 */

namespace p105{
    // 递归， 时间复杂度O(n), 空间复杂度O(log(n))
    class Solution{
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
            
            return buildTree0(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        }
        
        template<typename InputIterator>
        TreeNode* buildTree0(InputIterator pre_first, InputIterator pre_last,
            InputIterator in_first, InputIterator in_last){
            if(pre_first == pre_last) return nullptr;
            if(in_first == in_last) return nullptr;
            
            auto root = new TreeNode(*pre_first);
            auto inRootPos = std::find(in_first, in_last, *pre_first);
            auto leftSize = std::distance(in_first, inRootPos);
            
            auto pre_split = std::next(pre_first, leftSize + 1);
            
            root->left = buildTree0(std::next(pre_first), pre_split, in_first, inRootPos);
            root->right = buildTree0(pre_split, pre_last, std::next(inRootPos), in_last);
            return root;
        }
    };
}

namespace p105_test{
    TEST(TestP105, Solution){
        p105::Solution solution;
        auto expected_tree = build_tree("3,9,20,null,null,15,7");
        
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        auto acture_tree = solution.buildTree(preorder, inorder);
        EXPECT_TRUE(is_same_tree(expected_tree, acture_tree));
    }
}
