/*
 * p37.cc
 *
 *  Created on: 2018年9月27日
 *      Author: jun
 */

/**
 * 37 Sudoku Solver
 * Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <bitset>
#include "gtest/gtest.h"
using namespace std;



inline void print_board(vector<vector<char>>& board){
	for(int i=0; i<9; ++i){
		if(i==3 || i == 6){
			cout << string(24, '-') << '\n';
		}
		for(int j=0; j<9; ++j){
			if(j==3 || j == 6) cout << '|';
			char c = board[i][j];
			if(c=='.') c = ' ';
			cout << setw(j % 3 == 0 ? 1 : 3) << c;
		}
		cout << '\n';
	}
	cout << endl;
}


class Sudoku {
private:
	static constexpr const int N = 9;
private:
	typedef pair<int, int> pos_t;
public:
	struct state_t {
		int row;
		int col;
		int num_valid; // 有效的数字的个数
	};


private:
	vector<vector<char>>& board;
	vector<state_t> unknowns;

	// bitset位置1时，表示已经被占用
	vector<bitset<N>> row_flags;
	vector<bitset<N>> col_flags;
	vector<bitset<N>> grid_flags;

public:
	Sudoku(vector<vector<char>>& board): board(board), row_flags(N),
		col_flags(N), grid_flags(N){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				char ch = board[i][j];
				int idx = ch - '1';
				if(ch != '.'){
					row_flags[i].set(idx);
					col_flags[j].set(idx);
					grid_flags[get_grid({i, j})].set(idx);
				}
			}
		}

		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				char ch = board[i][j];
				if(ch == '.'){
					int idx = ch - '1';
					int num_valid = N - (row_flags[i] | col_flags[j] | grid_flags[get_grid({i, j})]).count();
					unknowns.push_back({i, j, num_valid});
				}
			}
		}
		sort(unknowns.begin(), unknowns.end(), [](const state_t& s1, const state_t& s2){
			return s1.num_valid < s2.num_valid;
		});


	}


private:

	int get_grid(pos_t pos){
		return pos.first / 3 * 3 + pos.second / 3;
	}

	bool is_valid(int r, int c, char val){
		int idx = val - '1';
		return !row_flags[r].test(idx) &&  !col_flags[c].test(idx) && !grid_flags[get_grid({r, c})].test(idx);
	}

	void set_val(int r, int c, char val){
		board[r][c] = val;
		int idx = val - '1';
		row_flags[r].set(idx);
		col_flags[c].set(idx);
		grid_flags[get_grid({r, c})].set(idx);
	}

	void reset_val(int r, int c){
		char val = board[r][c];
		int idx = val - '1';
		board[r][c] = '.';
		row_flags[r].reset(idx);
		col_flags[c].reset(idx);
		grid_flags[get_grid({r, c})].reset(idx);
	}

public:
	bool solve(int level){
		if(level == unknowns.size()){
			return true;
		}
		state_t s = unknowns[level];
		for(char ch = '1'; ch <= '9'; ++ch){
			if(is_valid(s.row, s.col, ch)){
				cout << '(' << s.row << ',' << s.col << "): " << ch << endl;
				set_val(s.row, s.col, ch);
				print_board(board);
				if(solve(level + 1)){
					return true;
				}
				reset_val(s.row, s.col);
			}
		}
		return false;
	}


};



class Solution{
public:
    void solveSudoku(vector<vector<char>>& board) {
    	Sudoku sudoku(board);
    	sudoku.solve(0);
    }
};

TEST(TestP37, Solution){
	vector<string> board_s {
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79"
	};
	vector<vector<char>> board;
	for(const string& s: board_s){
		board.push_back(vector<char>(s.begin(), s.end()));
	}

	print_board(board);
	Solution sln;
	sln.solveSudoku(board);
}

