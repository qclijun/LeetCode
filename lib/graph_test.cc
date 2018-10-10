/*
 * graph_test.cc
 *
 *  Created on: 2018年10月9日
 *      Author: jun
 */

#include <iostream>
#include <string>
#include <memory>
#include <set>

#include "graph.h"

#include "gtest/gtest.h"

#define FMT_HEADER_ONLY
#include "fmt/format.h"

using namespace std;

TEST(Graph, BuildGraph){
	string s = "0,1,2#1,2#2,2";
	UndirectedGraphNode* graph = BuildGraph(s);

	string node0_str = fmt::format("{}", *graph);
	EXPECT_EQ("Node 0:[1, 2]", node0_str);

	UndirectedGraphNode* node1 = graph->neighbors[0];
	EXPECT_EQ("Node 1:[0, 2]", fmt::format("{}", *node1));

	UndirectedGraphNode* node2 = graph->neighbors[1];
	EXPECT_EQ("Node 2:[0, 1, 2]", fmt::format("{}", *node2));

	DeleteGraph(graph);
}

TEST(Graph, GetAllNodes){
	string s = "0,1,2#1,2#2,2";
	UndirectedGraphNode* graph = BuildGraph(s);
	set<UndirectedGraphNode*> nodes = GetAllNodes(graph);

	EXPECT_EQ(3, nodes.size());
	set<int> node_labels;
	for(auto p : nodes) node_labels.insert(p->label);

	set<int> expect {0, 1, 2};
	EXPECT_EQ(expect, node_labels);

	DeleteGraph(graph);
}





