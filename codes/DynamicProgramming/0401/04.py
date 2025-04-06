# y, x 위치에서 시작했을 때 만들 수 있는 최대 경로의 합을 구하는 함수
def path3(y, x, triangle, cache):
    n = len(triangle)
    
    # 삼각형의 맨 아래에 도달하면 현재 값을 리턴
    if y == n - 1:
        return triangle[y][x]

    # 이미 계산한 적이 있으면 캐시에서 가져옴
    if (y, x) in cache:
        return cache[(y, x)]
    
    # 아래 또는 오른쪽 아래로 이동해서 최대 경로의 합을 구함
    cache[(y, x)] = triangle[y][x] + max(
        path3(y + 1, x, triangle, cache),
        path3(y + 1, x + 1, triangle, cache)
    )
    
    return cache[(y, x)]

# 테스트 케이스 개수 입력
c = int(input())

for _ in range(c):
    # 삼각형의 크기 입력
    n = int(input())
    i = 0

    # 삼각형 데이터를 리스트로 저장
    triangle = []
    for _ in range(n):
        row = list(map(int, input().split()))
        triangle.append(row)

    # 메모이제이션을 위한 캐시
    cache = {}

    # 결과 출력
    print(path3(0, 0, triangle, cache))
    