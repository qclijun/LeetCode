/*
 * 140. Word Break II
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
 * 
 * 
 */

#include <vector>
#include <string>
#include <set>

#include "gtest/gtest.h"

using namespace std;


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict {wordDict.begin(), wordDict.end()};
        int n = s.size();
        vector<bool> f(n+1, false);
        f[0] = true;
        
        // O(n^2)
        for(int j = 1; j < n; ++j){
            for(int i = 0; i < j; ++i){
                if(f[i] && dict.find(s.substr(i, j-i)) != dict.end()){
                    f[j] = true;
                    break;
                }
            }
        }
        vector<string> result;
        vector<string> path;
        
        gen_path(f, s, dict, n, path, result);
        return result;
    }
    
    void gen_path(const vector<bool>& f, const string& s, const set<string>& dict, 
                  int sz, vector<string>& path, vector<string>& result){
        
        if(sz == 0){
            string tmp = "";
            for(int i = path.size() - 1;;--i){
                tmp += path[i];
                if(i == 0){
                    result.push_back(tmp);
                    break;
                }
                tmp += ' ';
            }
        }
        
        for(int i = 0; i < sz; ++i){
            if(f[i]){
                string tmp = s.substr(i, sz - i);
                if(dict.find(tmp) != dict.end()){
                    path.push_back(tmp);
                    gen_path(f, s, dict, i, path, result);
                    path.pop_back();
                }
            }
        }
    }
};


TEST(TestP140, Solution){
    Solution sln;
    string s = "catsanddog";
    vector<string> wordDict {"cat", "cats", "and", "sand", "dog"};
    
    vector<string> result = sln.wordBreak(s, wordDict);
    set<string> result_set {result.begin(), result.end()};
    set<string> expect {"cats and dog", "cat sand dog"};
    
    EXPECT_EQ(expect, result_set);
    
}
