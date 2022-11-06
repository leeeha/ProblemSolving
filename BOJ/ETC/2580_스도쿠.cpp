#include <iostream>
using namespace std;

int arr[9][9];

bool promising(int r, int c, int a){ 
	for(int i = 0; i < 9; i++){
		// ���� �࿡ ��ġ�� ���ڰ� ������ 
		if(arr[r][i] == a) return false; 
		// ���� ���� ��ġ�� ���ڰ� ������ 
		if(arr[i][c] == a) return false;
	}

	// 3x3 �簢�� ���� ��ġ�� ���ڰ� ������ 
	for(int i = (r/3) * 3; i < (r/3) * 3 + 3; i++){
		for(int j = (c/3) * 3; j < (c/3) * 3 + 3; j++){
			if(arr[i][j] == a) return false; 
		}
	}

	// ��� ������ �����ϸ� true 
	return true; 
}

void dfs(int r, int c){ 
	// ���� ������ ���� ��� ��� 
	if(r == 9){ 
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	// ���� ������ ����, ���� ���� ù��° ���� �̵� 
	if(c == 9) dfs(r + 1, 0); 

	// ��ĭ�� 1~9���� �־��. 
	if(arr[r][c] == 0){ 
		for(int i = 1; i <= 9; i++){
			// ������ �Ǵ� 
			if(promising(r, c, i)){ 
				arr[r][c] = i; // ���� ��ȭ 
				dfs(r, c + 1); // ��� ȣ�� (���� ���� �̵�) 
				arr[r][c] = 0; // ���� ���� 
			}
		}
	}else{
		// ���� ���� �̵� 
		dfs(r, c + 1); 
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> arr[i][j]; 
		}
	}

	dfs(0, 0); 
	
	return 0;
}