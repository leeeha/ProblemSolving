#include <iostream>
using namespace std;

int recursiveCount; 
int dpCount; 

// �ռ� ���� ����� �����ϱ� ���� DP ���̺�
long long d[100];

int fibo(int x){ // O(2^N)
	if(x == 1 || x == 2){
		recursiveCount++; 
		return 1; 
	}
	
	return fibo(x - 1) + fibo(x - 2);
}

int fibonacci(int n){ // O(N) 
	d[1] = 1; 
    d[2] = 1; 
	
    for (int i = 3; i <= n; i++) { 
		dpCount++; 
        d[i] = d[i - 1] + d[i - 2];
    }

	return d[n]; 
}


int main() {
	int n; 
	cin >> n;

	int recursiveResult = fibo(n); 
	int dpResult = fibonacci(n); 

	cout << recursiveCount << " " << dpCount << endl; 

    return 0;
}