/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   treenode.h
 * Author: jun
 *
 * Created on August 25, 2018, 6:03 PM
 */

#ifndef STRUCT_H
#define STRUCT_H

#include <string>

struct ListNode {
    int val;
    ListNode * next;

    ListNode(int x) : val(x), next(nullptr) {

    }
};







#endif /* TREENODE_H */

