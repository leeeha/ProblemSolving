#include <iostream>
using namespace std;

int Index[1000001];
int inorder[1000001];
int postorder[1000001];
int n; 

// 중위, 후위 순회의 시작과 끝 인덱스 
void getPreorder(int inStart, int inEnd, int postStart, int postEnd){
	// 더 이상 분할할 수 없으면 재귀 호출 종료 
	if(inStart > inEnd || postStart > postEnd){
		return; 
	}

	// 중위 순회에서 루트 노드의 위치 알아내기 
	int rootIndex = Index[postorder[postEnd]];
	int leftSize = rootIndex - inStart; 
	int rightSize = inEnd - rootIndex;

	// 중위 순회에서 루트 노드의 값 출력 
	cout << inorder[rootIndex] << " "; 

	// recur left : 중위, 후위 순회에서 left 부분의 시작과 끝 인덱스를 바탕으로  
	getPreorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1); 

	// recur right: 중위, 후위 순회에서 right 부분의 시작과 끝 인덱스를 바탕으로 
	getPreorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1); 
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> inorder[i]; 

		// 중위 순회의 각 원소에 해당하는 인덱스를 저장해둔다. 
		// 나중에 루트 노드의 인덱스를 알아내기 위해 
		Index[inorder[i]] = i; 
	}

	for(int i = 1; i <= n; i++){
		cin >> postorder[i]; 
	}

	getPreorder(1, n, 1, n);
	
	return 0;
}