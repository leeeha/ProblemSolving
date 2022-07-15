#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
bool selected[MAX]; // false�� �ʱ�ȭ 
int arr[MAX][MAX];  // 0���� �ʱ�ȭ 
int n, minVal = 1e9;

void dfs(int idx, int cnt){
	vector<int> start; // ��ŸƮ ������ �ε��� ��
	vector<int> link;  // ��ũ ������ �ε��� �� 

	int startScore = 0;
	int linkScore = 0;

	if(cnt == n/2){ // n�� �߿� n/2�� ���õǸ�
		for(int i = 0; i < n; i++){ 
			if(selected[i]){ 
				// ���õ� ����� start ������ (�� ����� �ε��� ����) 
				start.push_back(i); 
			}else{ 
				link.push_back(i); 
			}
		}

		// �� ���� �ɷ�ġ �� ��� 
		for(int i = 0; i < n/2; i++){
			for(int j = 0; j < n/2; j++){
				startScore += arr[start[i]][start[j]];
				linkScore += arr[link[i]][link[j]];
			} 
		}

		// �ּ� ���� ���ϱ� 
		if(abs(startScore - linkScore) < minVal){
			minVal = abs(startScore - linkScore);
		}

		return; 
	}

	// n/2�� ���õ� ������ ��� ȣ�� �ݺ� 
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
	cin >> n; // �ִ� 20 
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}

	dfs(0, 0);
	
	cout << minVal << "\n"; 
	
	return 0;
}
