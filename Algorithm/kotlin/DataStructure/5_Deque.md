```kotlin
import java.util.*

fun main() {
    val dq = ArrayDeque<Int>()
    dq.offerLast(1)
    dq.offerLast(2)
    dq.offerLast(3)
    println(dq) // [1, 2, 3]
    
    dq.pollFirst()
    println(dq) // [2, 3]
    
    while(!dq.isEmpty()){
        dq.pollLast()
    }
    
    println(dq.size) // 0
}
```