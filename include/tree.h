/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tree.h
 * Author: jun
 *
 * Created on September 1, 2018, 11:27 PM
 */

#ifndef TREE_H
#define TREE_H

#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

TreeNode* build_tree(const std::string& string_repr);
bool is_same_tree(TreeNode* p, TreeNode* q);

#endif /* TREE_H */

