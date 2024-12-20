/*
주어진 항공권을 모두 사용하는 여행경로 구하기 
가능한 경로가 2개 이상이면, 알파벳 순서가 앞서는 경로 리턴 
시작 노드는 ICN으로 고정
한번 방문한 간선은 재방문하지 않도록 visited 배열 사용 
*/
class Solution {
    lateinit var graph: Array<Array<String>> 
    lateinit var visited: BooleanArray 
    val answer = mutableListOf<String>()
    var foundFirstCase = false
    var ticketSize = 0
    
    fun solution(tickets: Array<Array<String>>): Array<String> {
        ticketSize = tickets.size
        graph = tickets
        visited = BooleanArray(ticketSize) { false }
        
        // 목적지 문자열에 따라 정렬 
        graph.sortBy { ticket -> ticket[1] }
        
        dfs(0, "ICN")
        
        return answer.toTypedArray()
    }
    
    fun dfs(idx: Int, now: String){
        if(idx == ticketSize && !foundFirstCase){
            foundFirstCase = true
            answer.add(now)
            return 
        }
        
        for(ticketIdx in graph.indices){
            val start = graph[ticketIdx][0]
            val end = graph[ticketIdx][1]
            
            if(start == now && !visited[ticketIdx]){
                visited[ticketIdx] = true
                answer.add(start)
                
                dfs(idx + 1, end)
                
                if(foundFirstCase) return 
                
                visited[ticketIdx] = false
                answer.removeLast()
            }
        }
    }
}
