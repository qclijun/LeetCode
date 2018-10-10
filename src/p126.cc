/*
 * p126.cc
 *
 *  Created on: 2018年9月21日
 *      Author: jun
 */
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <memory>
#include <unordered_set>
#include <unordered_map>
using namespace std;

namespace p126 {
struct state_t {
	string word;
	int level;

	state_t() :
			word(""), level(0) {
	}
	state_t(const string& word, int level) :
			word(word), level(level) {
	}
};

inline ostream& operator<<(ostream& os, const state_t& s) {
	os << "{" << s.word << ":" << s.level << "}";
	return os;
}
}

typedef std::shared_ptr<p126::state_t> ptr_state;

inline ostream& operator<<(ostream& os, const ptr_state& p_s) {
	os << *p_s;
	return os;
}

namespace std {
template<>
struct hash<ptr_state> {
	size_t operator()(const ptr_state& p_s) const noexcept {
		return str_hash(p_s->word);
	}
private:
	hash<string> str_hash;
};



template<>
struct equal_to<ptr_state> {
	bool operator()(const ptr_state& s1, const ptr_state& s2) const {
		return str_equal(s1->word, s2->word);
	}
private:
	equal_to<string> str_equal;
};
}

namespace p126 {
// 单队列，宽度优先搜索
class Solution_ {
private:
	vector<vector<string>> result;
	unordered_set<ptr_state> visited;
	unordered_map<ptr_state, vector<ptr_state>> father;
	queue<ptr_state> q;
	string beginWord;
	string endWord;
	unordered_set<string> wordDict;

	ptr_state tmp_state;
	int length;

public:
	Solution_(const string& beginWord, const string& endWord,
			vector<string>& wordList) :
			beginWord(beginWord), endWord(endWord), wordDict { wordList.begin(),
					wordList.end() }, tmp_state(make_shared<state_t>()) {
		length = numeric_limits<int>::max();
	}

	bool is_target(ptr_state s) {
		return s->word == endWord;
	}

	vector<vector<string>> findLadders() {
		ptr_state start_state = make_shared<state_t>(beginWord, 0);
		q.push(start_state);
		visited.insert(start_state);

		while (!q.empty()) {
			ptr_state s = q.front();
			q.pop();

			if (s->level >= length)
				break;

			if (is_target(s)) {
				length = s->level + 1;
				continue;
			}

//			cout << "\ncurrent state: " << *s << endl;

			tmp_state->word = s->word;
			tmp_state->level = s->level + 1;

			string& word = tmp_state->word;
			int level = tmp_state->level;
			for (int i = 0; i < word.size(); ++i) {
				for (char c = 'a'; c <= 'z'; ++c) {
					if (c == word[i])
						continue;
					swap(c, word[i]);

					if (wordDict.find(word) != wordDict.end()) {
						cout << "check state: " << *tmp_state;
						auto pos = visited.find(tmp_state);
						if(pos == visited.end() || (*pos)->level == level){
							ptr_state new_state = make_shared<state_t>(*tmp_state);
							visited.insert(new_state);
							father[new_state].push_back(s);

							if(pos == visited.end()) q.push(new_state);
						}
					}
					swap(c, word[i]);
				}
			}
			cout << "queue size: " << q.size() << endl;
		}
//		testing::internal::UniversalPrint(father, &cout);
//		cout << "Exit loop, start to generate path." << endl;
		gen_path();
		return result;
	}

	void gen_path() {
		auto final_state = make_shared<state_t>(endWord, -1);
		if (father.find(final_state) == father.end()) {
			return;
		}
		ptr_state s = final_state;
		vector<vector<ptr_state>> ret;
		ret.push_back(vector<ptr_state>());
		ret[0].push_back(final_state);

		bool finished = false;
		while (!finished) {
			int sz = ret.size();
			for (int i = 0; i < sz; ++i) {
				auto curr_state = ret[i][ret[i].size()-1];
				if (curr_state->word == beginWord){
					finished = true;
					break;
				}
				vector<ptr_state>& parents = father[curr_state];
				for (int j = 1; j < parents.size(); ++j) {
					vector<ptr_state> copy_path { ret[i].begin(),
							ret[i].end() };
					copy_path.push_back(parents[j]);
					ret.push_back(copy_path);
				}

				ret[i].push_back(parents[0]);
			}
		}
		for (int i = 0; i < ret.size(); ++i) {
			vector<string> path;
			for (int j = ret[i].size() - 1; j >= 0; --j) {
				path.push_back(ret[i][j]->word);
			}
			result.push_back(path);
		}

	}
};

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord,
			vector<string>& wordList) {
		Solution_ sln(beginWord, endWord, wordList);
		return sln.findLadders();
	}
};




}

namespace p126_test {
TEST(TestP126, Solution) {
	string beginWord = "red";
	string endWord = "tax";
	vector<string> wordList { "ted", "tex", "red", "tax", "tad", "den", "rex",
			"pee" };

	p126::Solution sln;
	auto result = sln.findLadders(beginWord, endWord, wordList);

	testing::internal::UniversalPrint(result, &cout);
}
}

