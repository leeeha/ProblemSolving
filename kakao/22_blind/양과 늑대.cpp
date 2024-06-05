#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> pii; 

const int MAX = 18;
vector<int> tree[MAX];
vector<int> type; 
bool visited[MAX][MAX][MAX];
int ans = 0;

void dfs(int now, int s, int w){
    if(visited[now][s][w]) return; 
    visited[now][s][w] = true;
    
    // 현재 모은 양, 늑대 개수 저장 
    int ps = s, pw = w;
    // 현재 노드의 타입 저장 (양, 늑대)
    int pt = type[now];
    
    // 양 또는 늑대 개수 갱신 
    if(pt == 0) s++;
    else if(pt == 1) w++;
    type[now] = -1; // 다음에 중복해서 계산하지 않도록 
    
    // 양의 개수가 더 많을 때만 재귀호출 (가지치기)
    if(s > w){
        ans = max(ans, s); // 양의 최대 개수 갱신 
        for(auto next: tree[now]){
            dfs(next, s, w);
        }
    }
    
    // 상태 복구 
    type[now] = pt;
    visited[now][ps][pw] = false;
}

int solution(vector<int> info, vector<vector<int>> edges) {    
    // 부모와 자식 간의 양방향 연결 
    for(auto e: edges){
        tree[e[0]].push_back(e[1]);
        tree[e[1]].push_back(e[0]);
    }
    
    // 전역 변수 초기화 
    type = info;
    
    dfs(0, 0, 0);
    
    return ans;
}