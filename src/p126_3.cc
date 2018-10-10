/*
 * p126_3.cc
 *
 *  Created on: 2018年9月24日
 *      Author: jun
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution_1{
private:
	vector<string> words;
	unordered_map<string, int> wordDict;
	vector<bool> visited;

	int beginId;
	int endId;

	unordered_map<int, vector<int>> graph;

public:
	Solution_1(const string& beginWord, const string& endWord, vector<string>& wordList)
		:words(wordList){
		for(int i=0;i<words.size();++i){
			wordDict[words[i]] = i;
		}
		auto pos = wordDict.find(beginWord);
		beginId = pos == wordDict.end() ? -1 : pos->second;
		if(beginId == -1){
			beginId = words.size();
			words.push_back(beginWord);
			wordDict[beginWord] = beginId;
		}

		pos = wordDict.find(endWord);
		endId = pos == wordDict.end() ? -1 : pos->second;

		int num_states = wordDict.size();
		visited.resize(num_states);
	}

private:
	void build_graph(){

	}
};


