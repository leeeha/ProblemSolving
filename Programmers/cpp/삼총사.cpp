// https://school.programmers.co.kr/learn/courses/30/lessons/131705?language=cpp

#include <vector>
using namespace std;

int solution(vector<int> number) {
    int answer = 0;
	int length = number.size();
	
	for(int i = 0; i < length - 2; i++) {
		for(int j = i + 1; j < length - 1; j++){
			for(int k = j + 1; k < length; k++){
				if(number[i] + number[j] + number[k] == 0){
					answer++;
				}
			}
		}
	}
	
    return answer;
}