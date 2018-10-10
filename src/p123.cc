/*
 * p123.cc
 *
 *  Created on: 2018年10月4日
 *      Author: jun
 */

/**
 * 123. Best Time to Buy and Sell Stock III
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
111
Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "gtest/gtest.h"

using std::vector;
using std::max;
using std::min;
using std::make_heap;
using std::pop_heap;
using std::cout;
using std::endl;

// time complexity O(n^2), space complexity O(1)
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0;
       for(int i = 0; i < prices.size(); ++i){
    	   profit = max(profit, maxProfit_one_transaction(prices, 0, i) + maxProfit_one_transaction(prices, i, prices.size()));
       }
       return profit;
    }


    // time complexity O(n), space complexity O(1)
    int maxProfit_one_transaction(const vector<int>& prices, int begin, int end){
    	if(end - begin < 2) return 0;

		int last_min = prices[begin];
		int profit = 0;
		for (int i = begin + 1; i < end; ++i) {
			if (prices[i] < last_min) {
				last_min = prices[i];
			} else {
				profit = max(profit, prices[i] - last_min);
			}
		}
		return profit;
    }

};

// time complexity O(n), space complexity O(n)
class Solution{
public:
    int maxProfit(vector<int>& prices) {
    	const int n = prices.size();
    	if(n < 2) return 0;

    	// f(i)表示[0, i]区间内交易1次的最大利润, 0<=i<<n-1
    	// g(i)表示[i, n-1]区间内交易1次的最大利润, 0<=i<=n-1
    	vector<int> f(n, 0);
    	vector<int> g(n, 0);

    	for(int i=1, valley=prices[0]; i<n;++i){
    		valley = min(valley, prices[i]);
    		f[i] = max(f[i-1], prices[i] - valley);
    	}
    	for(int i=n-2, peak=prices[n-1]; i>=0; --i){
    		peak = max(peak, prices[i]);
    		g[i] = max(g[i-1], peak - prices[i]);
    	}
    	int max_profit = 0;
    	for(int i=0;i<n;++i){
    		max_profit = max(max_profit, f[i] + g[i]);
    	}
    	return max_profit;
    }
};



TEST(TestP123, Solution){
    Solution sln;
    vector<int> prices {3, 3, 5, 0, 0, 3, 1, 4};
    EXPECT_EQ(6, sln.maxProfit(prices));

    vector<int> prices2 = {1, 2, 3, 4, 5};
    EXPECT_EQ(4, sln.maxProfit(prices2));

    prices = {7, 6, 4, 3, 1};
    EXPECT_EQ(0, sln.maxProfit(prices));

    prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    EXPECT_EQ(13, sln.maxProfit(prices));
}
