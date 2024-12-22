import java.util.ArrayDeque 

data class Node(
    val x: Int, 
    val y: Int, 
    val moveCnt: Int
)

class Solution {
    lateinit var visited: Array<Array<Boolean>> 
    lateinit var graph: Array<String>
    val INF = Int.MAX_VALUE
    val dx = listOf(1, -1, 0, 0)
    val dy = listOf(0, 0, -1, 1)
    var answer = INF
    var N = 0 
    var M = 0 

    fun solution(board: Array<String>): Int {
        N = board.size 
        M = board[0].length  
        visited = Array(N) { Array(M) { false } }
        graph = board 
        
        for(i in 0 until board.size){
            for(j in 0 until board[i].length){
                if(board[i][j] == 'R'){
                    bfs(i, j)
                    break 
                }
            }
        }
        
        return if(answer == INF) -1 else answer 
    }
    
    fun bfs(a: Int, b: Int){
        val q = ArrayDeque<Node>()
        q.offer(Node(a, b, 0))
        visited[a][b] = true 
        
        while(!q.isEmpty()){
            val node = q.poll() 
            val x = node.x 
            val y = node.y 
            val moveCnt = node.moveCnt 
            
            if(graph[x][y] == 'G'){
                answer = moveCnt
                return
            }
            
            for(i in 0..3){
                // 상하좌우 방향 설정 
                var nx = x + dx[i]
                var ny = y + dy[i]
                
                // 멈출 수 있을 때까지 위치 이동 
                while(!possibleStop(nx, ny)){
                    nx += dx[i]
                    ny += dy[i]
                }
                
                nx -= dx[i]
                ny -= dy[i]
                
                if(!visited[nx][ny]){
                    q.offer(Node(nx, ny, moveCnt + 1))
                    visited[nx][ny] = true 
                }
            }
        }
    }
    
    fun possibleStop(nx: Int, ny: Int) = 
        nx < 0 || nx >= N || ny < 0 || ny >= M || graph[nx][ny] == 'D'
}