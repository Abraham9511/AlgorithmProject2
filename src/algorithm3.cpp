#include <iostream>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

// 输入：无序序列
// 作用：将序列划分为两部分
// 使得前部分的值都小于后部分的值
int partition(pair<int, double>* list, const int& start, const int& end);

// 输入：无序序列
// 保证中值左边的元素都小于它
// 中值右边的元素都大于它
void findKMin(pair<int, double>* list, const int& start, const int& end, const int& target);

// 输入：无序序列
// 输出：序列的中值
// 同时保证中值左边的元素都小于它
// 中值右边的元素都大于它
int getMid(pair<int, double>* list, const int& number);

// 输入：三个最近对（最近对的下标和距离）
// 距离最近的最近对
pair<double, pair<int, int> > findMinBetweenThree(const pair<double, pair<int, int> >& pair1, const pair<double, pair<int, int> >& pair2, const pair<double, pair<int, int> >& pair3);

// 输入：所有图像投影到同意随机向量后的随机向量，
// 输出：该直线上的最近对的下标及距离
// 功能：使用归并排序返回直线上最近对的下标
pair<double, pair<int, int> > Closet_Pair_M(pair<int, double>* list, const int& number);

// 输入：所有图像投影到同意随机向量后的随机向量，
// 输出：该直线上的最近对的下标
// 功能：使用归并排序返回直线上最近对的下标
pair<int, int> Closet_Pair_Median(pair<int, double>* list, const int& total_image);


// 通过产生一个随机数
// 将序列划分为大小两部分
// 位于随机数前的元素都小于等于随机数后的元素
int partition(pair<int, double>* list, const int& start, const int& end) {
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

// 通过随机划分来将序列分块
// 如果得到的两块不是相等的
// 则继续调动自身进行划分
void findKMin(pair<int, double>* list, const int& start, const int& end, const int& target) {
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

// 通过调用findKMin来保证：
// 同时保证中值左边的元素都小于它
// 中值右边的元素都大于它
int getMid(pair<int, double>* list, const int& number) {
	int ans = (number - 1) / 2 + 1;
	findKMin(list, 0, number - 1, ans);

	return ans;
}

// 比较三者的最近距离
// 返回距离最小的那个
pair<double, pair<int, int> > findMinBetweenThree(pair<double, pair<int, int> >& pair1, pair<double, pair<int, int> >& pair2, pair<double, pair<int, int> >& pair3) {
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

// 采用归并排序的思想进行最近对的寻找
// 每次将序列划分为元素个数基本相当的两部分
// 分别求出两部分的最近对和跨两部分的最近对
// 返回三者中的最小值，即为所求最近对
pair<double, pair<int, int> > Closet_Pair_M(pair<int, double>* list, const int& number) {
	pair<double, pair<int, int> > answer;
	if (!list || number == 1) {
		answer.first = INT_MAX;
	} else if (number == 2) {
		// 确保序列有序
		if (list[0].second > list[1].second) {
			swap(list[0], list[1]);
		}
		answer.first = list[1].second - list[0].second;
		answer.second.first = list[0].first;
		answer.second.second = list[1].first;
	} else {
		// 这里是以1开始，mid表示数量
		int mid = getMid(list, number);

		// 分别得到三部分的最近对
		pair<double, pair<int, int> > Closet_Pair_Left = Closet_Pair_M(list, mid);
		pair<double, pair<int, int> > Closet_Pair_Right = Closet_Pair_M(list + mid, number - mid);
		pair<double, pair<int, int> > Closet_Pair_Cross;
		// 因为这里是以0开始
		Closet_Pair_Cross.first = list[mid].second - list[mid - 1].second;
		Closet_Pair_Cross.second.first = list[mid - 1].first;
		Closet_Pair_Cross.second.second = list[mid].first;

		answer = findMinBetweenThree(Closet_Pair_Left, Closet_Pair_Right, Closet_Pair_Cross);
	}

	return answer;
}

// 在内部调用Closet_Pair_M方法来得到最近对的下标和距离
// 然后从中抽取最近对的下标作为返回值
pair<int, int> Closet_Pair_Median(pair<int, double>* list, const int& total_image) {
	pair<double, pair<int, int> > answer = Closet_Pair_M(list, total_image);
	pair<int, int> points = make_pair(answer.second.first, answer.second.second);
	return points;
}
