/*
 * p122.cc
 *
 *  Created on: 2018年10月3日
 *      Author: jun
 */

#include <vector>

using std::vector;

// time complexity O(n), space complexity O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int profit = 0;
    	for(int i = 1; i < prices.size(); ++i){
    		int diff = prices[i] - prices[i-1];
    		if (diff > 0) profit += diff;
    	}
    	return profit;
    }
};
