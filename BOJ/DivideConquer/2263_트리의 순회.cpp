#include <iostream>
using namespace std;

int Index[1000001];
int inorder[1000001];
int postorder[1000001];
int n; 

// ����, ���� ��ȸ�� ���۰� �� �ε��� 
void getPreorder(int inStart, int inEnd, int postStart, int postEnd){
	// �� �̻� ������ �� ������ ��� ȣ�� ���� 
	if(inStart > inEnd || postStart > postEnd){
		return; 
	}

	// ���� ��ȸ���� ��Ʈ ����� ��ġ �˾Ƴ��� 
	int rootIndex = Index[postorder[postEnd]];
	int leftSize = rootIndex - inStart; 
	int rightSize = inEnd - rootIndex;

	// ���� ��ȸ���� ��Ʈ ����� �� ��� 
	cout << inorder[rootIndex] << " "; 

	// recur left : ����, ���� ��ȸ���� left �κ��� ���۰� �� �ε����� ��������  
	getPreorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1); 

	// recur right: ����, ���� ��ȸ���� right �κ��� ���۰� �� �ε����� �������� 
	getPreorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1); 
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> inorder[i]; 

		// ���� ��ȸ�� �� ���ҿ� �ش��ϴ� �ε����� �����صд�. 
		// ���߿� ��Ʈ ����� �ε����� �˾Ƴ��� ���� 
		Index[inorder[i]] = i; 
	}

	for(int i = 1; i <= n; i++){
		cin >> postorder[i]; 
	}

	getPreorder(1, n, 1, n);
	
	return 0;
}