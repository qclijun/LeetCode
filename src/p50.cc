/*
 * p50.cc
 *
 *  Created on: 2018年9月29日
 *      Author: jun
 */

/*
 * 50. Pow(x, n)
 * Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
 */
#include <iostream>
#include <limits>

using namespace std;

// time complexity O(logn), space complexity O(1)
class Solution {
public:
    double myPow(double x, int n) {
    	if(x == 1.0) return 1.0;
    	if(x == 0.0) return 0.0;
    	if(n < 0) return 1.0 / myPow(x, -n - 1) / x ;

    	return myPow0(x, n);
    }

private:
    double myPow0(double x, int n){
    	if(n == 0) return 1.0;
    	double val = myPow0(x, n/2);
    	if(n % 2 == 0){
    		return val * val;
    	}else{
    		return val * val * x;
    	}
    }
};

int main(){
	int n = numeric_limits<int>::min();
	cout << "min: " << n << endl;
	int n2 = -n - 1;
	cout << "max: " << n2 << endl;
	int n3 = -n;
	cout << n3 << endl;
}
