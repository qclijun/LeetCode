/*
 * p126_2.cc
 *
 *  Created on: 2018年9月22日
 *      Author: jun
 */

#include "gtest/gtest.h"

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution_{
private:
	string beginWord;
	string endWord;
	unordered_map<string, int> wordDict;
	vector<string>& words;
	int num_states;
	vector<int> levels;
	queue<int> q;
	vector<bool> visited;

	vector<vector<string>> result;
	unordered_map<int, vector<int>> father;

	int beginId;
	int endId;

	int length;
public:
	Solution_(const string& beginWord, const string& endWord, vector<string>& wordList)
		:beginWord(beginWord), endWord(endWord), words(wordList){

		for(int i=0; i<wordList.size();++i){
			wordDict[wordList[i]] = i;
		}
		if(wordDict.find(beginWord) == wordDict.end()){
			wordDict[beginWord] = words.size();
			words.push_back(beginWord);
		}
		num_states = wordDict.size();
		levels.resize(num_states);
		visited.resize(num_states);

		beginId = wordDict[beginWord];
		auto end_pos = wordDict.find(endWord);
		if(end_pos == wordDict.end()){
			endId = -1;
		}else{
			endId = end_pos->second;
		}
		length = numeric_limits<int>::max();

		testing::internal::UniversalPrint(wordDict, &cout);
		cout << endl;
	}

	vector<vector<string>> findLadders(){
		if(endId == -1){
			return result;
		}
		q.push(beginId);
		visited[beginId] = true;

		while(!q.empty()){
			int curr = q.front();
			q.pop();

			cout << "curr state: ";
			print_state(curr);
			cout << endl;

			if(levels[curr] >= length) break;
			if(curr == endId){
				length = levels[curr] + 1;
				continue;
			}

			string& word = words[curr];
			int new_level = levels[curr] + 1;

			for(int i=0;i<word.size();++i){
				for(char c='a';c<='z';++c){
					if(c == word[i]) continue;
					swap(c, word[i]);

					auto pos = wordDict.find(word);

					if(pos != wordDict.end()){
						int new_id = pos->second;

						cout << "check state: " << word;

						// not visited
						if(!visited[new_id]){

							q.push(new_id);
							visited[new_id] = true;
							levels[new_id] = new_level;
							father[new_id].push_back(curr);

							cout << " not visited." << endl;
							print_state(new_id);
							cout << endl;

						}else if(levels[new_id] == new_level){
							// visited and same level
							father[new_id].push_back(curr);

							cout << " visited and sample level." << endl;
							print_state(new_id);
							cout << endl;
						}
					}
					swap(c, word[i]);
				}
			}
		} // end of while

//		testing::internal::UniversalPrint(father, &cout);
		gen_path();
		return result;
	}
private:
//	typedef ostream& (*out_fn)(ostream&);
//
//	out_fn print_state(int id){
//		return [=](std::ostream& os){
//			os << "(" << words[id] << ":" << levels[id] << ")";
//			return os;
//		};
//	}
	void print_state(int id){
		cout << "(" << words[id] << ":" << levels[id] << ")";
	}

	void gen_path(){
		if(father.find(endId) == father.end()){
			return;
		}

		vector<vector<int>> paths;
		paths.push_back({endId});

		bool finished = false;
		while(!finished){
			int sz = paths.size();
			for(int i=0;i<sz;++i){
				int curr_state = paths[i][paths[i].size() - 1];
				if(curr_state == beginId){
					finished = true;
					break;
				}
				vector<int>& parents = father[curr_state];
				for(int j=1; j<parents.size();++j){
					vector<int> copy_path {paths[i].begin(), paths[i].end()};
					copy_path.push_back(parents[j]);
					paths.push_back(copy_path);
				}
				paths[i].push_back(parents[0]);
			}
		}

		// reverse path
		for(int i=0;i<paths.size();++i){
			vector<string> path;
			for(int j=paths[i].size()-1;j>=0;--j){
				path.push_back(words[paths[i][j]]);
			}
			result.push_back(move(path));
		}
	}
};

// 双队列
class Solution_2{
private:
	vector<string> words;
	unordered_map<string, int> wordDict;

	int beginId;
	int endId;

	unordered_set<int> curr;
	unordered_set<int> next;
	vector<bool> visited;


	int length;
	vector<vector<string>> result;
	unordered_map<int, vector<int>> father;

public:
	Solution_2(const string& beginWord, const string endWord, vector<string>& wordList)
		:words(wordList.begin(), wordList.end()){
		for(int i=0;i<wordList.size();++i){
			wordDict[wordList[i]] = i;
		}
		auto pos = wordDict.find(beginWord);
		beginId = pos == wordDict.end() ? -1 : pos->second;

		pos = wordDict.find(endWord);
		endId = pos == wordDict.end() ? -1 : pos->second;

		if(beginId == -1){
			beginId = words.size();
			wordDict[beginWord] = beginId;
			words.push_back(beginWord);
		}
		int num_states = wordDict.size();
		visited.resize(num_states);



		length = numeric_limits<int>::max();

	}

public:
	vector<vector<string>> findLadders(){

		if(endId == -1){
			return result;
		}
		curr.insert(beginId);
		visited[beginId] = true;


		int level = -1;

		while(!curr.empty()){
			++ level;
			if(level >= length) break;

			cout << "curr level " << level << ":\n";
			for(int state : curr){
				print_state(state);
				cout << '\n';
			}

			// 把当前层的节点都加入到visited
			for(int state : curr){
				visited[state] = true;
			}
			// 扩展每一个当前层节点
			for(int state: curr){
				if(state == endId) {
					length = level + 1;
					continue;
				}
				string& word = words[state];
				for(int i=0;i<word.size();++i){
					for(char c='a';c<='z';++c){
						if (c == word[i]) continue;
						swap(c, word[i]);
						auto pos = wordDict.find(word);
						if(pos != wordDict.end()){
							int new_state = pos -> second;
							if(!visited[new_state]){
								next.insert(new_state);
								father[new_state].push_back(state);
							}
						}
						swap(c, word[i]);
					}
				}
			}
			curr.clear();
			swap(curr, next);
		}
		gen_path();
		return result;
	}
private:
	void gen_path(){
		if(father.find(endId) == father.end()){
			return;
		}

		vector<vector<int>> paths;
		paths.push_back({endId});

		bool finished = false;
		while(!finished){
			int sz = paths.size();
			for(int i=0;i<sz;++i){
				int curr_state = paths[i][paths[i].size() - 1];
				if(curr_state == beginId){
					finished = true;
					break;
				}
				vector<int>& parents = father[curr_state];
				for(int j=1; j<parents.size();++j){
					vector<int> copy_path {paths[i].begin(), paths[i].end()};
					copy_path.push_back(parents[j]);
					paths.push_back(copy_path);
				}
				paths[i].push_back(parents[0]);
			}
		}

		// reverse path
		for(int i=0;i<paths.size();++i){
			vector<string> path;
			for(int j=paths[i].size()-1;j>=0;--j){
				path.push_back(words[paths[i][j]]);
			}
			result.push_back(move(path));
		}
	}
	void print_state(int id){
		cout << "(" << words[id] << ")";
	}
};


class Solution{
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
		Solution_2 sln(beginWord, endWord, wordList);
		return sln.findLadders();
	}
};


TEST(TestP126_2, Solution){
	Solution sln;

	string beginWord = "red";
	string endWord = "tax";
	vector<string> wordList { "ted", "tex", "red", "tax", "tad", "den", "rex",
			"pee" };
//	"hit"
//	"cog"
//	["hot","dot","dog","lot","log","cog"]
//	string beginWord = "hit";
//	string endWord = "cog";
//	vector<string> wordList { "hot","dot","dog","lot","log","cog" };

	auto result = sln.findLadders(beginWord, endWord, wordList);

	testing::internal::UniversalPrint(result, &cout);
	cout << endl;
}

