```kotlin
fun solution(arr: IntArray): Int {
    var answer = arr[0]
    
    for(i in 1 until arr.size){
        answer = lcm(answer, arr[i])
    }
    
    return answer
}

fun gcd(a: Int, b: Int): Int {
    if(a % b == 0){
        return b
    }else{
        return gcd(b, a % b)
    }
}

fun lcm(a: Int, b: Int): Int = (a * b) / gcd(a, b)
```