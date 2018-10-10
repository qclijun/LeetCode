/*
 * p133.cc
 *
 *  Created on: 2018年10月9日
 *      Author: jun
 */

/**
 * 133. Clone Graph
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
 */
#include "graph.h"

#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

// 广度优先搜索
// time complexity O(2*E), space complexity O(V)
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(node == nullptr) return nullptr;

    	using ptr_node = UndirectedGraphNode*;

    	unordered_map<int, ptr_node> node_map;
    	queue<ptr_node> que;
    	que.push(node);
    	ptr_node root_node = new UndirectedGraphNode(node->label);
    	node_map[node->label] = root_node;

    	while(!que.empty()){
    		ptr_node cur = que.front();
    		que.pop();

    		ptr_node cur_clone = node_map[cur->label];
    		for(ptr_node neig : cur->neighbors){

    			auto iter = node_map.find(neig->label);
    			// not found
    			if(iter == node_map.end()){
    				que.push(neig);
    				ptr_node new_node = new UndirectedGraphNode(neig->label);
    				node_map[neig->label] = new_node;
    				cur_clone->neighbors.push_back(new_node);
    			}else{
    				cur_clone->neighbors.push_back(iter->second);
    			}
    		}
    	}
    	return root_node;
    }
};

TEST(TestP133, Solution){
	string s = "0,1,2#1,2#2,2";
	UndirectedGraphNode* node = BuildGraph(s);
	Solution sln;

	GraphVE gve;
	TransferToVE(*node, &gve);

	UndirectedGraphNode* node_clone = sln.cloneGraph(node);
	GraphVE gve_clone;
	TransferToVE(*node_clone, &gve_clone);

	EXPECT_EQ(gve, gve_clone);

}
