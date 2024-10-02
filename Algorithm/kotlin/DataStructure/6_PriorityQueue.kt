import java.util.*

fun main() {
    val minHeap = PriorityQueue<Int>() // 기본적으로 최소 힙 
    minHeap.addAll(listOf(1, 2, 3, 4, 5))
    println(minHeap) // [1, 2, 3, 4, 5]
    println(minHeap.peek()) // 1
    println(minHeap.contains(4)) // true 
    
    // 작은 값부터 삭제 
    while(!minHeap.isEmpty()){
        print(minHeap.poll())
    }
    println()
    
    val maxHeap = PriorityQueue<Int>(reverseOrder()) // 최대 힙
    maxHeap.addAll(listOf(1, 2, 3, 4, 5))
    println(maxHeap) // [5, 4, 2, 1, 3] -> 내림차순 X 
    println(maxHeap.peek()) // 5 
    
    // 큰 값부터 삭제 
    while(!maxHeap.isEmpty()){
        print(maxHeap.poll())
    }
    println()
}