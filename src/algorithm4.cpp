#include <iostream>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "algorithm4.h"
using namespace std;

//exchange the values of pointers
void swap(pair<int,double> *a, pair<int,double> *b) {
	pair<int,double> tmp = *a;
	*a = *b;
	*b = tmp;
}

//select the clostest pair of the vector, return the distance and their ids
double* quick_sort(pair<int,double> *o, int n) {
	double* re = new double[3];
	if (n == 0 || n == 1) {
		delete []re;
		return NULL;	//return null if the number of vectors is only 1 or 0
	} else if (n == 2) {
		re[0] = fabs(o[0].second-o[1].second);	//evaluate the distance
		re[1] = o[0].first;
		re[2] = o[1].first;
		return re;	//return themselves if the number of vectors is 2
	} else {
		int pos = rand()%n;	//select the position of cursor for quick sort
		pair<int,double> mid = make_pair(o[pos].first, o[pos].second);
		swap(o+pos, o+n-1);	//put the cursor to the end of the vectors' list

		//let the vector whose value is smaller than the cursor put at the front of the position of the cursor
		pair<int,double> *i = o+n-2, *lastBig = o+n-1;
		while (i >= o) {
			if (i->second >= mid.second) swap(i, --lastBig);
			i--;
		}
		swap(o+n-1, lastBig);

		int size = lastBig-o+1;
		double* re1 = quick_sort(o, size);
		double* re2 = quick_sort(lastBig+1, n-size);

		if (size == n) {
			delete []re;
			delete []re2;
			return re1;	//cursors' value is the largest among the vectors, which means that re2 is null
		} else {
			//if the closet pair consists of the vector in two sides, one of them must be the cursor
			re[0] = fabs(lastBig->second - (lastBig+1)->second);
			re[1] = lastBig->first;
			re[2] = (lastBig+1)->first;

			if (size == n-1) {
				//the cursor's value is just smaller than one of the vectors, which means re2 is null
				if (re[0] <= re1[0]) {
					delete []re1;
					delete []re2;
					return re;
				} else {
					delete []re;
					delete []re2;
					return re1;
				}
			} else if (size == 1) {
				//the cursor's value is the smallest among the vecotrs, which means re1 is null
				if (re[0] <= re2[0]) {
					delete []re1;
					delete []re2;
					return re;
				} else {
					delete []re;
					delete []re1;
					return re2;
				}
			} else {
				//compare the distance of these three pairs who is possible to be the closet pair and return the closet pair
				if (re[0] <= re1[0] && re[0] <= re2[0]) {
					delete []re1;
					delete []re2;
					return re;
				} else if (re1[0] <= re2[0]) {
					delete []re;
					delete []re2;
					return re1;
				} else {
					delete []re;
					delete []re1;
					return re2;
				}
			}
		}
	}
}

//use the function before, but just return the ids of the closet pair in the container form of pair
pair<int, int> Closet_Pair_Pivot(pair<int, double>* list, const int& total_image) {
	double* re = quick_sort(list, total_image);
	pair<int,int> result = make_pair(re[1], re[2]);
	delete []re;
	return result;
}
