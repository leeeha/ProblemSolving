import java.util.*
import kotlin.math.*
typealias PII = Pair<Int, Int>

class Solution {
    val INF = 1e9.toInt()
    lateinit var graph: MutableList<MutableList<Int>>
    lateinit var dist: MutableList<Int>
    
    fun solution(n: Int, edges: Array<IntArray>): Int {
        graph = MutableList(n + 1) { mutableListOf<Int>() }
        dist = MutableList(n + 1) { INF }
        
        for(e in edges){
            graph[e[0]].add(e[1])
            graph[e[1]].add(e[0])
        }
        
        // 1번 노드에서 모든 노드까지의 최단 거리 
        dijkstra(1)
        
        // 1번 노드로부터의 가장 먼 노드의 거리 
        var maxDist = 0
        for(i in 1..n){
            if(dist[i] != INF){
                maxDist = max(maxDist, dist[i])
            }
        }
        
        return dist.filter { it == maxDist }.size
    }
    
    fun dijkstra(startNode: Int) {
        // 노드 번호, 거리 (거리 기준으로 최소 힙)
        val pq = PriorityQueue<PII>(compareBy { it.second })
        
        // 시작 노드 방문 처리 
        pq.offer(Pair(startNode, 0))
        dist[startNode] = 0
    
        while(pq.isNotEmpty()){
            val curNum = pq.peek().first
            val curDist = pq.peek().second
            pq.poll()
    
            // 이미 확정된 최단 경로는 무시 
            if(curDist > dist[curNum]) continue
    
            // 인접 노드 확인 
            for(nextNum in graph[curNum]){
                // 최단 거리 테이블 갱신 
                if(dist[nextNum] > curDist + 1){
                    dist[nextNum] = curDist + 1 
                    pq.offer(Pair(nextNum, curDist + 1))
                }
            }
        }
    }
}