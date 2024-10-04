```kotlin
import java.util.*

fun main() {
    val stack = ArrayDeque<Int>()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    stack.push(5)
    println(stack) // [5, 4, 3, 2, 1]
    println(stack.contains(4)) // true
    
    stack.pop()
    println(stack) // [4, 3, 2, 1]
    println(stack.peek()) // 4
    
    while(!stack.isEmpty()){
        stack.pop()
    }
}
```