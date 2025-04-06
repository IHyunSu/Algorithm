import sys
import copy
input = sys.stdin.readline

def check_power_of_2(N):
    if (N & -N) == N:
        return N
    else:
        k = 1
        while k < N:
            k *= 2
        return k


def add_zero(M, idx, N):
    for i in range(N):
        M[i].extend([0 for _ in range(idx)])
    M.extend([0 for _ in range(N + idx)] for _ in range(idx))

    return M


def print_matrix(N, M):
    for i in range(N):
        print(*M[i][:N])


def partition(m, M, M11, M12, M21, M22):
    for i in range(m):
        for j in range(m):
            M11[i][j] = M[i][j]
            M12[i][j] = M[i][j + m]
            M21[i][j] = M[i+m][j]
            M22[i][j] = M[i+m][j+m]


def mmult(N, A, B, C):
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][k] += A[i][j] * B[j][k]


def madd(N, A, B, C):
    # print(A, B ,N)
    for i in range(N):
        for j in range(N):
            C[i][j] = A[i][j] + B[i][j]


def msub(N, A, B, C):
    for i in range(N):
        for j in range(N):
            C[i][j] = A[i][j] - B[i][j]


def resize(m, M):
    M.extend([[0 for _ in range(m)] for _ in range(m)])


def combine(m, C, C11, C12, C21, C22):
    for i in range(m):
        for j in range(m):
            C[i][j] = C11[i][j]
            C[i][j+m] = C12[i][j]
            C[i+m][j] = C21[i][j]
            C[i+m][j+m] = C22[i][j]


def strassen(N, A, B, C):
    global Threshold
    global count
    count += 1
    if N <= Threshold:
        mmult(N, A, B, C)
    else:
        m = N//2

        main_dict = {f'{c}{i}{j}': [] for c in ['A', 'B', 'C'] for i in range(1, 3) for j in range(1, 3)}
        main_dict.update({f'M{i}': [] for i in range(1, 8)})
        main_dict.update({f'{c}': [] for c in ['L', 'R']})

        for key in list(main_dict.keys()):
            resize(m, main_dict[key])

        # print(main_dict)

        partition(m, A, *[main_dict[f'{c}'] for c in list(main_dict.keys()) if 'A' in c])
        partition(m, B, *[main_dict[f'{c}'] for c in list(main_dict.keys()) if 'B' in c])

        # print(A21, A22, m)

        A11, A12, A21, A22 = [main_dict[f'{c}'] for c in list(main_dict.keys()) if 'A' in c]
        B11, B12, B21, B22 = [main_dict[f'{c}'] for c in list(main_dict.keys()) if 'B' in c]
        C11, C12 ,C21, C22 = [main_dict[f'{c}'] for c in list(main_dict.keys()) if 'C' in c]
        M1, M2, M3, M4, M5, M6, M7 = [main_dict[f'{c}'] for c in list(main_dict.keys()) if 'M' in c]
        L, R = main_dict['L'], main_dict['R']

        # for c in ['A', 'B', 'C']:
        #     for i in range(1, 3):
        #         for j in range(1, 3):
        #             locals()[f'{c}{i}{j}'] = main_dict[f'{c}{i}{j}']
        #
        # for i in range(1, 8):
        #     locals()[f'M{i}'] = main_dict[f'M{i}']
        #
        # for c in 'L', 'R':
        #     locals()[f'{c}'] = main_dict[f'{c}']

        madd(m, A11, A22, L)
        madd(m, B11, B22, R)
        strassen(m, L, R, M1)       ###M1

        madd(m, main_dict['A21'], main_dict['A22'], L)
        strassen(m, L, B11, M2)     ###M2

        msub(m, B12, B22, R)
        strassen(m, A11, R, M3)     ###M3

        msub(m, B21, B11, R)
        strassen(m, A22, R, M4)     ###M4

        madd(m, A11, A12, L)
        strassen(m, L, B22, M5)     ###M5

        msub(m, A21, A11, L)
        madd(m, B11, B12, R)
        strassen(m, L, R, M6)       ###M6

        msub(m, A12, A22, L)
        madd(m, B21, B22, R)
        strassen(m, L, R, M7)       ###M7

        # print(M1, M2, M3, M4, M5, M6, M7)

        madd(m, M1, M4, L)
        msub(m, L, M5, L)
        madd(m, L, M7, C11)          ###C1

        madd(m, M3, M5, C12)        ###C2

        madd(m, M2, M4, C21)        ###C3

        madd(m, M1, M3, L)
        msub(m, L, M2, L)
        madd(m, L, M6, C22)          ###C4

        combine(m, C, C11, C12, C21, C22)



N, Threshold = map(int, input().split())

k = check_power_of_2(N)
idx = k - N

A = [list(map(int, input().split())) for _ in range(N)]
B = [list(map(int, input().split())) for _ in range(N)]

if idx != 0:
    A = add_zero(A, idx, N)
    B = add_zero(B, idx, N)

C = [[0 for _ in range(k)] for _ in range(k)]

count = 0

strassen(k, A, B, C)

print(count)
print_matrix(N, C)