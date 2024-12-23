class Solution {
    val dx = listOf(0, 0, 1, -1)
    val dy = listOf(1, -1, 0, 0)
    lateinit var visited: Array<BooleanArray>
    lateinit var graph: Array<String>
    var N = 0 
    var M = 0 
    var sum = 0 
    
    fun solution(maps: Array<String>): IntArray {
        var answer = mutableListOf<Int>()
        N = maps.size 
        M = maps[0].length 
        visited = Array(N) { BooleanArray(M) {false} }
        graph = maps 
        
        for(i in maps.indices){
            for(j in maps[i].indices){
                if(maps[i][j] != 'X' && !visited[i][j]){
                    dfs(i, j)
                    answer.add(sum)
                    sum = 0
                }
            }
        }
        
        return if(answer.isEmpty()) intArrayOf(-1)
        else answer.sorted().toIntArray()
    }
    
    fun dfs(x: Int, y: Int) {
        sum += graph[x][y] - '0'
        visited[x][y] = true
        
        for(i in 0..3){
            val nx = x + dx[i]
            val ny = y + dy[i]
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue 
            if(graph[nx][ny] == 'X') continue 
            
            if(!visited[nx][ny]){
                dfs(nx, ny)
            }
        }
    }
}