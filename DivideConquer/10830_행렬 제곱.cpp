#include <iostream>
#include <vector> 
using namespace std;

typedef long long ll; 
typedef vector<vector<ll>> matrix; 

// ����� ������ ���� ������ �����ε� 
matrix operator * (const matrix& a, const matrix& b){
	int size = a.size(); // 2 �� N ��  5 
	matrix res(size, vector<ll>(size)); // ������� 
    
	for(int i = 0; i < size; i++){ 
		for(int j = 0; j < size; j++){
			for(int k = 0; k < size; k++){
				// ��� A�� i��, ��� B�� j�� ���г��� ���ؼ� ���Ѵ�. 
                // �຤�Ϳ� �������� ���� 
				res[i][j] += a[i][k] * b[k][j]; 
			}
			res[i][j] %= 1000; 
		}
	}
    
	return res; 
}

matrix power(matrix a, ll b){
	int size = a.size();
	matrix res(size, vector<ll>(size)); // ������� 

	// �׵���� ���ص� �ڱ� �ڽ��� ������ �ϴ� �� 
	// ���� ������ ���� �׵���� 1 
	// ��� ������ ���� �׵���� ���� ��� (res�� �ʱⰪ���� ����) 
	for(int i = 0; i < size; i++){
		res[i][i] = 1; // ���� ��� 
	}

	while(b > 0){
		// b�� Ȧ���� ���� ���� �ϳ� ������ b�� ¦���� �����
		// �� ���� ������� ���Ѵ�. 
		if(b % 2 == 1){
			b -= 1; 
			res = res * a; // ����� ���� 
		}else{
			// b�� ¦���� ���� ���� �����ϰ� b�� 2�� ������.
			a = a * a; // ����� ���� 
			b /= 2; 
		}
	}

	return res; // a�� b���� ��ȯ 
}

void printMatrix(const matrix& a){
	int size = a.size();
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n"; 
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; // ����� ũ�� (2 �� N ��  5) 
	ll b;  // ���� (1 �� B �� 100,000,000,000)
	cin >> n >> b;

	matrix a(n, vector<ll>(n)); // ������� 

	// ����� �� ���� 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j]; 
		}
	}

	// a�� b���� ��� 
	printMatrix(power(a, b)); 
	
	return 0;
}