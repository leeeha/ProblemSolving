#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 26; 
int freqA[MAX];
int freqB[MAX];

int main(void) {
	ios::sync_with_stdio(0);
    cin.tie(0);

	string a, b;
	cin >> a >> b;
 
	for(int i = 0; i < a.size(); i++){
		int idx = a[i] - 'a'; 
		freqA[idx]++; 
	}

	for(int i = 0; i < b.size(); i++){
		int idx = b[i] - 'a'; 
		freqB[idx]++; 
	}

	int ans = 0; 
	for(int i = 0; i < MAX; i++){
		if(freqA[i] != freqB[i]){
			int gap = abs(freqA[i] - freqB[i]);
			ans += gap;
		}
	}

	cout << ans; 
	
	return 0;
}
