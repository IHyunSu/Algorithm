# 알고리즘 요약 정리

---

## 📌 1. GCD (최대공약수)

### ✨ 유클리드 알고리즘 (Euclidean Algorithm)

두 수 `a`, `b`의 최대공약수(GCD)를 구할 때 사용. 나눗셈을 반복하면서 `gcd(a, b) = gcd(b, a % b)` 관계를 이용함.

### ✅ 재귀 코드 (C/C++ 스타일)
```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```

### ✅ 설명
- 기본 개념: 나머지가 0이 될 때까지 `a % b`를 반복
- 수학적 근거: `gcd(a, b) = gcd(b, a % b)`
- 시간복잡도: **O(log(max(a, b)))**  
  → 각 단계마다 b가 절반 이하로 줄어들 수 있음

---

## 📌 2. Collatz 수열 (3n + 1 문제)

### ✨ 개념
어떤 자연수 `n`에 대해 다음을 반복:
- 짝수면: `n → n / 2`
- 홀수면: `n → 3n + 1`

이 과정을 반복하면 모든 수는 결국 `1`이 된다는 미해결 수학 추측.

### ✅ 코드 예시 (Python 스타일)
```python
def collatz(n):
    print(n, end=' ')
    if n == 1:
        return
    elif n % 2 == 0:
        collatz(n // 2)
    else:
        collatz(3 * n + 1)
```

### ✅ 설명
- 수학적 성질은 알려진 것이 거의 없음
- 매우 단순한 규칙이지만 아무 수에서 시작해도 1로 수렴
- 시간복잡도: 평균적으로 **O(log n)** 수준이나, 최악 케이스는 미정

---

## 📌 3. 하노이의 탑 (Tower of Hanoi)

### ✨ 문제 설명
- 원반 N개를 한 기둥에서 다른 기둥으로 모두 옮기되,
  - 한 번에 한 개만 이동 가능
  - 큰 원반은 절대 작은 원반 위에 놓을 수 없음
  - 보조 기둥을 활용해야 함

### ✅ 재귀 알고리즘
```cpp
void hanoi(int n, char src, char dst, char aux) {
    if (n == 1)
        cout << "Move disk 1 from " << src << " to " << dst << endl;
    else {
        hanoi(n-1, src, aux, dst);
        cout << "Move disk " << n << " from " << src << " to " << dst << endl;
        hanoi(n-1, aux, dst, src);
    }
}
```

### ✅ 설명
- 총 이동 횟수: **2ⁿ - 1**
- 시간복잡도: **O(2ⁿ)**  
  → 입력 크기 `n`에 대해 지수적으로 증가

---

## 📌 4. Algorithm 1~7 시간복잡도 분석

| 알고리즘 | 구조 요약 | 시간복잡도 | 분석 |
|----------|-----------|------------|------|
| Algorithm 1 | 단일 루프 2개 | Θ(n) | 2n + n/2 |
| Algorithm 2 | 중첩 루프 | Θ(n²) | 2n × (n/2) |
| Algorithm 3 | 이중 로그 루프 | Θ(log² n) | log₂n × log₂n |
| Algorithm 4 | 두 개의 루프 (n, m) | Θ(n + m) | 각각 독립 |
| Algorithm 5 | 중첩 호출 | Θ(n³) | algorithm2(n) + algorithm3(n) 포함 |
| Algorithm 6 | 재귀: 2T(n/2) | Θ(n) | Master theorem (a=b=2, k=0) |
| Algorithm 7 | 재귀: 3T(n/4) | Θ(n^0.792) | log₄3 ≈ 0.792 |

---

## 📌 5. 처음 제시된 코드 4개: 시간복잡도 및 다항식 변환

### ✅ 코드 1

```cpp
for (i = 1; i <= 4*n; i += 2)
    for (j = n; j >= 1; j--) cnt++;
```

- 외부 루프: 2n회
- 내부 루프: n회
- 총 cnt 증가: `2n × n = 2n²`
- ✅ **다항식 표현**: `cnt = 2n²`

---

### ✅ 코드 2

```cpp
for (i=1; i<=2*n; i+=4)
    for (j=1; j<=2*m; j*=2)
        for (k=4*p; k>=1; k/=2)
            cnt++;
```

- i 루프: 약 `n/2`회
- j 루프: `log₂(2m)`
- k 루프: `log₂(4p)`
- ✅ **다항식 근사**: `cnt ≈ (n/2) × log(2m) × log(4p)`

---

### ✅ 코드 3 (재귀 4T(n/2))

```cpp
if (n == 0) return 1;
return 4 × fun(n/2);
```

- 재귀 트리 깊이: log₂(n+1)
- 호출 수: 4^log₂(n+1) = (n+1)²
- ✅ **다항식 표현**: `fun(n) = (n + 1)²`

---

### ✅ 코드 4 (재귀 8T(n/4))

```cpp
if (n == 0) return 1;
for (int i = 1; i <= 8; i++)
    s += fun(n/4);
```

- 재귀 트리 깊이: log₄(n+1)
- 호출 수: 8^log₄(n+1) = (n+1)^1.5
- ✅ **다항식 표현**: `fun(n) = (n + 1)^{1.5}`

---

## 📌 참고한 슬라이드 및 문서

- **Lec.02_Algorithms(2).pdf**  
  - 알고리즘 복잡도 이론, 연습 문제 (algorithm1~7)
  - Divide-and-Conquer vs Dynamic Programming
