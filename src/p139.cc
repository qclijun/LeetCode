
/**
 * 139. Word Break
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 */


#include <vector>
#include <string>
#include <set>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

#include "gtest/gtest.h"

using namespace std;

// dp
// time complexity O(n^2), space complexity O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict {wordDict.begin(), wordDict.end()};
        int n = s.size();
        vector<bool> f(n + 1, false);
        f[0] = true;
        for(int j = 1; j <= n; ++j){
            for(int i = 0; i < j; ++i){
                if(f[i] && dict.find(s.substr(i, j - i)) != dict.end()){
//                    fmt::print("true: [{}, {})\n", i, j);
                  
                    f[j] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};

TEST(TestP139, Solution){
    Solution sln;
    
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    EXPECT_TRUE(sln.wordBreak(s, wordDict));
    
    s = "applepenapple";
    wordDict = {"apple", "pen"};
    EXPECT_TRUE(sln.wordBreak(s, wordDict));
    
    s = "catsandog";
    wordDict = {"cats","dog","sand","and","cat"};
    EXPECT_FALSE(sln.wordBreak(s, wordDict));
        
}
