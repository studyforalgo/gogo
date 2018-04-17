// BFS, DP
// 1. 양방향 그래프 - sorted 배열에서 시작하나 입력배열에서 시작하나 최단거리는 같음.
// 2. 배열 순서만 맞으면 됨 - 숫자 크기에 관계없이 {0,1} 나 {2,4} 결과는 같음
// 3. N 상관없이 N=8 결과랑 같음 - {1,0,2} = {1,0,2,3,4,5,6,7}

// map 에서 key를 vector로 가능 - vector에 대소비교 구현되있기 때문

#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int C, N;
int n;
map<vector<int>, int> D;

int main(){
    //DP
    N = 8;
    vector<int> t(N);
    for (int i = 0; i < N; ++i)	t[i] = i;
    
    queue<vector<int>> q;
    q.push(t);
    D[t] = 0;
    while (!q.empty()){
        auto v = q.front();
        q.pop();
        
        int d = D[v];
        
        for (int s = 0; s < N - 1; ++s){
            for (int e = s + 2; e <= N; ++e){
                reverse(v.begin() + s, v.begin() + e);
                if (D.count(v) == 0){
                    q.push(v);
                    D[v] = d + 1;
                }
                reverse(v.begin() + s, v.begin() + e);
            }
        }
    }
    
    //solve
    scanf("%d", &C);
    while (C--){
        scanf("%d", &N);
        vector<int> arr(N);
        for (int i = 0; i < N; ++i){
            scanf("%d", &n);
            arr[i] = n;
        }
        
        vector<int> arr2(8);
        for (int i = 0; i < 8; ++i)	arr2[i] = i;
        
        for (int i = 0; i < N; ++i){
            int order = 0;
            for (int j = 0; j < N; ++j){
                if (arr[i] > arr[j])
                    ++order;
            }
            arr2[i] = order;
        }
        printf("%d\n", D[arr2]);
    }
    return 0;
}
