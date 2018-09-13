
#include <stack>
#include <vector>
#include <iostream>

#include "tree.h"
#include "util.hpp"

using namespace std;

namespace p144 {

    class Solution {
    public:

        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<const TreeNode*> s;
            if (root != nullptr) s.push(root);
            while (!s.empty()) {
                const TreeNode* p = s.top();
                s.pop();
                result.push_back(p->val);
                if (p->right != nullptr) s.push(p->right);
                if (p->left != nullptr) s.push(p->left);

            }

            return result;
        }
    };

    int main() {

        TreeNode* root = build_tree("1 null 2 3 5");
        //        cout << root->val << endl;
        TreeNode* r = root->right;
        cout << "left child: " << r->left->val << endl;
        cout << "right child: " << r->right->val << endl;

        Solution sln = Solution();
        vector<int> result = sln.preorderTraversal(root);
        print_list(result);

        return 0;
    }
}
