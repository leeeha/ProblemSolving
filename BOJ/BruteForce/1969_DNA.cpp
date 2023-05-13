#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
#include <map> 
using namespace std;

int N, M;
vector<string> v; 
map<char, int> m; 

void initMap() { 
	m['A'] = 0; 
	m['C'] = 0; 
	m['G'] = 0; 
	m['T'] = 0; 
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	initMap(); 

	cin >> N >> M; 

	for(int i = 0; i < N; i++){
		string s; 
		cin >> s; 
		v.push_back(s); 
	}

	string str = ""; 
	int hammingDist = 0; 
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			// 행 변화, 열 고정 
			char ch = v[j][i]; 
			
			// 각 문자의 등장 횟수 갱신 
			m[ch] += 1; 
		}

		// 각 열에 대해 빈도수가 가장 높은 문자를 구한다.
		// 전체 행의 개수에서 해당 빈도수를 빼면, 그 열에 대한 해밍 거리를 구할 수 있다. 
		int maxFreq = -1; 
		char temp = 'A';
		for(auto e: m){
			int freq = e.second; 
	
			// 빈도수가 동일한 경우에는 
			// 사전 순으로 앞에 오는 문자가 먼저 temp에 저장된다. 
			if(freq > maxFreq){ 
				maxFreq = freq; 
				temp = e.first; 
			}
		}

		str += temp;
		hammingDist += (N - maxFreq);
		
		initMap();
	}

	cout << str << "\n" << hammingDist; 
	
	return 0;
}