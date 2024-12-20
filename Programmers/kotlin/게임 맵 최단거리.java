import java.util.*;

class Point { 
    int x; 
    int y; 
    int dist; // 시작점으로부터의 이동 거리 
    
    Point(int x, int y, int dist){
        this.x = x; 
        this.y = y; 
        this.dist = dist; 
    }
}

class Solution {
    final int MAX = 101;
    final int INF = Integer.MAX_VALUE; 
    int N = 0, M = 0; 
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int[][] arr = new int[MAX][MAX];
    boolean[][] visited = new boolean[MAX][MAX];
    int answer = INF; 
    
    public int solution(int[][] maps) {
        arr = maps;
        N = maps.length; 
        M = maps[0].length; 
        
        bfs(0, 0);
        
        if(answer == INF) return -1;
        else return answer + 1; // 이동 거리가 아니라 칸의 개수니까 +1 
    }
    
    void bfs(int a, int b) {
        ArrayDeque<Point> q = new ArrayDeque<Point>();
        q.offer(new Point(a, b, 0));
        visited[a][b] = true;
        
        while(!q.isEmpty()){
            Point point = q.poll();
            int x = point.x; 
            int y = point.y; 
            int dist = point.dist; 
            
            if(x == N-1 && y == M-1){
                answer = dist;
                return;
            }
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; 
                
                // 벽은 이동 불가 
                if(arr[nx][ny] == 0) continue; 
                
                if(!visited[nx][ny]){
                    q.offer(new Point(nx, ny, dist + 1));
                    visited[nx][ny] = true; 
                }
            }
        }
    }
}