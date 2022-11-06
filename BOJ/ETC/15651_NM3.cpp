#include <iostream>
#define MAX 7  
using namespace std;

int n, r; 
int arr[MAX]; // 0으로 초기화 
int selected[MAX]; // 0으로 초기화 

void dfs(int cnt){
	if(cnt == r){
		for(int i = 0; i < r; i++){
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i = 0; i < n; i++){
		// cnt번째로 선택된 카드를 arr[i]로 지정 
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