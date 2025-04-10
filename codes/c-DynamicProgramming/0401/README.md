
# 🧠 Dynamic Programming vs Divide and Conquer

## 📘 개요

프로그래밍에서 큰 문제를 풀기 위해 **작은 문제로 나누는 전략**은 매우 일반적입니다.  
이러한 전략을 구현하는 대표적인 방법으로는 **분할 정복(Divide and Conquer)**과 **동적 계획법(Dynamic Programming)**이 있습니다.

이 두 가지는 유사해 보이지만, 핵심적인 차이점이 있습니다.

---

## 🔍 공통점

- 둘 다 큰 문제를 **작은 하위 문제들**로 나누어 해결합니다.
- 재귀 호출을 사용하는 방식이 많습니다.

---

## 🔥 주요 차이점

| 구분               | Divide and Conquer                | Dynamic Programming                            |
|--------------------|-----------------------------------|------------------------------------------------|
| 하위 문제의 중복    | 없음 또는 거의 없음               | **하위 문제들이 반복적으로 등장**              |
| 계산된 결과 저장    | 저장하지 않음                     | **결과를 저장(Memoization)**하여 중복 제거     |
| 예시 문제           | 퀵 정렬, 병합 정렬, 이진 탐색 등   | 피보나치 수열, 계단 오르기, 배낭 문제 등        |

---

## 🧩 예시: 피보나치 수열

### 피보나치 수열 정의
- F(0) = 0  
- F(1) = 1  
- F(n) = F(n - 1) + F(n - 2) (n ≥ 2)

---

### ❌ Divide and Conquer 방식 (비효율적)

```python
def fib_dc(n):
    if n <= 1:
        return n
    return fib_dc(n - 1) + fib_dc(n - 2)
```

#### 🧾 재귀 호출 트리 구조 (fib(5)의 경우)

```
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1)
│   │   │   └── fib(0)
│   │   └── fib(1)
│   └── fib(2)
│       ├── fib(1)
│       └── fib(0)
└── fib(3)
    ├── fib(2)
    │   ├── fib(1)
    │   └── fib(0)
    └── fib(1)
```

이와 같이 중복되는 하위 문제(`fib(2)`, `fib(3)` 등)가 여러 번 등장함을 볼 수 있으며,  
이는 비효율적인 계산을 초래합니다.  

**→ Dynamic Programming을 사용하면 이 중복 계산을 피할 수 있습니다.**

---

## ✅ Dynamic Programming (동적 계획법)

`Divide and Conquer`와 달리, 하위 문제들이 **겹칠 때** 그 결과를 **기억해두고**,  
다시 계산하지 않도록 한다.  
이 과정을 **메모이제이션(Memoization)**이라고 한다.

---

### 방법 1: Top-Down (재귀 + 메모이제이션)

```python
def fib(n, cache={}):
    if n in cache:
        return cache[n]
    if n <= 1:
        return n
    cache[n] = fib(n - 1, cache) + fib(n - 2, cache)
    return cache[n]
```

### 방법 2: Bottom-Up (반복문)

```python
def fib(n):
    if n <= 1:
        return n
    dp = [0, 1]
    for i in range(2, n + 1):
        dp.append(dp[i - 1] + dp[i - 2])
    return dp[n]
```

이 방식은 모든 하위 문제를 정확히 한 번씩만 계산하기 때문에  
Divide and Conquer보다 훨씬 효율적이다.  
→ 시간 복잡도: O(n)

---

## 📌 요약

| 항목                 | Divide and Conquer             | Dynamic Programming           |
|----------------------|--------------------------------|-------------------------------|
| 하위 문제의 중복     | 거의 없음                      | 자주 발생함                   |
| 하위 문제의 결과 저장 | 저장하지 않음                  | 저장해서 재사용               |
| 시간 효율성          | 낮음 (O(2^n) 등)               | 높음 (O(n))                   |
| 예시                 | 병합 정렬, 퀵 정렬, Karatsuba 곱셈 | 피보나치, 계단 오르기, 배낭 문제 |

---

## 📝 마무리

**Dynamic Programming**은 **중복되는 계산이 많은 경우**에 매우 유용한 전략이다.  
반면 **Divide and Conquer**는 **문제를 깔끔하게 쪼갤 수 있고 중복이 없는 경우**에 적합하다.

문제를 풀 때 두 방법 중 어떤 것이 더 적절한지 고민해 보는 것이 중요하다.
