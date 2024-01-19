/**
루트 노드를 찾는 Find 연산 
서로 다른 루트 노드를 합치는 Union 연산 
*/

#include <iostream>
using namespace std;

// 각 정점의 부모 노드 번호를 저장하는 배열 (최종적으로는 루트 노드 번호)
int parent[8]; 

// 루트 노드를 찾는 Find 연산
int Find(int x) {
	// 배열의 인덱스와 값이 같다면 루트 노드 발견!
	if (x == parent[x]) return x;

	// 부모 노드의 번호를 전달하면서, 루트 노드를 찾을 때까지 재귀 호출 반복
	return parent[x] = Find(parent[x]);
}

// 두 노드를 같은 집합으로 합치는 Union 연산
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	// 루트 노드가 같다면 이미 연결되어 있는 것
	if (x == y) return;

	// 더 작은 값이 부모 노드가 될 수 있도록
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

// 두 노드가 연결되어 있는지 판별하는 함수
bool isUnion(int x, int y) {
	x = Find(x);
	y = Find(y);

	// 루트 노드가 같은지 확인
	return (x == y);
}

int main() {
	for (int i = 1; i <= 7; i++)
		parent[i] = i;

	Union(1, 2); // p[2] = 1
	Union(4, 5); // p[5] = 4
	Union(5, 6); // p[6] = 4 (5번이 아니라 4번 저장)
	cout << "2와 4는 같은 집합인가? " << isUnion(2, 4) << "\n"; // false

	Union(1, 4); // p[4] = 1
	cout << "2와 4는 같은 집합인가? " << isUnion(2, 4) << "\n"; // true

	return 0;
}