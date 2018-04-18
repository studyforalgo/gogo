// BFS, math(mod)

// n*a+m = c -> c%n = m
// D 숫자를 하나씩 증가시키면서 체크 - (c*10+d) mod n => m
// 최단 거리 v->u => v : (c+d) mod n, u : m, edge : d

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node{
    int num;
    int parent;
    int d;
    Node() : parent(-1) {}
};

int T;
int N,M;
char D[10];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%s %d %d", D, &N, &M);
        
        vector<int> listD;
        for(int i = 0; D[i]; ++i)
            listD.push_back(D[i] - '0');
        sort(listD.begin(), listD.end());
        
        vector<Node> nodes(N*2);
        nodes[0].num = 0;
        nodes[0].parent = 0;
        nodes[0].d = 0;
        
        queue<Node> q;
        q.push(nodes[0]);
        while(!q.empty()){
            auto& v = q.front();
            q.pop();
            
            for (int d : listD){
                int e = v.num * 10 + d;
                e = (e < N) ? e % N : e % N + N;
                
                if(e == N+M){
                    vector<int> ans(1,d);
                    while(v.parent != v.num){
                        ans.push_back(v.d);
                        v = nodes[v.parent];
                    }
                    reverse(ans.begin(), ans.end());
                    if(ans[0] != 0) printf("%d", ans[0]);
                    for(int i = 1; i < ans.size(); ++i)
                        printf("%d", ans[i]);
                    goto ALGO_END;
                }
                
                auto& u = nodes[e];
                if(u.parent == -1){
                    u.num = e;
                    u.parent = v.num;
                    u.d = d;
                    q.push(u);
                }
            }
            
        }
        printf("IMPOSSIBLE");
    ALGO_END:
        printf("\n");
    }
    
    return 0;
}
