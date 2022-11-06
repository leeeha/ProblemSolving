#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
#include <cmath>
#define MAX 1001 
using namespace std;

int n; // ���� ���� 
int parent[MAX]; // ��Ʈ ��带 �����ϴ� ���̺� 
vector<pair<float, float>> coord; // ���� ��ǥ 
vector<pair<float, pair<int, int>>> edges; // ���� a�� b ������ �Ÿ� c
float result = 0; // �ּ� ��� 

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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n; // ���� ���� 
	
	for(int i = 0; i < n; i++){
		parent[i] = i; // �θ� ���̺� �ʱ�ȭ 
	}

	for(int i = 0; i < n; i++){
		float x, y; 
		cin >> x >> y; 
		coord.push_back({x, y}); // ���� ��ǥ 
	}

	for(int i = 0; i < n; i++){
		float x1 = coord[i].first; 
		float y1 = coord[i].second; 

		for(int j = i + 1; j < n; j++){
			float x2 = coord[j].first; 
			float y2 = coord[j].second; 
            
            // �� ���� ������ �Ÿ� ���ϱ� 
			float dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
			edges.push_back({dist, {i, j}}); 
		}
	}

	// ������ ��뿡 ���� �������� ���� 
	sort(edges.begin(), edges.end()); 

	for(int i = 0; i < edges.size(); i++){
		float cost = edges[i].first; 
		int a = edges[i].second.first; 
		int b = edges[i].second.second; 
        
		if(findParent(a) != findParent(b)){
			unionParent(a, b);
			result += cost; 
		}
	}

	cout << result; 

	return 0; 
}