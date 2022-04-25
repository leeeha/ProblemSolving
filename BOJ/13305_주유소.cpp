#include <iostream>
#include <vector>
using namespace std;

// 각 거리와 비용의 최댓값이 10억이므로, 그 둘을 곱한 total 변수는 8바이트 크기로 선언해야 한다는 게 이해되는데
// 벡터 d와 c, 변수 min까지 왜 long long이어야 통과될까??
// 간단한 그리디 문제라는데, 나한텐 코드 작성하는 게 쉽지 않았다. 그리디 문제를 더 많이 풀어봐야겠다!!!

int main()
{	
	int n; // 도시 개수 (최대 10만)
	cin >> n;
	
	int tmp;
	vector<long long> d; // 인접한 도시 간의 거리 (최대 10억)
	for(int i = 0; i < n - 1; i++){ // n-1개
		cin >> tmp;
		d.push_back(tmp);
	}
	
	vector<long long> c; // 각 주유소의 리터당 가격 (최대 10억)
	for(int i = 0; i < n; i++){ // n개
		cin >> tmp;
		c.push_back(tmp);
	}

	long long min = c[0];
	long long total = c[0] * d[0]; // 첫번째 지점에서는 주유 필수 

	// 인접한 두 도시의 리터당 가격을 비교하고,
	// 가격이 더 적은 곳에서 많은 양을 주유할 수 있도록!
	for(int i = 1; i < n-1; i++){ // c[n-1]은 크기 검사X 
		if(min > c[i]){
			min = c[i];
			total += min * d[i];
		}else{
			total += min * d[i];
		}
	}

	cout << total << endl;
	
	return 0;
}