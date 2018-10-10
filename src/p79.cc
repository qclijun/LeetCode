/*
 * p79.cc
 *
 *  Created on: 2018年9月29日
 *      Author: jun
 */

/**
 * 79. Word Search
 * Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent"
cells are those horizontally or vertically neighboring. The same letter cell may not be
used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;


class Solver {
private:
	typedef pair<int, int> pos_t;
private:
	vector<vector<char>> board;
	string word;

	vector<pos_t> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
	Solver(const vector<vector<char>>& board_, const string& word_): board(board_.size() + 2), word(word_){
		int row = board_.size();
		int col = board_[0].size();
		// add a border with character '0'
		board[0] = vector<char>(col + 2, '0');
		for(int i = 0; i < row; ++i){
			board[i + 1].push_back('0');
			copy(board_[i].begin(), board_[i].end(), back_inserter(board[i+1]));
			board[i + 1].push_back('0');
		}
		board[row + 1] = vector<char>(col + 2, '0');
	}

	bool solve(){
		// search first character of word
		for(int r = 1; r <= board.size() - 2; ++r){
			for(int c = 1; c <= board[0].size() - 2; ++c){
				cout << "(" << r << ", " << c << ")\n";
				if(board[r][c] == word[0]){
					cout << "satrt pos: (" << r << ", " << c << ")\n";

					// mark visited position with '0'
					board[r][c] = '0';
					if(solve0({r, c}, 1))
						return true;

					// recover if false
					board[r][c] = word[0];
				}

			}
		}
		return false;
	}
private:
	bool solve0(pos_t pos, int level){
		if(level == word.size()){
			return true;
		}

		for(auto dir : dirs){
			pos_t new_pos{pos.first + dir.first, pos.second + dir.second};
			if(board[new_pos.first][new_pos.second] == word[level]){
				cout << "new pos: (" << new_pos.first << ", " << new_pos.second << ")\n";
				board[new_pos.first][new_pos.second] = '0';
				if(solve0(new_pos, level + 1))
					return true;
				board[new_pos.first][new_pos.second] = word[level];
			}
		}
		return false;

	}
};


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	Solver solver(board, word);
    	return solver.solve();
    }
};

TEST(TestP79, Solution){
	Solution sln;
	vector<vector<char>> board {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
//	bool result = sln.exist(board, word);
//	EXPECT_TRUE(result);

	EXPECT_TRUE(sln.exist(board, "SEE"));
	EXPECT_FALSE(sln.exist(board, "ABCB"));
}

