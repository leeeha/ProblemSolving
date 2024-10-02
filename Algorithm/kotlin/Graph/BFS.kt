import java.util.*

val MAX = 101
val graph = MutableList<MutableList<Int>>(MAX) { mutableListOf() }
val visited = MutableList(MAX) { false }

fun bfs(start: Int){
    val q = ArrayDeque<Int>()
    q.offer(start)
    visited[start] = true
    
    while(!q.isEmpty()){
        val x = q.peek()
        q.pop()
        print("$x ")
        
        for(y in graph[x]){
            if(!visited[y]){
                q.offer(y)
                visited[y] = true 
            }
        }
    }
}

fun main() {
    graph[1].add(2)
    graph[1].add(3)
    graph[1].add(8)
    
    graph[2].add(1)
    graph[2].add(7)
    
    graph[3].add(1)
    graph[3].add(4)
    graph[3].add(5)
    
    graph[4].add(3)
    graph[4].add(5)
    
    graph[5].add(3)
    graph[5].add(4)
    
    graph[6].add(7)
    
    graph[7].add(2)
    graph[7].add(6)
    graph[7].add(8)
    
    graph[8].add(1)
    graph[8].add(7)
    
	bfs(1) // 1 2 3 8 7 4 5 6 
}