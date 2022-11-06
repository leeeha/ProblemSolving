#include <iostream>
using namespace std;

const int MAX = 2500; 
int arr[MAX][MAX];
int result[3]; 

bool check(int r, int c, int num){
	int start = arr[r][c];
	for(int i = r; i < r + num; i++){
		for(int j = c; j < c + num; j++){
			if(start != arr[i][j]){
				return false;
			}
		}
	}

	return true; 
}

void divide(int r, int c, int num){
	// ���� ���� ���� ���� ��� ĭ���� ���� ���̸� 
	if(check(r, c, num)){
		result[arr[r][c]]++;
	}else{
		// ���ο� ���� ����� �����.
		int size = num / 3;
		
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				divide(r + size * i, c + size * j, size); 
			}
		}
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; 
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int input;
			cin >> input;
			input++; // -1,0,1�� 0,1,2�� ǥ�� 
			arr[i][j] = input; 
		}
	}

	divide(0, 0, n);

	printf("%d\n%d\n%d\n", result[0], result[1], result[2]); 
	
	return 0;
}
