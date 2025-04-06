def path3(y, x, triangle, cache, prefix="", is_last=True):
    branch = "└── " if is_last else "├── "
    print(f"{prefix}{branch}({y}, {x}) 값: {triangle[y][x]}", end="")

    n = len(triangle)

    if y == n - 1:
        print(" [맨 아래] → 반환:", triangle[y][x])
        return triangle[y][x]

    if (y, x) in cache:
        print(" [캐시 사용] → 반환:", cache[(y, x)])
        return cache[(y, x)]

    print()  # 줄바꿈

    new_prefix = prefix + ("    " if is_last else "│   ")

    left = path3(y + 1, x, triangle, cache, new_prefix, False)
    right = path3(y + 1, x + 1, triangle, cache, new_prefix, True)

    cache[(y, x)] = triangle[y][x] + max(left, right)

    print(f"{prefix}    ↑ 위치 ({y}, {x}) 결과 저장: {cache[(y, x)]}")
    return cache[(y, x)]


# 테스트 케이스 개수
c = int(input("테스트 케이스 개수: "))

for case in range(1, c + 1):
    print(f"\n📦 테스트 케이스 #{case}")
    n = int(input("삼각형의 크기: "))

    triangle = []
    print("삼각형을 입력하세요:")
    for _ in range(n):
        row = list(map(int, input().split()))
        triangle.append(row)

    cache = {}
    print("\n🌲 경로 트리 출력 시작 🌲\n")
    result = path3(0, 0, triangle, cache)
    print("\n✅ 최대 경로 합:", result)
