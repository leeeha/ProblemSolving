// 2751번. 수 정렬2 (합병 정렬, 퀵 정렬, 힙 정렬)

#include <iostream>
//#include <algorithm> // std::sort
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void quickSort(int* arr, int low, int high) {
	// 리스트 요소가 하나라면 이미 정렬된 상태
	if (low >= high) return;

	int pivot = arr[high]; // 마지막 원소를 피벗으로!
	int cursor = low; // 피벗보다 '큰' 첫번째 원소를 가리킴.

	// 피벗 바로 앞까지 탐색
	for (int i = low; i < high; i++) {
		if (arr[i] < pivot) { // 피벗보다 작은 원소를 발견하면
			swap(arr[i], arr[cursor]); // 피벗보다 큰 첫번째 원소와 스왑한다.
			cursor++;
		}
	}

	// 피벗이 가운데에 오도록 스왑하기
	swap(arr[cursor], arr[high]);

	// 피벗 기준으로 나눠진 각 부분 리스트에 대해 퀵정렬 반복
	quickSort(arr, low, cursor - 1); // 피벗의 왼쪽
	quickSort(arr, cursor + 1, high); // 피벗의 오른쪽
}

int main()
{
	int n;
	scanf("%d", &n);

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	//std::sort(arr, arr + n);
	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}

// vector 컨테이너, cin, cout 사용하는 경우
#include <iostream>
#include <vector>
#include <algorithm> // std::sort
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> arr;
	int n;
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	std::sort(arr.begin(), arr.end());

	for (auto& e : arr)
		cout << e << '\n';

	return 0;
}