// 2751��. �� ����2 (�պ� ����, �� ����, �� ����)

#include <iostream>
//#include <algorithm> // std::sort
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void quickSort(int* arr, int low, int high) {
	// ����Ʈ ��Ұ� �ϳ���� �̹� ���ĵ� ����
	if (low >= high) return;

	int pivot = arr[high]; // ������ ���Ҹ� �ǹ�����!
	int cursor = low; // �ǹ����� 'ū' ù��° ���Ҹ� ����Ŵ.

	// �ǹ� �ٷ� �ձ��� Ž��
	for (int i = low; i < high; i++) {
		if (arr[i] < pivot) { // �ǹ����� ���� ���Ҹ� �߰��ϸ�
			swap(arr[i], arr[cursor]); // �ǹ����� ū ù��° ���ҿ� �����Ѵ�.
			cursor++;
		}
	}

	// �ǹ��� ����� ������ �����ϱ�
	swap(arr[cursor], arr[high]);

	// �ǹ� �������� ������ �� �κ� ����Ʈ�� ���� ������ �ݺ�
	quickSort(arr, low, cursor - 1); // �ǹ��� ����
	quickSort(arr, cursor + 1, high); // �ǹ��� ������
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

// vector �����̳�, cin, cout ����ϴ� ���
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