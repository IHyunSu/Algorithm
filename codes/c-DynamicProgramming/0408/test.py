def matrix_chain_order(p, cache, y, x, prefix="", is_last=True, R=None):
    branch = "└── " if is_last else "├── "
    print(f"{prefix}{branch}({y}, {x}) 범위 계산: M[{y}][{x}]")
    
    # 최적화 계산이 완료된 경우
    if (y, x) in cache:
        print(f"{prefix} [캐시 사용] → 반환: {cache[(y, x)]}")
        return cache[(y, x)]

    # 기본적인 종료 조건
    if y == x:
        print(f"{prefix} [단일 행렬] → 반환: 0 (곱셈이 불필요)")
        return 0
    
    # 분할된 최적화 값 계산 (분할 지점 k)
    print(f"{prefix} 분할 계산 시작")
    min_cost = float('inf')  # 최소 비용을 무한대로 초기화
    split_point = -1  # 최적 분할 지점 초기화

    for k in range(y, x):
        left_cost = matrix_chain_order(p, cache, y, k, prefix + ("│   " if not is_last else "    "), False, R)
        right_cost = matrix_chain_order(p, cache, k + 1, x, prefix + ("│   " if not is_last else "    "), True, R)
        
        # 두 부분의 곱셈을 고려한 비용 계산
        cost = left_cost + right_cost + p[y] * p[k + 1] * p[x + 1]

        if cost < min_cost:
            min_cost = cost
            split_point = k
    
    # 분할 지점 k를 캐시에 저장
    cache[(y, x)] = min_cost
    R[y][x] = split_point  # R 테이블에 최적 분할 지점 저장
    print(f"{prefix} M[{y}][{x}] 계산 완료 → {min_cost} (분할 지점: {split_point})")
    
    return min_cost


# 최적의 곱셈 순서를 추적하는 함수
def optimal_order(R, i, j):
    if i == j:
        return f"A{i + 1}"
    else:
        k = R[i][j]
        left_order = optimal_order(R, i, k)
        right_order = optimal_order(R, k + 1, j)
        return f"({left_order} x {right_order})"


# 테스트 케이스 개수
c = int(input("테스트 케이스 개수: "))

for case in range(1, c + 1):
    print(f"\n📦 테스트 케이스 #{case}")
    
    # 행렬 크기 입력
    n = int(input("행렬 크기: "))
    
    # 행렬 크기에 맞는 차원 배열 입력
    p = list(map(int, input(f"행렬 차원 배열 (크기 {n-1}): ").split()))
    
    cache = {}  # 캐시 초기화
    R = [[0] * n for _ in range(n)]  # 분할 지점 기록을 위한 R 테이블 초기화
    
    print("\n🌲 경로 트리 출력 시작 🌲")
    
    # 행렬 곱셈 최소 비용 계산 시작
    result = matrix_chain_order(p, cache, 0, n - 2, R=R)
    
    print("\n✅ 최소 곱셈 횟수:", result)
    
    # 최적 곱셈 순서 출력
    optimal_solution = optimal_order(R, 0, n - 2)
    print("\n최적 곱셈 순서:", optimal_solution)
