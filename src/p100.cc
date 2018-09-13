#include <stack>
#include "tree.h"


using namespace std;

namespace p100{
    class Solution{
    public:
        bool isSameTree(TreeNode* p, TreeNode* q){
            stack<TreeNode*> s;
            s.push(p);
            s.push(q);
            
            while(!s.empty()){
                p = s.top();
                s.pop();
                q = s.top();
                s.pop();
                
                if(!p && !q) continue;
                if(!p || !q) return false;
                if(p->val != q->val) return false;
                
                s.push(q->left);
                s.push(q->left);
                s.push(p->right);
                s.push(q->right);
            }
            return true;
        }
    };
}

