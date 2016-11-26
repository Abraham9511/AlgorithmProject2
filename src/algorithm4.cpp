#include <iostream>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include"algorithm4.h"

using namespace std;

void swap(pair<int,double> *a, pair<int,double> *b) {
	pair<int,double> tmp = *a;
	*a = *b;
	*b = tmp;
}

double* Closet_Pair_Q(pair<int,double> *o, int n) {
	double* re= new double[3];
	if (n == 0 || n == 1) {
		return NULL;
	} else if (n == 2) {
		re[0] = fabs(o[0].second-o[1].second);
		re[1] = o[0].first;
		re[2] = o[1].first;
		return re;
	} else {
		int pos = rand()%n;
		pair<int,double> mid = make_pair(o[pos].first, o[pos].second);
		swap(o+pos, o+n-1);

		pair<int,double> *i = o+n-2, *lastBig = o+n-1;
		while (i >= o) {
			if (i->second >= mid.second) swap(i, --lastBig);
			i--;
		}
		swap(o+n-1, lastBig);

		int size = lastBig-o+1;
		double* re1 = Closet_Pair_Q(o, size);
		double* re2 = Closet_Pair_Q(lastBig+1, n-size);

		if (size == n) {
			return re1;
		} else {
			re[0] = fabs(lastBig->second - (lastBig+1)->second);
			re[1] = lastBig->first;
			re[2] = (lastBig+1)->first;
			if (size == n-1) return (re[0] <= re1[0]) ? re : re1;
			else if (size == 1) return (re[0] <= re2[0]) ? re : re2;
			else {
				if (re[0] <= re1[0] && re[0] <= re2[0]) return re;
				else if (re1[0] <= re2[0]) return re1;
				else return re2;
			}
		}
	}
    return re;
}
/*
int main() {
	pair<int, double> o[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		o[i] = make_pair(i, rand()%100);
		cout << o[i].first << " " << o[i].second << endl;
	}
	double *re = Closet_Pair_Q(o, 10);
	cout << re[0] << " " << re[1] << " " << re[2];
	return 0;
}*/
