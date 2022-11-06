#include <iostream>
#define MAX 7  
using namespace std;

int n, r; 
int arr[MAX]; // 0���� �ʱ�ȭ 
int selected[MAX]; // 0���� �ʱ�ȭ 

void dfs(int cnt){
	if(cnt == r){
		for(int i = 0; i < r; i++){
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i = 0; i < n; i++){
		// cnt��°�� ���õ� ī�带 arr[i]�� ���� 
		selected[cnt] = arr[i]; 
		dfs(cnt + 1); 
	}
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> r;
	
	for(int i = 0; i < n; i++){
		arr[i] = i + 1; 
	} 

	dfs(0);
	
	return 0;
}