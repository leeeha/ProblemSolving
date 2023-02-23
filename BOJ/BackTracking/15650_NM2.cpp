#include <iostream>
#define MAX 9 
using namespace std; 

int n, m; 
int arr[MAX]; 
bool selected[MAX];

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

	for(int i = num; i <= n; i++){ // num���� ���� 
		if(!selected[i]){ 
			selected[i] = true; 
			arr[cnt] = i; // ���õ� ���� �����Ѵ�. 
			dfs(i, cnt + 1); 
			selected[i] = false; 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; 
	
	dfs(1, 0); 
	
    return 0;
}