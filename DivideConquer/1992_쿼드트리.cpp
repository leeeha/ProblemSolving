#include <iostream>
#include <string> 
using namespace std;

const int MAX = 64;
int arr[MAX][MAX];

void divide(int size, int r, int c){	
	// ���� ���� �簢�� ���� ��� ĭ���� ���� ������ Ȯ�� 
	int cur = arr[r][c];
	
	for(int i = r; i < r + size; i++){ 
		for(int j = c; j < c + size; j++){
			if(cur != arr[i][j]){ 
				// ��� 0�̳� 1�� �̷���� ������, ��������� 4��� (�ð� ����) 
				cout << "(";
				divide(size / 2, r, c); // 2��и� 
				divide(size / 2, r, c + size / 2); // 1��и� 
				divide(size / 2, r + size / 2, c); // 3��и� 
				divide(size / 2, r + size / 2, c + size / 2); // 4��и� 
				cout << ")"; 
				return; 
			}
		}
	}
	
	// ��� 0�̰ų� 1�̸� �״�� ��� 
	cout << cur; 
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; 
	cin >> n;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s; 

		// ���̰� n�� ���ڿ��� ���� �ϳ��ϳ��� ������ ��ȯ�ؼ� ���� 
		for(int j = 0; j < n; j++){
			arr[i][j] = s[j] - '0'; 
		}
	}

	divide(n, 0, 0); 
	
	return 0;
}
