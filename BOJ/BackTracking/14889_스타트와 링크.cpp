#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
bool selected[MAX]; 
int arr[MAX][MAX];  
int n; 
int minVal = 1e9; 

void input(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
}

void updateMinVal() {
	vector<int> start, link; 
	int g1 = 0, g2 = 0; 

	for(int i = 0; i < n; i++){ 
		if(selected[i]){ 
			start.push_back(i); 
		}else{ 
			link.push_back(i); 
		}
	}

	// 각 팀의 능력치 계산 
	// 각 팀원들의 번호에 맞는 행과 열을 뽑아서 
	// 그 2차원 배열의 모든 원소들의 합을 구하면 된다. 
	for(int i = 0; i < n/2; i++){ 
		for(int j = 0; j < n/2; j++){  
			g1 += arr[start[i]][start[j]]; // 0~2: 00 01 02 10 11 12 20 21 22 
			g2 += arr[link[i]][link[j]];   // 3~5: 33 34 35 43 44 45 53 54 55 
		} 
	}

	// 최소 차이 구하기 
	int gap = abs(g1 - g2); 
	if(gap < minVal){ 
		minVal = gap; 
	}
}

void dfs(int cnt, int idx){ // 뽑은 개수, 탐색을 진행할 인덱스  
	if(cnt == n/2){ 
		updateMinVal(); // 최솟값 갱신 
		return; 
	}

	// n명 중에 n/2명을 선택하는 조합 구하기 (i는 idx부터 시작) 
	for(int i = idx; i < n; i++){ 
		if(!selected[i]){ 
			selected[i] = true; 
			dfs(cnt + 1, i); 
			selected[i] = false; 
		}
	}
}

int main()
{ 
	input(); 

	dfs(0, 0); 
	
	cout << minVal; 
	
	return 0;
}