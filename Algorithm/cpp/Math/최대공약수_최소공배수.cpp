/** 
유클리드 호제법으로 최대 공약수 구하기
두 자연수 A, B에 대하여 (A > B) A를 B로 나눈 나머지를 R이라고 했을 때,
A와 B의 최대공약수는 B와 R의 최대공약수와 같다.
*/
int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	} else {
		return gcd(b, a % b);
	}
}

// 최소 공배수 = (두 수의 곱) / 최대 공약수 	
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

// N개의 최소 공배수 
int solution(int* arr, int n) {
	int ans = arr[0];
	for (int i = 1; i < n; i++) {
		ans = lcm(ans, arr[i]); 
	}
	return ans;
}