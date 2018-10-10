/*
 * p130.cc
 *
 *  Created on: 2018年9月24日
 *      Author: jun
 */


#include <vector>
#include <queue>
using namespace std;

namespace p130{
class SolutionHelper{
private:
	vector<vector<char>>& board;
	int num_rows;
	int num_cols;

	typedef pair<int, int> state_t;
	// 四个方向
	vector<state_t> four_dir {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
	SolutionHelper(vector<vector<char>>& board): board(board){
		num_rows = board.size();
		num_cols = board[0].size();
	}

	void solve(){
		for(int c = 0; c < num_cols; ++c){
			bfs(board, 0, c);
			bfs(board, num_rows - 1, c);
		}
		for(int r  = 0; r < num_rows; ++r){
			bfs(board, r, 0);
			bfs(board, r, num_cols - 1);
		}
		for(int r = 0; r < num_rows; ++r){
			for(int c = 0; c < num_cols; ++c){
				if(board[r][c] == '+'){
					board[r][c] = 'O';
				}else if(board[r][c] == 'O'){
					board[r][c] = 'X';
				}
			}
		}
	}

private:
	bool is_valid(state_t s){
		int r = s.first;
		int c = s.second;
		return r >= 0 && r < num_rows && c >= 0 && c < num_cols && board[r][c] == 'O';
	}

	vector<state_t> state_extend(state_t s){
		vector<state_t> new_states;
		for(const state_t& d : four_dir){
			state_t new_state {s.first + d.first, s.second + d.second};
			if(is_valid(new_state)){
				new_states.push_back(new_state);
			}
		}
		return new_states;
	}


    void bfs(vector<vector<char>>& board, int i, int j){
    	queue<state_t> q;
    	state_t start_s{i, j};
    	if(is_valid(start_s)){
    		board[i][j] = '+';
    		q.push(start_s);
    	}
    	while(!q.empty()){
    		auto s = q.front();
    		q.pop();

    		for(auto new_s : state_extend(s)){
    			board[new_s.first][new_s.second] = '+';
    			q.push(new_s);
    		}
    	}
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
    	if(board.empty()) return;
        SolutionHelper sln(board);
        sln.solve();
    }
};


}
