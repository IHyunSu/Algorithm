// #include <iostream>
// #include <math.h>
// using namespace std;

// int threshold = 1;
// int cnt = 0;

// long long int karatuba(int u, int v);

// int main () {
//     int u, v;

//     cin >> u >> v;
//     // printf("%d\n", u, v);

//     long long int uv = karatuba(u, v);
//     printf("%d\n%lld\n", cnt, uv);

//     return 0;
// }

// long long int karatuba(int u, int v) {
//     cnt++;
//     int n;
//     n = (to_string(u).length()) >= (to_string(v).length()) ? (to_string(u).length()) : (to_string(v).length());
//     if (u == 0 || v == 0)
//         return 0;
//     else if (n <= threshold) {
//         return u * v;
//     } else {
//         long long int m, x, y, w, z;
//         long long int r, p, q;
//         m = n / 2;
//         x = u / pow(10, m); y = u % static_cast<int>(pow(10, m));
//         w = v / pow(10, m); z = v % static_cast<int>(pow(10, m));
//         r = karatuba(x + y, w + z);
//         p = karatuba(x, w);
//         q = karatuba(y, z);
//         return p * (pow(10, 2*m)) + (r - p - q) * (pow(10, m)) + q;
//     }
// }

#include <iostream>
#include <math.h>
using namespace std;

int threshold = 1;
int cnt = 0;

string large_mult2(string u, string v);
string addStrings(string a, string b);
string multiplyStrings(string a, string b);
string shiftLeft(string num, int m);
long long int large_mult(int u, int v);

int main () {
    string u, v;

    cin >> threshold;
    cin >> u >> v;
    int check1 = u.size() > 10 ? 1 : 0;
    int check2 = v.size() > 10 ? 1 : 0;

    if (check1 == 1 || check2 == 1) {
        string result = large_mult2(u, v);
        cout << cnt << endl;
        cout << result << endl;
    } else {
        long long int uv = large_mult(stoll(u), stoll(v));
        printf("%d\n%lld\n", cnt, uv);
    }

    return 0;
}

long long int large_mult(int u, int v) {
    cnt++;
    int n;
    n = (to_string(u).length()) >= (to_string(v).length()) ? (to_string(u).length()) : (to_string(v).length());
    if (u == 0 || v == 0) {
        return 0;
    }
    else if (n <= threshold) {
        return u * v;
    } else {
        long long int m, x, y, w, z;
        long long int p1, p2, p3, p4;
        m = n / 2;
        x = u / pow(10, m); y = u % static_cast<int>(pow(10, m));
        w = v / pow(10, m); z = v % static_cast<int>(pow(10, m));
        p1 = large_mult(x, w); p2 = large_mult(x, z);
        p3 = large_mult(w, y); p4 = large_mult(y, z);
        return p1 * (pow(10, 2*m)) + (p2 + p3) * (pow(10, m)) + p4;
    }
}

// // 큰 수 곱셈 (문자열 기반)
// string large_mult2(string u, string v) {
//     cnt++; // 재귀 호출 횟수 증가
//     int n = max(u.size(), v.size());

//     while (u.size() < n) u = "0" + u;
//     while (v.size() < n) v = "0" + v;

//     // threshold보다 작으면 직접 곱셈 수행
//     if (n <= threshold) {
//         return multiplyStrings(u, v);
//     }


//     int m = n / 2;
//     string x = u.substr(0, u.size() - m);
//     string y = u.substr(u.size() - m);
//     string w = v.substr(0, v.size() - m);
//     string z = v.substr(v.size() - m);

//     string p1 = large_mult2(x, w);
//     string p2 = large_mult2(x, z);
//     string p3 = large_mult2(w, y);
//     string p4 = large_mult2(y, z);

//     return addStrings(addStrings(shiftLeft(p1, 2 * m), shiftLeft(addStrings(p2, p3), m)), p4);
// }

// string addStrings(string a, string b) {
//     string result = "";
//     int carry = 0, sum;

//     while (a.size() < b.size()) a = "0" + a;
//     while (b.size() < a.size()) b = "0" + b;

//     for (int i = a.size() - 1; i >= 0; i--) {
//         sum = (a[i] - '0') + (b[i] - '0') + carry;
//         carry = sum / 10;
//         result = char(sum % 10 + '0') + result;
//     }
//     if (carry) result = "1" + result;

//     return result;
// }

// // 문자열 곱셈 (자리 올림 고려)
// string multiplyStrings(string a, string b) {
//     int len1 = a.size(), len2 = b.size();
//     string result(len1 + len2, '0');

//     for (int i = len1 - 1; i >= 0; i--) {
//         int carry = 0;
//         for (int j = len2 - 1; j >= 0; j--) {
//             int sum = (a[i] - '0') * (b[j] - '0') + (result[i + j + 1] - '0') + carry;
//             carry = sum / 10;
//             result[i + j + 1] = (sum % 10) + '0';
//         }
//         result[i] += carry;
//     }

//     // 앞쪽의 불필요한 0 제거
//     size_t startpos = result.find_first_not_of("0");
//     return (startpos != string::npos) ? result.substr(startpos) : "0";
// }

// // 문자열을 10^m 배만큼 shift
// string shiftLeft(string num, int m) {
//     if (num == "0") return "0";
//     return num + string(m, '0');
// }