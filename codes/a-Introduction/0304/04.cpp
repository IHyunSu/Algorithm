// #include <iostream>
// using namespace std;
// #define ROW 25
// #define COL 25

// int main () {
//     int n;
//     int arr1[ROW][COL] = {0, };
//     int arr2[ROW][COL] = {0, };
//     int arr3[ROW][COL] = {0, };

//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> arr1[i][j];
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> arr2[i][j];
//         }
//     }
    
//     // cout << "arr1" << endl;
//     // for (int i = 0; i < n; i++) {
//     //     for (int j = 0; j < n; j++) {
//     //         if (j != n - 1) cout << arr1[i][j] << " ";
//     //         else cout << arr1[i][j] << endl;
//     //     }
//     // }

//     // cout << "arr2" << endl;
//     // for (int i = 0; i < n; i++) {
//     //     for (int j = 0; j < n; j++) {
//     //         if (j != n - 1) cout << arr2[i][j] << " ";
//     //         else cout << arr2[i][j] << endl;
//     //     }
//     // }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             arr3[i][j] = 0;
//             for (int k = 0; k < n; k++) {
//                 arr3[i][j] += arr1[i][k] * arr2[k][j];
//             }
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (j != n - 1) cout << arr3[i][j] << " ";
//             else cout << arr3[i][j] << endl;
//         }
//     }
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// void cinArray(vector<vector<int> >& S, int n);
// void multiplication(vector<vector<int> > S1, vector<vector<int> > S2, vector<vector<int> >& S3, int n);
// void coutArray(vector<vector<int> > S, int n);

// int main () {
//     int n; cin >> n;
//     vector<vector<int> >S1(n, vector<int>(n));
//     vector<vector<int> >S2(n, vector<int>(n));
//     vector<vector<int> >S3(n, vector<int>(n));

//     cinArray(S1, n);
//     cinArray(S2, n);

//     multiplication(S1, S2, S3, n);

//     coutArray(S3, n);
// }
// void cinArray(vector<vector<int> >& S, int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> S[i][j];
//         }
//     }
// }

// void multiplication(vector<vector<int> > S1, vector<vector<int> > S2, vector<vector<int> >& S3, int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             S3[i][j] = 0;
//             for (int k = 0; k < n; k++) {
//                 S3[i][j] += S1[i][k] * S2[k][j];
//             }
//         }
//     }
// }

// void coutArray(vector<vector<int> > S, int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (j != n - 1)
//                 cout << S[i][j] << " ";
//             else
//                 cout << S[i][j] << endl;
//         }
//     }
// }   


#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > matrix_t;

void inputMatrix(matrix_t& S, int n);
void matrixMult(matrix_t A, matrix_t B, matrix_t& C, int n);
void printMatrix(matrix_t S, int n);

int main () {
    int n;
    cin >> n;
    matrix_t A(n + 1, vector<int>(n + 1)); inputMatrix(A, n);
    matrix_t B(n + 1, vector<int>(n + 1)); inputMatrix(B, n);

    matrix_t C(n + 1, vector<int>(n + 1));

    matrixMult(A, B, C, n);
    printMatrix(C, n);

    return 0;
}

void inputMatrix(matrix_t& S, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> S[i][j];
        }
    }

    return;
}

void matrixMult(matrix_t A, matrix_t B, matrix_t& C, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            C[i][j] = 0;
            for (int k = 1; k <= n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return;
}

void printMatrix(matrix_t S, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << S[i][j];
            if (j != n) cout << " ";
        }
        if (i != n) cout << endl;
    }

    return;
}