// https://school.programmers.co.kr/learn/courses/30/lessons/135808

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end(), greater<int>());
	
	int num = score.size() / m;
	for(int i = 1; i <= num; i++) {
		int min = score[m * i - 1];
		if(min <= k) {
			answer += min * m;
		}
	}
    
    return answer;
}

int main() {
	vector<int> score {4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2};

	int answer = solution(4, 3, score);
	cout << answer << endl;
	
	return 0;
}