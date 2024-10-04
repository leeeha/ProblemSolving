#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 50;
int answer = MAX;
bool visited[MAX];

string g_target; 
vector<string> g_words; 

// 한 개의 문자만 다른지 확인한다. (유망성 판단)
bool possible(string a, string b) {
    int cnt = 0; 

    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) cnt++;
    }

    if(cnt == 1) return true; 
    else return false; 
}

void dfs(string currentWord, int step){ 
    if(answer <= step) return; 

    // target과 일치하면 
    if(currentWord == g_target){ 
        // 최소 변환 횟수 갱신하고 현재 가지에 대한 탐색 종료 
        answer = min(answer, step); 
        return; 
    }

    for(int i = 0; i < g_words.size(); i++){
        string candidate = g_words[i];

        // 문자 하나만 다르고 방문하지 않은 단어라면 재귀 호출 
        if(possible(currentWord, candidate) && !visited[i]){
            visited[i] = true; // 상태 변화 
            dfs(candidate, step + 1); // 탐색할 단어, 단계 갱신 
            visited[i] = false; // 상태 복구 (다음 경우의 수를 위해) 
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    g_target = target; 
    g_words = words; 

    dfs(begin, 0); 

    // target 단어로 변환할 수 없는 경우 
    if(answer == MAX) return 0;

    return answer; 
}