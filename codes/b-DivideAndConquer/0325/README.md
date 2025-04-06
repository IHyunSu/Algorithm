# ⚔️ Divide and Conquer (분할 정복)

**Divide and Conquer**는 큰 문제를 더 작고 유사한 하위 문제로 나누어 해결한 후, 그 결과를 결합하여 전체 문제를 해결하는 전략입니다. 이 전략은 다음과 같은 세 단계로 이루어집니다:

1. **Divide (분할)**: 문제를 더 작은 하위 문제로 나눈다.
2. **Conquer (정복)**: 하위 문제를 재귀적으로 해결한다.
3. **Combine (결합)**: 하위 문제의 해답을 결합하여 전체 문제의 해답을 구한다.

---

## 📌 대표적인 예시

### 1. 🔢 스트라센 행렬 곱셈 (Strassen's Matrix Multiplication)

행렬 곱셈에서 곱셈 횟수를 줄여 더 빠르게 계산하는 알고리즘.

- **분할**: 두 행렬을 각각 4개의 하위 행렬로 나눔
- **정복**: 7개의 곱셈을 재귀적으로 계산
- **결합**: 결과를 합쳐 전체 행렬을 구성

> ⏱ 시간 복잡도: **O(n^2.81)**

---

### 2. 🧮 카라츠바 정수 곱셈 (Karatsuba's Integer Multiplication)

큰 수의 곱셈을 3개의 곱셈으로 줄여 수행하는 방법.

- **분할**: 숫자를 절반으로 나눔
- **정복**: 3개의 곱셈을 수행
- **결합**: 곱셈 결과를 더하고 빼서 최종 계산

> ⏱ 시간 복잡도: **O(n^1.585)**

---

### 3. 🌀 피보나치 수 계산 (Fibonacci by Divide and Conquer)

행렬 제곱 또는 공식 이용하여 빠르게 피보나치 수를 계산.

- **분할**: F(n)을 F(k), F(k+1)로 나눔
- **정복**: 재귀적으로 F(k), F(k+1) 계산
- **결합**: 공식으로 F(n) 계산

> ⏱ 시간 복잡도: **O(log n)**

---

### 4. 🖼️ 쿼드트리 인코더 (Quadtree Encoder)

이미지를 재귀적으로 나누어 압축하는 방식.

- **분할**: 이미지를 4개의 영역으로 분할
- **정복**: 각 영역이 동일한 색인지 확인하고 재귀적으로 압축
- **결합**: 쿼드트리 구조로 전체 인코딩

> ⏱ 시간 복잡도: **O(n²)** (이미지 크기에 따라)

---

### 5. 📡 쿼드트리 디코더 (Quadtree Decoder)

쿼드트리로 압축된 이미지를 복원하는 알고리즘.

- **분할**: 트리 구조에 따라 이미지 영역 분할
- **정복**: 각 영역을 재귀적으로 복원
- **결합**: 복원된 하위 영역을 결합하여 전체 이미지 구성

> ⏱ 시간 복잡도: **O(n²)**

---

## ✅ 요약

| 알고리즘                  | 핵심 전략                    | 시간 복잡도         |
|---------------------------|-------------------------------|---------------------|
| 스트라센 행렬 곱셈        | 7개의 하위 행렬 곱셈 수행     | O(n^2.81)           |
| 카라츠바 정수 곱셈        | 큰 수를 3개 곱셈으로 처리     | O(n^1.585)          |
| 피보나치 수 계산          | 공식 기반 재귀 계산           | O(log n)            |
| 쿼드트리 인코더           | 동일 영역 압축                | O(n²)               |
| 쿼드트리 디코더           | 트리 구조로 복원              | O(n²)               |

Divide and Conquer는 복잡한 문제를 재귀적으로 해결하는 강력한 전략이며, 다양한 분야에서 효율적인 알고리즘 설계에 사용됩니다.

# ⚙️ Divide and Conquer 구조 분석

각 예시에서 Divide and Conquer 기법이 어떻게 적용되는지 구조적으로 정리한 문서입니다.

---

## 1. 🔢 스트라센 행렬 곱셈 (Strassen's Matrix Multiplication)

```
function Strassen(A, B):
    if size is small:
        return A * B
    else:
        Divide A and B into 4 submatrices
        Compute 7 matrix products recursively:
            M1 = (A11 + A22) * (B11 + B22)
            M2 = (A21 + A22) * B11
            M3 = A11 * (B12 - B22)
            ...
        Combine the 7 products to get result matrix C
        return C
```

---

## 2. 🧮 카라츠바 정수 곱셈 (Karatsuba's Integer Multiplication)

```
function Karatsuba(x, y):
    if x or y is small:
        return x * y
    else:
        Split x into a and b, y into c and d
        Compute:
            ac = Karatsuba(a, c)
            bd = Karatsuba(b, d)
            ad_plus_bc = Karatsuba(a + b, c + d) - ac - bd
        Combine:
            return ac * 10^(2m) + ad_plus_bc * 10^m + bd
```

---

## 3. 🌀 피보나치 수 계산 (Fibonacci by Divide and Conquer)

```
function Fib(n):
    if n == 0:
        return (0, 1)
    else:
        (a, b) = Fib(n // 2)
        c = a * (2 * b - a)
        d = a^2 + b^2
        if n % 2 == 0:
            return (c, d)
        else:
            return (d, c + d)
```

---

## 4. 🖼️ 쿼드트리 인코더 (Quadtree Encoder)

```
function Encode(image):
    if region is homogeneous:
        return single value
    else:
        Divide image into 4 quadrants
        Encode each quadrant recursively
        return Node(top-left, top-right, bottom-left, bottom-right)
```

---

## 5. 📡 쿼드트리 디코더 (Quadtree Decoder)

```
function Decode(node):
    if node is a value:
        return filled region with that value
    else:
        Decode top-left, top-right, bottom-left, bottom-right
        Combine the 4 regions into full image
        return image
```

---

이 구조들은 각 문제에 맞는 **Divide → Conquer → Combine** 흐름을 따르며, 재귀적으로 문제를 해결합니다.
