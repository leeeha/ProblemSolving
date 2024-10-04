## 소수 판별 

```kotlin
fun isPrime(x: Int): Boolean {
    if(x < 2) return false 

    for(i in 2..x){
        if(i * i > x) break // 제곱근까지만 검사 
        if(x % i == 0) return false
    }

    return true 
}
```

## 에라토스테네스의 체 

```kotlin
fun main() {
    val n = 50 // 1~50까지 소수 구하기 
	val prime = MutableList(n + 1) {true}
    
    prime[0] = false
    prime[1] = false 
    
    // n의 제곱근까지 확인하면서 
    for(i in 2..n){ 
        if(i * i > n) break
        
        // 아직 지워지지 않은 숫자에 대해 
        if(prime[i]){
            // i의 배수 제외 
            for(j in 2*i..n step i){
                prime[j] = false
            }
        }
    }
    
    for(i in 2..n){
        if(prime[i]) print("$i ")
    }
}
```