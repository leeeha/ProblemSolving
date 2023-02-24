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

	// �� ���� �ɷ�ġ ��� 
	// �� �������� ��ȣ�� �´� ��� ���� �̾Ƽ� 
	// �� 2���� �迭�� ��� ���ҵ��� ���� ���ϸ� �ȴ�. 
	for(int i = 0; i < n/2; i++){ 
		for(int j = 0; j < n/2; j++){  
			g1 += arr[start[i]][start[j]]; // 0~2: 00 01 02 10 11 12 20 21 22 
			g2 += arr[link[i]][link[j]];   // 3~5: 33 34 35 43 44 45 53 54 55 
		} 
	}

	// �ּ� ���� ���ϱ� 
	int gap = abs(g1 - g2); 
	if(gap < minVal){ 
		minVal = gap; 
	}
}

void dfs(int cnt, int idx){ // ���� ����, Ž���� ������ �ε���  
	if(cnt == n/2){ 
		updateMinVal(); // �ּڰ� ���� 
		return; 
	}

	// n�� �߿� n/2���� �����ϴ� ���� ���ϱ� (i�� idx���� ����) 
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