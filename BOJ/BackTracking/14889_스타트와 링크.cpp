#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
bool selected[MAX]; // false로 초기화 
int arr[MAX][MAX];  // 0으로 초기화 
int n, minVal = 1e9;

void dfs(int idx, int cnt){
	vector<int> start; // 스타트 팀원의 인덱스 값
	vector<int> link;  // 링크 팀원의 인덱스 값 

	int startScore = 0;
	int linkScore = 0;

	if(cnt == n/2){ // n명 중에 n/2명 선택되면
		for(int i = 0; i < n; i++){ 
			if(selected[i]){ 
				// 선택된 사람은 start 팀으로 (그 사람의 인덱스 저장) 
				start.push_back(i); 
			}else{ 
				link.push_back(i); 
			}
		}

		// 각 팀의 능력치 합 계산 
		for(int i = 0; i < n/2; i++){
			for(int j = 0; j < n/2; j++){
				startScore += arr[start[i]][start[j]];
				linkScore += arr[link[i]][link[j]];
			} 
		}

		// 최소 차이 구하기 
		if(abs(startScore - linkScore) < minVal){
			minVal = abs(startScore - linkScore);
		}

		return; 
	}

	// n/2명 선택될 때까지 재귀 호출 반복 
	for(int i = idx; i < n; i++){
		if(!selected[i]){ 
			selected[i] = true; 
			dfs(i, cnt + 1); 
			selected[i] = false; 
		}
	}
}

int main()
{ 
	cin >> n; // 최대 20 
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}

	dfs(0, 0);
	
	cout << minVal << "\n"; 
	
	return 0;
}
