// 다익스트라

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int A[125][125];

struct Pos{
    int y, x;
    
    bool operator<(const Pos& a) const {
        return A[y][x] > A[a.y][a.x];
    }
};

int N;
int map[125][125];
int C;

Pos m[4] = { {1,0},{0,1},{-1,0},{0,-1} };

bool check(int y, int x){
    if(x < 0 || y < 0 || x >= N || y >= N)  return false;
    return true;
}

int main(){
    while(1){
        scanf("%d\n", &N);
        if(N == 0)   break;
        
        memset(A, 0x7f, sizeof(A));
        
        ++C;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j)
                scanf("%d", &map[i][j]);
            scanf("\n");
        }
        
        bool B[125][125] = {false};
        priority_queue<Pos> q;

        A[0][0] = map[0][0];
        q.push({0,0});
        
        while(!q.empty()){
            auto node = q.top();
            q.pop();
            
            if(node.y == N-1 && node.x == N-1){
                printf("Problem %d: %d\n", C, A[node.y][node.x]);
                break;
            }
            
            for(int i = 0; i < 4; ++i){
                Pos t = {node.y + m[i].y, node.x + m[i].x};
                if(check(t.y, t.x)){
                    if(A[t.y][t.x] > A[node.y][node.x]+map[t.y][t.x])
                        A[t.y][t.x] = A[node.y][node.x]+map[t.y][t.x];
                    if(!B[t.y][t.x]){
                        B[t.y][t.x] = true;
                        q.push(t);
                    }
                    
                }
            }
        }
    }
    
    return 0;
}
