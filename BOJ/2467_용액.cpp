#include <iostream>
#include <vector> 
#include <algorithm> 
#include <utility>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n; // �ִ� 10�� 

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i]; // �������� (�� ���Ҵ� �ִ� 10��) 
	}

	int left = 0, right = n - 1; 
	int sum = 2e9; // �ִ� 20�� (0�� ���� ����� ������ ���ŵ� ����) 
	pair<int, int> p; // ���� 0�� ���� ����� �� ����� Ư���� ���� 
	
	// ���ʿ��� �ٰ����� �� ������ 
	while(left < right){
		int a = v[left];
		int b = v[right];
		
		if(abs(a + b) < sum){ 
			sum = abs(a + b); // �ּڰ� ���� 
			p = { a, b }; // �� ���� 
		}

		if(a + b < 0){ 
			left++; // ���� �ø��� ���ؼ�  
		}else{
			right--; // ���� ���̱� ���ؼ� 
		}
	}

	cout << p.first << " " << p.second << endl;

	return 0;
}
