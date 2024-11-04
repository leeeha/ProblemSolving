```kotlin 
fun countDivisorOf(n: Int): Int {
    var cnt = 0
    
    for(i in 1..n){
        if(i * i > n) break
        
        if(i * i == n) cnt++
        else if(n % i == 0) cnt +=2
    }
    
    return cnt 
}
```