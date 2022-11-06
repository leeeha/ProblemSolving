#include <iostream>
#include <vector> 
using namespace std;

typedef long long ll; 
typedef vector<vector<ll>> matrix; 

// 행렬의 곱셈을 위한 연산자 오버로딩 
matrix operator * (const matrix& a, const matrix& b){
	int size = a.size(); // 2 ≤ N ≤  5 
	matrix res(size, vector<ll>(size)); // 정방행렬 
    
	for(int i = 0; i < size; i++){ 
		for(int j = 0; j < size; j++){
			for(int k = 0; k < size; k++){
				// 행렬 A의 i행, 행렬 B의 j열 성분끼리 곱해서 더한다. 
                // 행벡터와 열벡터의 내적 
				res[i][j] += a[i][k] * b[k][j]; 
			}
			res[i][j] %= 1000; 
		}
	}
    
	return res; 
}

matrix power(matrix a, ll b){
	int size = a.size();
	matrix res(size, vector<ll>(size)); // 정방행렬 

	// 항등원은 곱해도 자기 자신이 나오게 하는 수 
	// 정수 곱셈에 대한 항등원은 1 
	// 행렬 곱셈에 대한 항등원은 단위 행렬 (res의 초기값으로 설정) 
	for(int i = 0; i < size; i++){
		res[i][i] = 1; // 단위 행렬 
	}

	while(b > 0){
		// b가 홀수일 때는 밑을 하나 꺼내서 b를 짝수로 만들고
		// 그 밑은 결과값에 곱한다. 
		if(b % 2 == 1){
			b -= 1; 
			res = res * a; // 행렬의 곱셈 
		}else{
			// b가 짝수일 때는 밑을 제곱하고 b를 2로 나눈다.
			a = a * a; // 행렬의 곱셈 
			b /= 2; 
		}
	}

	return res; // a의 b제곱 반환 
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

	int n; // 행렬의 크기 (2 ≤ N ≤  5) 
	ll b;  // 지수 (1 ≤ B ≤ 100,000,000,000)
	cin >> n >> b;

	matrix a(n, vector<ll>(n)); // 정방행렬 

	// 행렬의 각 원소 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j]; 
		}
	}

	// a의 b제곱 출력 
	printMatrix(power(a, b)); 
	
	return 0;
}