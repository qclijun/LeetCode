/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   p2.cpp
 * Author: jun
 *
 * Created on July 11, 2018, 10:31 PM
 */

#include <vector>
#include <iostream>

#include "struct.h"

using namespace std;


namespace p2 {

    class Solution {
    public:

        ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {

            ListNode * result = nullptr;
            ListNode * p = nullptr;
            int jinwei = 0;
            while ((l1 != nullptr) && (l2 != nullptr)) {
                cout << l1->val << endl;
                cout << l2->val << endl;
                if (result == nullptr) {
                    result = new ListNode(jinwei + l1->val + l2->val);
                    p = result;
                } else {
                    p->next = new ListNode(jinwei + l1->val + l2->val);
                    p = p->next;
                }
                cout << "jinwei: " << jinwei << " p.val: " << p->val << endl;
                jinwei = p->val / 10;
                p->val %= 10;


                l1 = l1->next;
                l2 = l2->next;
            }

            while (l1 != NULL) {
                p->next = new ListNode(jinwei + l1->val);
                p = p->next;
                jinwei = p->val / 10;
                p->val %= 10;

                l1 = l1->next;
            }

            while (l2 != NULL) {

                p->next = new ListNode(jinwei + l2->val);
                p = p->next;
                jinwei = p->val / 10;
                p->val %= 10;

                l2 = l2->next;
            }

            if (jinwei > 0) {
                p->next = new ListNode(jinwei);
            }

            return result;
        }
    };

    ListNode* init_list(const vector<int>& vals) {
        auto it = vals.begin();
        ListNode * p = new ListNode(*it++);
        ListNode * head = p;
        while (it != vals.end()) {
            p->next = new ListNode(*it++);
            p = p->next;
        }
        return head;
    }

    
    int main() {
        vector<int> ivec;
        ivec.push_back(2);
        ivec.push_back(4);
        ivec.push_back(3);

        ListNode *l1 = init_list(ivec);

        ivec.clear();
        ivec.push_back(5);
        ivec.push_back(6);
        ivec.push_back(4);
        ListNode *l2 = init_list(ivec);

        cout << "hello" << endl;

        Solution obj;
        ListNode * result = obj.addTwoNumbers(l1, l2);

        while (result != nullptr) {
            cout << result->val << endl;
            result = result->next;
        }
        return 0;
    }

}