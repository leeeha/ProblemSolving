#include <iostream> 
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n, m; // �ִ� 10�� 
	cin >> n >> m; 

	// �־��� ��� 1000�� 10���� ���ϹǷ�, ���� ���� Ÿ���� long������ ���� 
	vector<long> psum(n+1); 
	psum[0] = 0; 
	for(int i = 1; i <= n; i++){ 
		int val; 
		cin >> val; 
		psum[i] = psum[i - 1] + val; // ���� �� 
	}
	
	while(m--){ 
		int i, j; 
		cin >> i >> j;
		
		// i���� j������ ���� �� ���ϱ� 
		cout << psum[j] - psum[i - 1] << "\n"; 
	}
	
	return 0;
}
