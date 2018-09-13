#include <string>
#include <vector>
#include <stack>
#include <boost/algorithm/string.hpp>

#include "tree.h"

using namespace std;

TreeNode* build_tree(const string& string_repr) {
    vector<string> nodes;
    boost::split(nodes, string_repr, boost::is_any_of(","), boost::token_compress_on);

    if (nodes.empty()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    vector<TreeNode*> prevLevel{root};
    vector<TreeNode*> currLevel;

    // node iterator
    int p = 1;
    // number of nodes current level
    int n = 2;

    while (true) {
        for (int i = p; i < nodes.size() && i < p + n; ++i) {
            currLevel.push_back(nodes[i] == "null" ? nullptr : new TreeNode(stoi(nodes[i])));
        }
        for (int j1 = 0, j2 = 0; j2 < currLevel.size();) {
            if (prevLevel[j1] == nullptr) {
                ++j1;
                continue;
            }
            if (j2 % 2 == 0) {
                prevLevel[j1]->left = currLevel[j2++];
            } else {
                prevLevel[j1++]->right = currLevel[j2++];
            }
        }
        p += n;
        if (p > nodes.size()) {
            break;
        }
        n *= 2;
        prevLevel.assign(currLevel.begin(), currLevel.end());
        currLevel.clear();
    }
    return root;
}

bool is_same_tree(TreeNode* p, TreeNode* q) {
    stack<TreeNode*> s;
    s.push(p);
    s.push(q);

    while (!s.empty()) {
        p = s.top();
        s.pop();
        q = s.top();
        s.pop();

        if (!p && !q) continue;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        s.push(q->left);
        s.push(q->left);
        s.push(p->right);
        s.push(q->right);
    }
    return true;
}

