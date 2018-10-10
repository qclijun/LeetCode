/*
 * graph.h
 *
 *  Created on: 2018年10月9日
 *      Author: jun
 */

#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_

#include <vector>
#include <memory>
#include <string>
#include <set>
#include <iostream>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

struct UndirectedGraphNode {
	int label;
	std::vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x): label(x) {}
};

struct GraphVE {
	std::set<int> vertexes;
	std::set<std::pair<int, int>> edges;
};

inline bool operator==(const GraphVE& g1, const GraphVE& g2){
	return g1.vertexes == g2.vertexes && g1.edges == g2.edges;
}

namespace fmt{
template<>
struct formatter<UndirectedGraphNode>{
	template<typename ParseContext>
	constexpr auto parse(ParseContext& ctx) { return ctx.begin();}

	template<typename FormatContext>
	auto format(const UndirectedGraphNode& node, FormatContext& ctx){
		int sz = node.neighbors.size();
		if(sz == 0){
			return format_to(ctx.begin(), "Node {}:[]", node.label);
		}
		format_to(ctx.begin(), "Node {}:[", node.label);
		for(int i = 0;;++i){
			format_to(ctx.begin(), "{}", node.neighbors[i]->label);
			if(i == sz - 1){
				return format_to(ctx.begin(), "]");
			}
			format_to(ctx.begin(), ", ");
		}
	}
};
}


UndirectedGraphNode* BuildGraph(const std::string& serialized_text);

std::set<UndirectedGraphNode*> GetAllNodes(UndirectedGraphNode* graph);

void DeleteGraph(UndirectedGraphNode* graph);

void TransferToVE(const UndirectedGraphNode& graph, GraphVE* out);

//std::string SerializeGraph(const UndirectedGraphNode& graph);

#endif /* INCLUDE_GRAPH_H_ */
