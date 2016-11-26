#include <iostream>
#include <utility>
#include <cmath>
#include <cstdlib>

using namespace std;

void swap(pair<int,int> *a, pair<int,int> *b) {
	pair<int,int> tmp = *a;
	*a = *b;
	*b = tmp;
}

int* Closet_Pair_Q(pair<int,int> *o, int n) {
	int* re = new int[3];
	if (n == 1) {
		re[0] = re[1] = re[2] = -1;
	} else if (n == 2) {
		re[0] = abs(o[0].second-o[1].second);
		re[1] = o[0].first;
		re[2] = o[1].first;
	} else {
		int pos = rand()%n;

		pair<int,int> mid = make_pair(o[pos].first, o[pos].second);

		swap(o+pos, o+n-1);

		pair<int,int> *i = o+n-2, *lastBig = o+n-1;
		while (i >= o) {
			if (i->second >= mid.second) swap(i, --lastBig);
			i--;
		}
		swap(o+n-1, lastBig);

		int* re1 = Closet_Pair_Q(o, pos+1);
		int* re2 = Closet_Pair_Q(o+pos, n-pos);
		if (abs(o[pos].second-o[pos+1].second) <= re1[0] && abs(o[pos].second-o[pos+1].second) >= re2[0]) {
			re[0] = abs(o[pos].second-o[pos+1].second);
			re[1] = o[pos].first;
			re[2] = o[pos+1].first;
		} else if (re1[0] <= re2[0]) {
			re[0] = re1[0];
			re[1] = re1[1];
			re[2] = re1[2];
		} else {
			re[0] = re2[0];
			re[1] = re2[1];
			re[2] = re2[2];
		}
	}
	return re;
}

int main() {
	pair<int,int> o[10];
	for (int i = 0; i < 10; i++) {
		o[i] = make_pair(i, rand()%10);
		cout << o[i].first << " " << o[i].second << endl;
	}
	int *re = Closet_Pair_Q(o, 10);
	cout << re[0] << " " << re[1] << " " << re[2];
	return 0;
}
