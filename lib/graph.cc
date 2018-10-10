/*
 * graph.cc
 *
 *  Created on: 2018年10月9日
 *      Author: jun
 */

#include "graph.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <memory>
#include <unordered_map>
#include <algorithm>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

using std::string;
using std::vector;
using std::pair;
using std::set;
using std::queue;
using std::shared_ptr;
using std::make_shared;
using std::stoi;
using std::unordered_map;

using std::cout;
using std::endl;

static const char* NODE_SEP = "#";
static const char* NEIGHBOR_SEP = ",";



//
//string SerializeGraph(const UndirectedGraphNode& graph){
//	using edge_t = pair<int, int>;
//	using ptr_node = const UndirectedGraphNode*;
//	set<int> seen;
//	set<edge_t> edges;
//
//	queue<ptr_node> nodes;
//	nodes.push(&graph);
//	seen.insert(graph.label);
//
//	while(!nodes.empty()){
//		ptr_node curr = nodes.front();
//		nodes.pop();
//
//		for(ptr_node node : curr->neighbors){
//			// not seen
//			if(seen.find(node->label) == seen.end()){
//				seen.insert(node->label);
//				nodes.push(node);
//			}
//			if(curr->label > node->label){
//				edges.insert({node->label, curr->label});
//			}else{
//				edges.insert({curr->label, node->label});
//			}
//		}
//	}
//	return "";
//}

using ptr_node = UndirectedGraphNode*;
using c_ptr_node = const UndirectedGraphNode*;

ptr_node BuildGraph(const string& text){
	vector<string> split_result;
	boost::split(split_result, text, boost::is_any_of(NODE_SEP));
	const int num_nodes = split_result.size();

	unordered_map<int, ptr_node> node_map;
	vector<pair<int, int>> edges;

	ptr_node root = nullptr;
	for(const string& node_str : split_result){
		vector<string> tmp;
		boost::split(tmp, node_str, boost::is_any_of(NEIGHBOR_SEP));
		int curr_node = stoi(tmp[0]);
		node_map[curr_node] = new UndirectedGraphNode(curr_node);
		if(root == nullptr){
			root = node_map[curr_node];
		}
		for(int i = 1; i < tmp.size(); ++i){
			int neig_label = stoi(tmp[i]);
			edges.push_back({curr_node, neig_label});
		}
	}

	for(const auto& edge : edges){
		ptr_node node1 = node_map[edge.first];
		ptr_node node2 = node_map[edge.second];
		node1->neighbors.push_back(node2);
		if(node1 != node2)
			node2->neighbors.push_back(node1);
	}
	return root;
}


// 广度优先搜索
set<ptr_node> GetAllNodes(ptr_node graph){
	set<ptr_node> result;
	queue<ptr_node> que;
	que.push(graph);
	result.insert(graph);

	while(!que.empty()){
		ptr_node cur = que.front();
		que.pop();
		for(ptr_node neig : cur->neighbors){
			if(result.find(neig) == result.end()){
				result.insert(neig);
				que.push(neig);
			}
		}
	}

	return result;
}

void DeleteGraph(ptr_node graph){
	for (auto p : GetAllNodes(graph)){
		delete p;
	}
}

void TransferToVE(const UndirectedGraphNode& graph, GraphVE* out){
	queue<c_ptr_node> que;
	que.push(&graph);
	out->vertexes.insert(graph.label);

	while(!que.empty()){
		c_ptr_node cur = que.front();
		que.pop();
		for(ptr_node neig : cur->neighbors){
			if(out->vertexes.find(neig->label) == out->vertexes.end()){
				out->vertexes.insert(neig->label);
				que.push(neig);
			}
			if(cur->label <= neig->label){
				out->edges.insert({cur->label, neig->label});
			}else{
				out->edges.insert({neig->label, cur->label});
			}
		}
	}

}
