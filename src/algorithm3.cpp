#include <iostream>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

int partition(pair<int, double>* list, int start, int end);
void findKMin(pair<int, double>* list, int start, int end, int target);
int getMid(pair<int, double>* list, int number);

/*
	@ dist   : 距离
	@ index1 : 第一个点
	@ index2 : 第二个点
*/
pair<double, pair<int, int> > findMinBetweenThree(pair<double, pair<int, int> >& pair1, pair<double, pair<int, int> >& pair2, pair<double, pair<int, int> >& pair3);

/*
	@ double : 距离
	@ int    : 第一个点的位置
	@ int    : 第二个点的位置
	@ list   : 输入的元素，第一个分量表示原位置，第二个分量表示排序时的位置
	@ number : 输入元素的个数
*/
pair<double, pair<int, int> > Closet_Pair_M(pair<int, double>* list, int number);

int main() {
	pair<int, double> pairs[7];
	pairs[0] = make_pair(0, 300);
	pairs[1] = make_pair(1, 0);
	pairs[2] = make_pair(2, 30);
	pairs[3] = make_pair(3, 100);
	pairs[4] = make_pair(4, 10);
	pairs[5] = make_pair(5, 1);
	pairs[6] = make_pair(6, 50);
	pair<double, pair<int, int> > answer = Closet_Pair_M(pairs, 7);
	cout << "dist is " << answer.first << endl;
	cout << "one is " << answer.second.first << ", two is " << answer.second.second << endl;
	return 0;
}

int partition(pair<int, double>* list, int start, int end) {
	int rd = start + rand() % (end - start + 1);
	swap(list[rd], list[end]);

	int j = start - 1;
	for (int i = start; i < end; i++) {
		if (list[i].second <= list[end].second) {
			swap(list[++j], list[i]);
		}
	}
	swap(list[++j], list[end]);
	return j;
}

void findKMin(pair<int, double>* list, int start, int end, int target) {
	int m = partition(list, start, end);
	int current = m - start + 1;
	if (target == current) {
		return;
	} else if (target < current) {
		findKMin(list, start, m - 1, target);
	} else {
		findKMin(list, m + 1, end, target - current);
	}
}

int getMid(pair<int, double>* list, int number) {
	int ans = (number - 1) / 2 + 1;
	findKMin(list, 0, number - 1, ans);
	return ans;
}

pair<double, pair<int, int> > findMinBetweenThree(pair<double, pair<int, int> >& pair1, pair<double, pair<int, int> >& pair2, pair<double, pair<int, int> >& pair3) {
	cout << "pair1: " << pair1.first << ", " << pair1.second.first << ", " << pair1.second.second << endl;
	cout << "pair2: " << pair2.first << ", " << pair2.second.first << ", " << pair2.second.second << endl;
	cout << "pair3: " << pair3.first << ", " << pair3.second.first << ", " << pair3.second.second << endl;
	cout << endl;
	if (pair1.first < pair2.first) {
		if (pair1.first < pair3.first) {
			return pair1;
		} else {
			return pair3;
		}
	} else {
		if (pair2.first < pair3.first) {
			return pair2;
		} else {
			return pair3;
		}
	}
}

pair<double, pair<int, int> > Closet_Pair_M(pair<int, double>* list, int number) {
	pair<double, pair<int, int> > answer;
	if (!list || number == 1) {
		answer.first = INT_MAX;
	} else if (number == 2) {
		if (list[0].second > list[1].second) {
			swap(list[0], list[1]);
		}
		answer.first = list[1].second - list[0].second;
		answer.second.first = list[0].first;
		answer.second.second = list[1].first;
	} else {
		// 这里是以1开始，mid表示数量
		int mid = getMid(list, number);

		pair<double, pair<int, int> > Closet_Pair_1 = Closet_Pair_M(list, mid);
		pair<double, pair<int, int> > Closet_Pair_2 = Closet_Pair_M(list + mid, number - mid);
		pair<double, pair<int, int> > Closet_Pair_3;
		// 因为这里是以0开始
		Closet_Pair_3.first = list[mid].second - list[mid - 1].second;
		cout << "mid is " << mid << endl;
		Closet_Pair_3.second.first = list[mid - 1].first;
		Closet_Pair_3.second.second = list[mid].first;
		answer = findMinBetweenThree(Closet_Pair_1, Closet_Pair_2, Closet_Pair_3);
	}

	for (int i = 0; i < number; i++) {
		cout << list[i].first << " " << list[i].second << endl;
	}
	cout << "answer is : ";
	cout << "dist is " << answer.first << " " << answer.second.first << ", " << answer.second.second << endl << endl;
	return answer;
}
