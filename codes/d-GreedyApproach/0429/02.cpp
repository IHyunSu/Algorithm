#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * 1. 먼저 앞은 문자, 뒤는 문자의 빈도수를 넣은 sequence들을 만든다.
 * 2. 또한 sequence들의 set을 모두 frequncy 기준으로 비내림차순 정렬한다.
 * 3. 이후 맨 앞과 두번째 앞인 p와 q를 고른 뒤, 이들을 remove하여 r을 구한다.
 * 4. 구한 r을 subtree로 만들며, set의 비내림차순 정렬 기준으로 자리를 찾아 insert한다.
 * 5. 3단계 4단계 반복 후, 더 이상 remove할 게 없으면 종료한다.
 */

struct HuffNode
{
    char symbol;     // 심볼
    int freq;        // 빈도수
    HuffNode *left;  // 왼쪽 자식 노드
    HuffNode *right; // 오른쪽 자식 노드

    // 생성자
    HuffNode(char s, int f)
    {
        symbol = s;
        freq = f;
        left = nullptr;  // 초기값은 nullptr
        right = nullptr; // 초기값은 nullptr
    }

    // 전위 순회
    void preorder(int &count)
    {
        if (count > 0)
            cout << " ";                                       // 첫 번째 노드가 아닐 경우 공백 출력
        cout << (symbol == ' ' ? '+' : symbol) << ":" << freq; // 빈도수 출력
        count++;
        if (left != nullptr)
        {
            left->preorder(count); // 왼쪽 자식 노드 전위 순회
        }
        if (right != nullptr)
        {
            right->preorder(count); // 오른쪽 자식 노드 전위 순회
        }
    }

    // 중위 순회
    void inorder(int &count)
    {
        if (left != nullptr)
        {
            left->inorder(count); // 왼쪽 자식 노드 중위 순회
        }
        if (count > 0)
            cout << " ";                                       // 첫 번째 노드가 아닐 경우 공백 출력
        cout << (symbol == ' ' ? '+' : symbol) << ":" << freq; // 빈도수 출력
        count++;
        if (right != nullptr)
        {
            right->inorder(count); // 오른쪽 자식 노드 중위 순회
        }
    }
};

// 비교 함수 (우선순위 큐에서 사용)
struct Compare
{
    bool operator()(HuffNode *a, HuffNode *b)
    {
        return a->freq > b->freq; // 빈도수가 낮은 순서로 정렬
    }
};

// 허프만 알고리즘
HuffNode *huffman(int n, priority_queue<HuffNode *, vector<HuffNode *>, Compare> &PQ)
{
    for (int i = 0; i < n - 1; ++i)
    {
        HuffNode *p = PQ.top();
        PQ.pop(); // 가장 낮은 빈도수의 노드
        HuffNode *q = PQ.top();
        PQ.pop(); // 두 번째로 낮은 빈도수의 노드

        HuffNode *r = new HuffNode(' ', p->freq + q->freq); // 새로운 노드 생성
        r->left = p;                                        // 왼쪽 자식
        r->right = q;                                       // 오른쪽 자식

        PQ.push(r); // 새로운 노드를 우선순위 큐에 추가
    }
    return PQ.top(); // 최종 루트 노드 반환
}

// 허프만 코드 생성
void generateHuffmanCodes(HuffNode *root, const string &code, unordered_map<char, string> &huffmanCodes)
{
    if (!root)
        return;

    if (root->symbol != ' ')
    {
        huffmanCodes[root->symbol] = code; // 리프 노드일 경우 코드 저장
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);  // 왼쪽 자식
    generateHuffmanCodes(root->right, code + "1", huffmanCodes); // 오른쪽 자식
}

int main()
{
    // 예시로 우선순위 큐 생성 및 허프만 알고리즘 실행
    priority_queue<HuffNode *, vector<HuffNode *>, Compare> PQ;

    int N;
    cin >> N; // 문자 개수 입력

    vector<pair<char, int>> input(N); // 문자와 빈도수를 저장할 벡터
    for (int i = 0; i < N; i++)
        cin >> input[i].first; // 문자 입력
    for (int i = 0; i < N; i++)
        cin >> input[i].second; // 빈도수 입력

    // 빈도수 기준으로 정렬
    sort(input.begin(), input.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second < b.second; });

    // 데이터 추가
    for (int i = 0; i < N; i++)
    {
        PQ.push(new HuffNode(input[i].first, input[i].second)); // 우선순위 큐에 노드 추가
    }

    HuffNode *root = huffman(N, PQ); // 허프만 알고리즘 실행

    // 결과 출력 (루트 노드의 빈도수)
    int preCount = 0;
    root->preorder(preCount);
    cout << endl;

    // 중위 순회 출력
    int inCount = 0;
    root->inorder(inCount);
    cout << endl;

    // 허프만 코드 생성
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    int M;
    cin >> M; // 인코딩할 문자의 개수
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str; // 문자열 입력
        string encoded = "";
        for (char c : str)
        {
            encoded += huffmanCodes[c]; // 허프만 코드로 인코딩
        }
        cout << encoded << endl; // 인코딩 결과 출력
    }

    int K;
    cin >> K; // 디코딩할 허프만 코드의 개수
    for (int i = 0; i < K; i++)
    {
        string code;
        cin >> code; // 허프만 코드 입력
        string decoded = "";
        HuffNode *current = root;
        for (char c : code)
        {
            current = (c == '0') ? current->left : current->right; // 트리 탐색
            if (current->symbol != ' ')
            {                               // 리프 노드에 도달했을 때
                decoded += current->symbol; // 문자 추가
                current = root;             // 루트로 돌아감
            }
        }
        cout << decoded << endl; // 디코딩 결과 출력
    }

    return 0;
}
