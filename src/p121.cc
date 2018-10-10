/*
 * p121.cc
 *
 *  Created on: 2018年9月30日
 *      Author: jun
 */

/**
 * 121. Best Time to Buy and Sell Stock
 * ay you have an array for which the ith element is the price of a given stock on day i.

 If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

 Note that you cannot sell a stock before you buy one.

 Example 1:

 Input: [7,1,5,3,6,4]
 Output: 5
 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 Not 7-1 = 6, as selling price needs to be larger than buying price.
 Example 2:

 Input: [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

#include <vector>

#include "gtest/gtest.h"

using std::vector;
using std::max;

// time complexity O(n), space complexity O(1)
class Solution {
public:
	int maxProfit(const vector<int>& prices) {
		if (prices.size() < 2)
			return 0;

		int last_min = prices[0];
		int profit = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] < last_min) {
				last_min = prices[i];
			} else {
				profit = max(profit, prices[i] - last_min);
			}
		}
		return profit;

	}
};

TEST(TestP121, Solution) {
	vector<int> prices { 7, 1, 5, 3, 6, 4 };
	Solution sln;
	EXPECT_EQ(5, sln.maxProfit(prices));

	prices = {7, 6, 4, 3, 1};
	EXPECT_EQ(0, sln.maxProfit(prices));
}
