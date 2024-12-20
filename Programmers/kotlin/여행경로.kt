import java.util.*

/**
주어진 항공권을 이용해서 만들 수 있는 모든 경로 중에서 
알파벳 순으로 가장 앞서는 것을 정답으로! 
출발 노드는 ICN (노드 최대 1만개)
*/
class Solution {
    var answer = arrayListOf<String>()
    lateinit var graph: Array<Array<String>>
    lateinit var visited: BooleanArray
    val temp = arrayListOf<String>()
    var N = 0
    var findFirstCase = false
    
    fun solution(tickets: Array<Array<String>>): Array<String> {
        // 전역 변수 초기화 
        N = tickets.size
        graph = tickets
        visited = BooleanArray(tickets.size) { false }
        
        // 목적지 문자열에 따라 사전순 정렬
        tickets.sortBy { ticket -> ticket[1] }
        
        dfs(0, "ICN")
        
        return answer.toTypedArray()
    }
    
    fun dfs(cnt: Int, now: String){
        if(cnt == N && !findFirstCase){
            findFirstCase = true
            
            // 현재 경로의 모든 노드 추가 
            answer.addAll(temp) 
            
            // 마지막 도착 노드 추가 
            answer.add(now) 
            return
        }
        
        for(i in graph.indices){
            val start = graph[i][0]
            val end = graph[i][1]
            
            if(start == now && !visited[i]){
                // 현재 간선에 대한 방문 처리 
                visited[i] = true
                temp.add(start) // 시작 노드 저장 
                dfs(cnt + 1, end) // 도착 노드로 이동 
                
                // 다음 경우의 수를 위한 상태 복구 
                visited[i] = false
                temp.removeLast()
            }
        }
    }
}
