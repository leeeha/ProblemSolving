```kotlin 
/**
 * add(): 큐가 꽉 차면 예외 발생 
 * offer(): 큐가 꽉 차면 false 반환
 * 
 * remove(): 큐가 비어 있으면 예외 발생 
 * poll(): 큐가 비어 있으면 null 반환
 */
import java.util.*

fun main() {
    val queue = ArrayDeque<Int>()
    queue.offer(1)
    queue.offer(2)
    queue.offer(3)
    queue.offer(4)
    queue.offer(5)
    println(queue) // [1, 2, 3, 4, 5]
    println(queue.peek()) // 1
    println(queue.contains(3)) // true
    
    while(!queue.isEmpty()){
        queue.poll()
    }
}
```