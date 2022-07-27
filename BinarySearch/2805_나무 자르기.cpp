#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, m; // n�� �ִ� 100��, m�� �ִ� 20�� 
int tree[100'0001]; // �� ������ ���̴� �ִ� 10�� 

// ���ܱ��� ���̸�ŭ �߸� �������� ���� ���� 
// m �̻����� �����ϴ� �Լ� 
bool decision(int height){
	long long total = 0; 

	// ���ܱ��� ���̸�ŭ �߸� �������� ���� ���� ���Ѵ�.
	for(int i = 0; i < n; i++){ 
		int gap = tree[i] - height;
		if(gap > 0){ 
			total += gap; 
		} // 0�� ������ ���� 
	}

	// �� ������ ���� m �̻��̸� true ���� 
	return total >= m; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 

	for(int i = 0; i < n; i++){
		cin >> tree[i]; 
	}

	int left = 0, right = 1e9; 
	while(left <= right){
		int mid = (left + right) / 2; 
		if(decision(mid)) left = mid + 1; // x�� �ִ��� ���ϱ� ���� 
		else right = mid - 1; // true �������� �̵��ϵ��� 
	}

	cout << right; 
		
	return 0; 
}