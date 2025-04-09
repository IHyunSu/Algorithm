import sys

# 최소 연산 횟수를 구하는 함수
def minimum(i, j, d, M):
    min_value = sys.maxsize
    k_opt = -1
    for k in range(i, j):
        value = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]
        if value < min_value:
            min_value = value
            k_opt = k
    return min_value, k_opt

# 행렬 곱셈 최소 비용 계산 함수
def minmult(n, d):
    M = [[0] * (n + 1) for _ in range(n + 1)]  # 곱셈 결과 테이블
    P = [[0] * (n + 1) for _ in range(n + 1)]  # 분할 지점 테이블

    # 대각선 초기화
    for i in range(1, n + 1):
        M[i][i] = 0

    # 동적 프로그래밍을 사용하여 최소 비용 계산
    for diagonal in range(1, n):
        for i in range(1, n - diagonal + 1):
            j = i + diagonal
            M[i][j], P[i][j] = minimum(i, j, d, M)

    return M, P

# 최적 곱셈 순서 구하기
def order(i, j, P):
    if i == j:
        return f"(A{i})"
    else:
        k = P[i][j]
        left = order(i, k, P)
        right = order(k + 1, j, P)
        return f"({left}{right})"

# main function
def main():
    # 행렬 크기 입력
    n = int(input())
    
    # 행렬 크기에 맞는 차원 배열 입력
    d = list(map(int, input().split()))

    # 행렬 곱셈 최소 비용 계산
    M, P = minmult(n, d)

    # M 배열 출력
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if j == 1:
                print(M[i][j], end=" ")
            elif M[i][j] != 0:
                print(M[i][j], end=" ")
        print()

    # P 배열 출력
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if j == 1:
                print(P[i][j], end=" ")
            elif P[i][j] != 0:
                print(P[i][j], end=" ")
        print()

    # 최적 곱셈 횟수 출력
    print(M[1][n])

    # 최적 곱셈 순서 출력
    optimal_order = order(1, n, P)
    print(optimal_order)

# 실행
if __name__ == "__main__":
    main()
