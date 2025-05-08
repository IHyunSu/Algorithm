// Greedy Approach (1) deadline scheduling

/**
 * 1. input으로 각 job마다 deadline과 profit을 받는다.
 * 2. job들을 profit기준으로 내림차순 정렬한다.
 * 3. 내림차순 정렬된 job을 하나하나씩 K sequence에 deadline기준으로 비내림차순 정렬되게 insert하면서
 *    feasible한 sequence인지 확인해본다.
 *      -> if : insert한 sequnece라면 J sequence에 deadline기준으로 비내림차순 정렬되게 insert
 *         else : reject하여 다음 정렬된 job을 선택하여 단계 3 반복.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // iota를 사용하기 위해 추가

using namespace std;

// 원래의 scheduleList 타입을 사용
typedef vector<pair<int, int> > scheduleList;

// 함수 선언
bool feasible(const vector<int> &K, const scheduleList &schedules);                                      // K와 schedules를 const 참조로 변경
vector<int> insert(const vector<int> &J, int current_job_original_index, const scheduleList &schedules); // i를 원래 인덱스로 의미 변경
vector<int> schedule(const scheduleList &schedules);                                                     // schedules를 const 참조로 변경

int main()
{
    // 입출력 속도 개선
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 원래의 schedules 데이터를 저장할 벡터
    scheduleList schedules(N);

    for (int i = 0; i < N; i++)
        cin >> schedules[i].first; // deadline
    for (int i = 0; i < N; i++)
        cin >> schedules[i].second; // profit

    // schedule 함수 호출 (원래 데이터 전달)
    vector<int> J = schedule(schedules);

    // 결과 이익 계산 (J에 저장된 것은 원래 인덱스)
    int result = 0;
    for (int idx : J)
    {
        result += schedules[idx].second; // 원래 인덱스를 사용해서 이익 접근
    }

    cout << result << endl;

    for (int i = 0; i < J.size(); i++)
    {
        cout << schedules[J[i]].second;
        if (i != J.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}

// schedule 함수: 이익 순으로 정렬 후 스케줄 구성
vector<int> schedule(const scheduleList &schedules)
{
    int N = schedules.size();
    // 작업의 원래 인덱스를 저장할 벡터
    vector<int> original_indices(N);
    // 0부터 N-1까지 인덱스로 채우기
    iota(original_indices.begin(), original_indices.end(), 0);

    // 원래 인덱스들을 이익(schedules[index].second) 내림차순으로 정렬
    sort(original_indices.begin(), original_indices.end(), [&](int a, int b)
         { return schedules[a].second > schedules[b].second; });

    // 스케줄된 작업들의 원래 인덱스를 시간 순서대로 저장할 벡터
    vector<int> J;

    // 이익이 큰 작업부터 순회하며 스케줄에 추가 시도
    for (int i = 0; i < N; i++)
    {
        int current_job_original_index = original_indices[i]; // 이익 순으로 고려할 현재 작업의 원래 인덱스

        // 현재 스케줄 J에 이 작업을 삽입했을 때의 가상 스케줄 K 생성
        vector<int> K = insert(J, current_job_original_index, schedules);

        // K가 실행 가능한 스케줄인지 확인
        if (feasible(K, schedules))
        {
            J = K; // 가능하면 J를 K로 업데이트
        }
    }
    return J;
}

// feasible 함수: 주어진 스케줄 K가 유효한지 확인
bool feasible(const vector<int> &K, const scheduleList &schedules)
{
    // K는 시간 순서대로 정렬된 작업들의 '원래 인덱스' 목록
    // K[i-1]는 시간 i에 스케줄된 작업의 '원래 인덱스'를 의미
    for (int i = 1; i <= K.size(); i++)
    {
        int original_index_at_time_i = K[i - 1]; // 시간 i에 스케줄된 작업의 원래 인덱스
        // 시간 i에 스케줄된 작업의 마감일(schedules[original_index_at_time_i].first)이
        // 현재 시간 i보다 작으면 (즉, 마감일을 넘겼으면) 불가능
        if (i > schedules[original_index_at_time_i].first)
        {
            return false;
        }
    }
    return true; // 모든 작업이 마감일 안에 가능하면 참
}

// insert 함수: 현재 스케줄 J에 새로운 작업(original_index)을 삽입하여 가상 스케줄 K 생성
vector<int> insert(const vector<int> &J, int current_job_original_index, const scheduleList &schedules)
{
    vector<int> K = J; // J를 복사하여 K 생성
    int j = K.size();  // K의 현재 크기 (새 작업이 들어갈 수 있는 최대 시간 + 1)

    // 삽입할 위치를 찾기 위한 루프
    // K는 시간 순서대로 정렬된 상태라고 가정하고,
    // 현재 작업의 마감일과 K에 있는 작업들의 마감일을 비교하며 삽입 위치를 찾으려는 로직 같아 보임.
    // j는 K의 끝(K.size())부터 1까지 내려가면서 비교.
    // j가 1일 때 K[j-1]은 K[0] (시간 1의 작업)을 의미.
    while (j > 0 && schedules[current_job_original_index].first < schedules[K[j - 1]].first)
    {
        j--; // 현재 작업 마감일이 K[j-1] 작업 마감일보다 작으면, 더 앞쪽 시간으로 이동해서 삽입할 위치를 찾아.
    }
    // 루프가 끝나면 j는 새로운 작업이 삽입될 위치의 인덱스
    // (0 <= j <= K.size())

    // 찾은 위치(인덱스 j)에 현재 작업의 원래 인덱스를 삽입
    K.insert(K.begin() + j, current_job_original_index);

    return K; // 새로운 가상 스케줄 K 반환
}
