#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m; // 최대 20 
int k; // 새로운 맵의 크기 
int cnt = 0; // 자물쇠의 홈 개수 
vector<vector<int>> board;

void initBoard(vector<vector<int>> lock) {
    int lx = 0, ly = 0; 
    for(int i = m - 1; i < k - m + 1; i++, lx++){
        for(int j = m - 1; j < k - m + 1; j++, ly++){
            // 자물쇠의 홈, 돌기 표시 
            board[i][j] = lock[lx][ly];
            
            // 자물쇠 홈의 개수 카운팅 
            if(board[i][j] == 0) cnt++;
        }
        ly = 0; 
    }
}

int countMatchingPoint(int i, int j, vector<vector<int>> key){
    int kx = 0, ky = 0;
    int point = 0;
    
    for(int x = i; x < i + m; x++, kx++){
        for(int y = j; y < j + m; y++, ky++){
            if(board[x][y] == 1 && key[kx][ky] == 1) return -1; 
            if(board[x][y] == 0 && key[kx][ky] == 0) return -1; 
            if(board[x][y] == 0 && key[kx][ky] == 1) point++; 
        }
        ky = 0;
    }
    
    return point;
}

void rotateKey(vector<vector<int>>& key) {
    vector<vector<int>> temp = key; 
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            temp[j][m - 1 - i] = key[i][j];
        }
    }
    
    key = temp; // 원본 배열 변경 
}

bool isPossibleKey(vector<vector<int>> key){
    for(int dir = 0; dir < 4; dir++){
        // 열쇠를 이동시키면서 
        for(int i = 0; i < m + n - 1; i++){
            for(int j = 0; j < m + n - 1; j++){
                // 열쇠의 돌기 & 자물쇠의 홈 -> 매칭 개수 세기 
                int result = countMatchingPoint(i, j, key);
                if(result == cnt) return true;
            }
        }
        
        // 열쇠 회전시키기 
        rotateKey(key);
    }
    
    return false; 
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = lock.size();
    m = key.size();
    k = n + 2 * (m - 1);
    
    // 자물쇠가 아닌 영역은 2로 표시 
    board.resize(k, vector<int>(k, 2)); 
    
    // 맵 초기화 
    initBoard(lock);
    
    return isPossibleKey(key);
}
