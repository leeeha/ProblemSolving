#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 10001
using namespace std;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n;

	int count[MAX] {0};

	for(int i = 0; i < n; i++){
		int x; 
		cin >> x; 

		// x�� �Էµ� Ƚ�� ī���� 
		count[x] += 1; 
	}

	// i�� j�� ��� 
	for(int i = 1; i < MAX; i++){
		for(int j = 0; j < count[i]; j++){
			cout << i << "\n"; 
		}
	}

    return 0;
}