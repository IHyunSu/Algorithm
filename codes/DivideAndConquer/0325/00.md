# 🧠 Divide and Conquer (분할 정복)

## 📘 개요

Divide and Conquer는 문제를 더 작은 하위 문제로 나눈 후, 이들을 해결하여 전체 문제의 해답을 구하는 알고리즘 패러다임입니다.  
작은 문제들이 독립적일 때 매우 효과적이며, 병렬 처리에 유리합니다.

---

## 🔍 Divide and Conquer의 3단계

1. **분할 (Divide)**: 문제를 더 작은 하위 문제로 분할한다.
2. **정복 (Conquer)**: 하위 문제를 재귀적으로 해결한다.
3. **결합 (Combine)**: 하위 문제의 해를 합쳐서 전체 문제의 해를 구한다.

---

## 🧩 예시 1: Strassen's Matrix Multiplication (슈트라센 알고리즘)

### ✅ 개요

Strassen 알고리즘은 두 개의 정사각형 행렬을 곱할 때, 전통적인 방법보다 더 적은 곱셈 연산으로 수행할 수 있도록 분할 정복을 사용합니다.

### ✅ Divide and Conquer 방식

두 개의 n x n 행렬을 4개의 (n/2) x (n/2) 행렬로 분할합니다.  
7개의 곱셈과 몇 개의 덧셈/뺄셈으로 원래 곱셈을 구성합니다.

```python
# 예시: 2x2 행렬 곱
def strassen(A, B):
    if len(A) == 1:
        return [[A[0][0] * B[0][0]]]
    # A와 B를 4개의 서브행렬로 나누기 (생략)
    # M1 ~ M7 계산 (곱셈 7번)
    # 결과 행렬의 각 사분면 계산 및 결합
```

### ✅ 시간 복잡도

- 일반적인 행렬 곱셈: O(n³)
- 슈트라센 알고리즘: O(n^log₂7) ≈ O(n^2.81)

---

## 🧩 예시 2: 쿼드 트리 압축

### ✅ 개요

이미지나 2차원 배열 데이터를 압축할 때 사용하는 방식으로, 4개의 영역으로 나눈 후, 동일한 값이면 압축합니다.

### ✅ Divide and Conquer 방식

1. 2차원 배열을 4개의 영역으로 분할
2. 각 영역에 대해 동일한 값으로만 구성되었는지 확인
3. 아니라면 계속 분할 (재귀적 처리)

```python
def compress(x, y, size):
    if check_same(x, y, size):
        return str(arr[x][y])
    half = size // 2
    return "(" +            compress(x, y, half) +            compress(x, y + half, half) +            compress(x + half, y, half) +            compress(x + half, y + half, half) + ")"
```

### ✅ 시간 복잡도

- 최악의 경우 모든 픽셀을 분할하며 확인 → O(n²)
- 평균적으로 압축이 잘 될 경우 더 낮은 시간

---

## ✅ 정리

| 항목             | Divide and Conquer 예시                         |
|------------------|--------------------------------------------------|
| 목적             | 문제를 쪼개고 재귀적으로 해결 후 결합           |
| 대표 알고리즘     | 병합 정렬, 퀵 정렬, Karatsuba, Strassen, 쿼드 트리 |
| 중복 하위 문제   | 없음 (Dynamic Programming과 차이점)             |
| 효율성           | 병렬화에 유리, 깔끔한 분할 구조일수록 효율적    |

---

## 📌 마무리

Divide and Conquer는 구조적으로 잘 나눠지는 문제에 특히 강력하며,  
하위 문제 간의 중복이 적고 독립적인 경우에 적합한 전략입니다.