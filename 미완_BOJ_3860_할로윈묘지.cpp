// 벨만-포드 알고리즘
#include <iostream>
using namespace std;
#define INF (9000100)

int R, C;
int G, E;
int map[33][33];
int hole[910][3];
int times[33][33];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void input(){
    int r, c;
    int i, j;

    for(i=1; i<=R; i++){
        for(j=1; j<=C; j++){
            map[i][j] = 0;
        }
    }
    cin >> G;
    for(i=0; i<G; i++){
        cin >> c >> r;
        map[r + 1][c + 1] = -1;
    }

    cin >> E;
    for(i=1; i<=E; i++){
        cin >> c >> r >> hole[i][1] >> hole[i][0] >> hole[i][2];
        (hole[i][0])++; (hole[i][1])++;
        map[r + 1][c + 1] = i;
    }

    // 테두리
    for(i=0; i<=R+1; i++) map[i][0] = map[i][C + 1] = -1;
    for(i=0; i<=C+1; i++) map[0][i] = map[R + 1][i] = -1;
}

void getSol(){
    int i, j, k;
    int tot = R * C - E - 1;
    int nr, nc, tmp, hnum;

    // 초기화
    for(i=1; i<=R; i++){
        for(j=1; j<=C; j++){
            times[i][j] = INF;
        }
    }
    times[1][1] = 0;
    
    while(tot--){
        for(i=1; i<=R; i++){
            for(j=1; j<=C; j++){
                if(map[i][j] < 0 || times[i][j] == INF || (i == R && j == C)) continue;
                if(map[i][j] == 0){ // 잔디
                    for(k=0; k<4; k++){
                        nr = i + dr[k];
                        nc = j + dc[k];
                        if(map[nr][nc] < 0) continue;
                        tmp = times[i][j] + 1;
                        if(tmp < times[nr][nc]) times[nr][nc] = tmp;
                    }
                } else{ // 귀신 구멍
                    hnum = map[i][j];
                    nr = hole[hnum][0];
                    nc = hole[hnum][1];
                    tmp = times[i][j] + hole[hnum][2];
                    if(tmp < times[nr][nc]) times[nr][nc] = tmp; 
                }
            }
        }
    }

    // 음의 사이클 확인
    for(i=1; i<=R; i++){
        for(j=1; j<=C; j++){
            if(map[i][j] < 0 || times[i][j] == INF || (i == R && j == C)) continue;
            if(map[i][j] == 0){ // 잔디
                for(k=0; k<4; k++){
                    nr = i + dr[k];
                    nc = j + dc[k];
                    if(map[nr][nc] < 0) continue;
                    tmp = times[i][j] + 1;
                    if(tmp < times[nr][nc]) {
                        cout << "Never\n";
                        return;
                    }
                }
            } else{ // 귀신 구멍
                hnum = map[i][j];
                nr = hole[hnum][0];
                nc = hole[hnum][1];
                tmp = times[i][j] + hole[hnum][2];
                if(tmp < times[nr][nc]) {
                    cout << "Never\n";
                    return;
                }
            }
        }
    }

    if(times[R][C] == INF){
        cout << "Impossible\n";
        return;
    }

    cout << times[R][C] << "\n";
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1){
        cin >> C >> R;
        if(C == 0 && R == 0) break;
        input();
        getSol();
    }
}