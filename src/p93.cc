/*
 * p93.cc
 *
 *  Created on: 2018年9月26日
 *      Author: jun
 */

/**
 * 93. Restore IP Addresses
 *
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

 */

#include <string>
#include <sstream>
#include <vector>
#include <set>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<int> path;
        path.push_back(0);
        dfs(s, path, result);
        return result;
    }
private:
    void dfs(const string& s, vector<int>& path, vector<string>& out){
    	if(path.size() == 4){
    		int last_pos = path[3];
    		int cnt = s.size() - last_pos;
    		if(cnt > 0 && cnt < 4 && is_valid(s, last_pos, cnt)){
    			ostringstream tmp;
    			for(int i=0;i<path.size()-1;++i){
    				tmp << s.substr(path[i], path[i+1]-path[i]) << '.';
    			}
    			tmp << s.substr(last_pos, cnt);
    			out.push_back(tmp.str());
    		}
    		return;
    	}

    	for(int cnt = 1; cnt < 4; ++cnt){
    		int last_pos = path[path.size() - 1];
    		if(last_pos + cnt > s.size()) continue;
    		if(is_valid(s, last_pos, cnt)){
    			path.push_back(last_pos + cnt);
    			dfs(s, path, out);
    			path.pop_back();
    		}
    	}
    }

    bool is_valid(const string& s, int begin, int cnt){
    	if(cnt > 1 && s[begin] == '0') return false;
    	int num = stoi(s.substr(begin, cnt));
    	return num >= 0 && num <= 255;
    }
};

TEST(TestP93, Solution){
	string s = "25525511135";
	Solution sln;
	vector<string> result = sln.restoreIpAddresses(s);

	set<string> expect {
		"255.255.11.135",
		"255.255.111.35"
	};

	set<string> result_set {result.begin(), result.end()};

	EXPECT_EQ(expect, result_set);
}


