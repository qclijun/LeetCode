/*
 * p69.cc
 *
 *  Created on: 2018年9月29日
 *      Author: jun
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	if(x < 2) return x;
        int first = 1;
        int last = x / 2 + 1;

        while(first < last){
        	int mid = first + (last - first + 1) / 2;
        	if(mid  <= x / mid){
        		first = mid;
        	}else{
        		last = mid - 1;
        	}
        }
        return first;
    }
};


int main(){
	Solution sln;
	cout << sln.mySqrt(4) << endl;
	cout << sln.mySqrt(8) << endl;

	return 0;
}
