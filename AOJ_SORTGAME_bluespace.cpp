// BFS

#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int C, N;
int n;

int main(){
    scanf("%d", &C);
    while(C--){
        scanf("%d", &N);
        vector<int> arr(N);
        for(int i = 0; i < N; ++i){
            scanf("%d", &n);
            arr[i] = n;
        }
        
        vector<int> sorted(arr);
        sort(sorted.begin(), sorted.end());
        
        map<vector<int>,int> dist;
        queue<vector<int>> q;
        q.push(arr);
        dist[arr] = 0;
        
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            
            if(sorted == v){
                printf("%d\n", dist[v]);
                break;
            }
            
            int d = dist[v];
            
            for(int s = 0; s < N-1; ++s){
                for(int e = s+2; e <= N; ++e){
                    reverse(v.begin()+s, v.begin()+e);
                    if(dist.count(v) == 0){
                        q.push(v);
                        dist[v] = d+1;
                    }
                    reverse(v.begin()+s, v.begin()+e);
                }
            }
        }
    }
    return 0;
}
