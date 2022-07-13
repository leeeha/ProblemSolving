#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e9; // 10�� 
int n;
int arr[11]; // 2 �� N �� 11 
int op[4]; // �� �������� ������ ���� 
int maxVal = -MAX, minVal = MAX;

// cnt�� ������� ����� �������� ��������, arr �迭�� �ε����� ����. 
// sum�� ���� ����� ������. 
void dfs(int plus, int minus, int mul, int div, int cnt, int result){
	// �����ڸ� ��� ������� ��
	if(cnt == n){
		maxVal = max(maxVal, result);
		minVal = min(minVal, result);
	}

	// ��� ����� �� Ž�� 
	if(plus > 0){
		dfs(plus - 1, minus, mul, div, cnt + 1, result + arr[cnt]);
	} 

	if(minus > 0){
		dfs(plus, minus - 1, mul, div, cnt + 1, result - arr[cnt]);
	}

	if(mul > 0){
		dfs(plus, minus, mul - 1, div, cnt + 1, result * arr[cnt]);
	}
	
	if(div > 0){
		dfs(plus, minus, mul, div - 1, cnt + 1, result / arr[cnt]);
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < 4; i++){
		cin >> op[i];
	}

	dfs(op[0], op[1], op[2], op[3], 1, arr[0]);

	cout << maxVal << "\n";
	cout << minVal << "\n";
	
	return 0;
}
