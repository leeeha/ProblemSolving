#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
#include <cmath>
#define MAX 1001 
using namespace std;

int n, m; // ������ ���� 
int parent[MAX]; // ��Ʈ ��带 �����ϴ� ���̺� 
vector<pair<int, pair<int, int>>> edges; // ���� ���� 
vector<int> upHill; // ���������� ���� 
int ans = 0; // �ּ� ���  

// Ư�� ���Ұ� ���� ���� ã�Ƴ��� 
int findParent(int x){
	// ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��� ȣ�� 
	if(x == parent[x]) return x; 
	return parent[x] = findParent(parent[x]);
}

// �� ���Ұ� ���� ������ ��ġ�� 
void unionParent(int a, int b){
	a = findParent(a);
	b = findParent(b);

	// �� ���� ��ȣ�� �θ� ��尡 �ǵ��� 
	if(a < b) parent[b] = a;
	else parent[a] = b; 
}

int getWorstCase(){ 
	// ���� ��뿡 ���� �������� ���� 
	// �������� ���� �߰���Ű�ϱ� �־��� ��� 
	sort(edges.begin(), edges.end()); 

	// �θ� ���̺� �ʱ�ȭ 
	for(int i = 1; i <= n; i++){
		parent[i] = i;  
	}

	int count = 0; // ���������� ���� 
	for(int i = 0; i < edges.size(); i++){
		int isDown = edges[i].first; // 1�̸� ��������, 0�̸� �������� 
		int a = edges[i].second.first; 
		int b = edges[i].second.second; 

		// ����Ŭ�� �߻����� ������  
		if(findParent(a) != findParent(b)){
			unionParent(a, b); // ���� �������� ��ġ�� 
			if(isDown != 1) count++; // �������� ���� ���� 
		}
	}

	return pow(count, 2); // k_max ^ 2
}

int getBestCase(){
	// �θ� ���̺� �ʱ�ȭ 
	for(int i = 1; i <= n; i++){
		parent[i] = i;  
	}

	int count = 0; // ���������� ���� 
	for(int i = edges.size() - 1; i >= 0; i--){ // �������� ���� �߰� (������ ���)
		int isDown = edges[i].first; // 1�̸� ��������, 0�̸� �������� 
		int a = edges[i].second.first; 
		int b = edges[i].second.second; 

		// ����Ŭ�� �߻����� ������  
		if(findParent(a) != findParent(b)){
			unionParent(a, b); // ���� �������� ��ġ�� 
			if(isDown != 1) count++; // �������� ���� ���� 
		}
	}

	return pow(count, 2); // k_min ^ 2
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	// ������ ������ ���� 
	cin >> n >> m; 

	// �Ա��� 1�� �ǹ� ���� �������
	int a, b, c; 
	cin >> a >> b >> c; 
	edges.push_back({c, {a, b}}); // c�� 0�̸� ��������, 1�̸� �������� 

	// ��� ���� ���� �Է� 
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c; 
		edges.push_back({c, {a, b}});
	}

	int max = getWorstCase(); 
	int min = getBestCase(); 
	cout << max - min;

	return 0; 
}