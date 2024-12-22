import java.util.ArrayDeque 
import kotlin.math.*

/*
S -> L -> E 
최소 이동 시간 구하기 
*/
class Solution {
    lateinit var graph: Array<String>
    lateinit var visited: Array<Array<Boolean>> 
    val dx = listOf(1, -1, 0, 0)
    val dy = listOf(0, 0, -1, 1)
    var answer = 0 
    var N = 0
    var M = 0 
    var sx = 0 
    var sy = 0 
    var lx = 0
    var ly = 0 
    
    fun solution(maps: Array<String>): Int {
        N = maps.size 
        M = maps[0].length 
        graph = maps 
        visited = Array(N) {Array(M){false}}
        
        for(i in 0..N-1){
            for(j in 0..M-1){
                if(graph[i][j] == 'S'){
                    sx = i
                    sy = j 
                }
                
                if(graph[i][j] == 'L'){
                    lx = i
                    ly = j 
                }
            }
        }
        
        // S -> L 최소 시간 
        val t1 = bfs(sx, sy, 'L')
        if(t1 == -1) return -1 
        
        // 방문 배열 초기화 (다음 탐색에서 재방문 가능하도록)
        visited = Array(N) {Array(M){false}}
        
        // L -> E 최소 시간 
        val t2 = bfs(lx, ly, 'E')
        return if(t2 == -1) -1 else t1 + t2
    }
    
    fun bfs(a: Int, b: Int, target: Char): Int {
        val q = ArrayDeque<Node>()
        q.offer(Node(a, b, 0))
        visited[a][b] = true
        
        while(!q.isEmpty()){
            val node = q.poll()
            val x = node.x
            val y = node.y
            val time = node.time
            
            if(graph[x][y] == target){
                return time 
            }
            
            for(i in 0..3){
                val nx = x + dx[i]
                val ny = y + dy[i]
                
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue 
                if(graph[nx][ny] == 'X') continue
                
                if(!visited[nx][ny]){
                    q.offer(Node(nx, ny, time + 1))
                    visited[nx][ny] = true 
                }
            }
        }
        
        return -1 
    }
}

data class Node(
    val x: Int, 
    val y: Int, 
    val time: Int
)