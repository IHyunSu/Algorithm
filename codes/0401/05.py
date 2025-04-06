# y, x 위치에서 시작했을 때 만들 수 있는 최대 경로의 합과 경로 리스트를 반환하는 함수
def path3(y, x, triangle, cache):
    n = len(triangle)

    # 삼각형 맨 아래 도달
    if y == n - 1:
        return triangle[y][x], [triangle[y][x]]

    if (y, x) in cache:
        return cache[(y, x)]

    # 오른쪽 치우친 경로를 우선시
    left_sum, left_path = path3(y + 1, x, triangle, cache)
    right_sum, right_path = path3(y + 1, x + 1, triangle, cache)

    if right_sum >= left_sum:
        total = triangle[y][x] + right_sum
        path = [triangle[y][x]] + right_path
    else:
        total = triangle[y][x] + left_sum
        path = [triangle[y][x]] + left_path

    cache[(y, x)] = (total, path)
    return cache[(y, x)]


# 테스트 케이스 개수 입력
c = int(input())

for _ in range(c):
    n = int(input())
    triangle = [list(map(int, input().split())) for _ in range(n)]
    cache = {}

    # 경로와 합 계산
    total, path = path3(0, 0, triangle, cache)

    # 출력
    print(total)
    print(" ".join(map(str, path)))
