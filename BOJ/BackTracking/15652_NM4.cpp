#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue> 
#define MAX 9 
using namespace std; 

int n, m; 
int arr[MAX]; 

// ���õ� m���� ����Ѵ�. 
void printArray(){ 
	for(int i = 0; i < m; i++){ 
		cout << arr[i] << " "; 
	}
	cout << "\n"; 
}

void dfs(int num, int cnt){ // ���� ��ȣ, ���� ���� 
	if(cnt == m){
		printArray(); 
		return; 
	}

	for(int i = num; i <= n; i++){ 
		arr[cnt] = i; // ���õ� ���� �����Ѵ�. 
		dfs(i, cnt + 1); 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 
	
	dfs(1, 0); 
	
    return 0;
}