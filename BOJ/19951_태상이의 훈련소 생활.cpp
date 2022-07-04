#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100'001
using namespace std;

struct cmd {
	int a;
	int b;
	int k;
};

int n, m;
int arr[MAX];
int accSum[MAX];
cmd cmdArr[MAX];

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < m; i++){
		int a, b, k;
		cin >> a >> b >> k;
		cmdArr[i] = { a - 1, b - 1, k };
	}

	for(int i = 0; i < m; i++){
		int start = cmdArr[i].a;
		int end = cmdArr[i].b;
		int k = cmdArr[i].k;

		// start에 +k, (end+1)에 -k 
		accSum[start] += k; 
		accSum[end + 1] -= k; 
	}

	// accSum 배열의 누적합 구하기 
	for(int i = 0; i < n; i++){ 
		accSum[i + 1] += accSum[i]; 
	}

	// 누적합 배열과 원본 배열 더하기 
	for(int i = 0; i < n; i++){
		arr[i] += accSum[i];
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}