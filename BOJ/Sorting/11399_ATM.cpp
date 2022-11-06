// 11399번. ATM
/*
	Input
	사람의 수 N명
	각 사람이 돈을 인출하는 데 걸리는 시간 Pi

	Output
	각 사람이 돈을 인출하는 데 필요한 시간의 합의 최솟값
*/

#include <iostream>
#include <algorithm> // std::sort
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* time = new int[n];
	for (int i = 0; i < n; i++)
		cin >> time[i];

	// Pi: 3 1 4 3 2 -> 1 2 3 3 4
	// 최소 시간: 1*5 + 2*4 + 3*3 + 3*2 + 4*1
	// 시간이 적게 걸리는 사람일수록 앞쪽에 줄을 서야 한다!

	std::sort(time, time + n);

	int total = 0;
	for (int i = 0; i < n; i++) {
		total += time[i] * (n - i);
	}

	cout << total;

	return 0;
}