#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
#include <cmath>
#define MAX 1001 
using namespace std;

int n, m, k; // ����, ����, �������� ����  
int parent[MAX]; // ��Ʈ ��带 �����ϴ� ���̺� 
bool elec[MAX]; // �����Ұ� ��ġ�� ���� ǥ�� 
vector<pair<int, pair<int, int>>> edges; // ���� ���� 
int result = 0; // �ּ� ��� 

int findParent(int x){
	// ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��� ȣ�� 
	if(x == parent[x]) return x; 
	return parent[x] = findParent(parent[x]); 
}

void unionParent(int cost, int a, int b){
	a = findParent(a);
	b = findParent(b);

	// �� ���� ��� �����ҿ� ����� ��� 
	if(elec[a] && elec[b])
		return; 
	// �� �߿� �ϳ��� �����ҿ� ����� ��� 
	else if(elec[a] && !elec[b]){
		// �����Ұ� �ִ� ������ ���� 
		parent[b] = a;
		result += cost; 
	}else{
		parent[a] = b;
		result += cost; 
	}
}

void solution(){
	// ���� ��뿡 ���� �������� ���� 
	sort(edges.begin(), edges.end()); 

	// �θ� ���̺� �ʱ�ȭ 
	for(int i = 1; i <= n; i++){
		parent[i] = i;  
	}

	for(int i = 0; i < edges.size(); i++){
		int cost = edges[i].first; 
		int u = edges[i].second.first; 
		int v = edges[i].second.second; 

		// ����Ŭ�� �������� �����鼭 
		if(findParent(u) != findParent(v)){
			// �����ҿ� ����Ǿ� ���� ���� ������ ������ ����! 
			unionParent(cost, u, v);
		}
	}

	cout << result; // �ּ� ��� ��� 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 

	// ����, ����, �������� ���� 
	cin >> n >> m >> k; 

	// �����Ұ� ��ġ�� ���� ǥ���ϱ� 
	for(int i = 0; i < k; i++){ 
		int idx;
		cin >> idx; 
		elec[idx] = true; 
	} 

	// ���� ���� �Է� 
	for(int i = 0; i < m; i++){
		int u, v, w; 
		cin >> u >> v >> w; 
		edges.push_back({w, {u, v}});
	}

	solution(); 

	return 0; 
}