#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std; 

string vowels = "AEIOU";
int answer = 0, cnt = 0; 

void dfs(string now, string target){
	if(now == target) {
		answer = cnt;
	}
	
	if(now.size() > 5) {
		return; 
	}

	cnt++;

	for(int i = 0; i < vowels.size(); i++){
		dfs(now + vowels[i], target);
	}
}

int solution(string word){
	dfs("", word); 
	return answer; 
}