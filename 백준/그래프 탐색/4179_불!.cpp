// 카운팅을 잘못 고려함..
#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> coord;

const string IMPOSSIBLE = "IMPOSSIBLE";
int const BLOCKED = 2000000001;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int R, C, hazard[1002][1002];
bool checked[1002][1002];

queue<coord> burn;
queue<coord> jh;

// 불의 이동에 대한 고려
bool check_fire_coordinate(int x, int y, int x_bound, int y_bound) {
    if((x >= 0 && x < x_bound) && (y >= 0 && y < y_bound)) {
        // 불이 이미 붙었거나, 벽이라면 불 붙이기 그만.
        if(hazard[x][y] != 0) return false;
        return true;
    }
    else return false;
}

bool check_jh_coordinate(int x, int y, int x_bound, int y_bound, int move_count) {
    // 갔던길은 다시 가지 마라. 막힌길을 가지마라.
    if(checked[x][y] || hazard[x][y] == BLOCKED) return false;
    if((x >= 0 && x < x_bound) && (y >= 0 && y < y_bound)) {
        // 불이 애초에 없는 경우를 0으로 설정함. 그떄는 가라.
        if(hazard[x][y]==0) return true;
        // 불이 이미 붙었다면 가지마라.
        if(move_count >= hazard[x][y]) return false;
        else return true;
    }
    else return false;
}

int main(void) {
    
    cin >> R >> C;
    for(int i=0; i<R; ++i) {
        string line; cin >> line;
        for(int j=0; j<C; ++j) {
            if(line[j] == '#') hazard[i][j] = BLOCKED;
            else if(line[j] == 'F') {
                hazard[i][j] = BLOCKED;
                burn.push({i, j});
            }
            else if(line[j] == 'J') {
                checked[i][j] = true;
                jh.push({i, j});
            }
        }
    }
    
    // movement
    // 불이 없는 경우를 0으로 했기 때문에 0으로 시작하면 틀린다.
    int fire_movement = 1;
    int jh_movement = 1;
    
    while(!burn.empty()) {
        int size = (int)burn.size();
        for(int i=0; i<size; ++i) {
            coord cur_fire = burn.front(); burn.pop();
            for(int j=0; j<4; ++j) {
                int x = cur_fire.first + dx[j];
                int y = cur_fire.second + dy[j];
                if(check_fire_coordinate(x, y, R, C)) {
                    hazard[x][y] = fire_movement;
                    burn.push({x, y});
                }
            }
        }
        fire_movement += 1;
    }
    
    bool escaped = false;
    while(!jh.empty() && !escaped) {
        int size = (int)jh.size();
        for(int i=0; i<size; ++i) {
            coord cur_jh = jh.front(); jh.pop();
            int x = cur_jh.first;
            int y = cur_jh.second;
            if(x == 0 || y == 0 || x == R-1 || y == C-1) {
                escaped = true;
                break;
            }
            for(int j=0; j<4; ++j) {
                int x = cur_jh.first + dx[j];
                int y = cur_jh.second + dy[j];
                if(check_jh_coordinate(x, y, R, C, jh_movement)) {
                    checked[x][y] = true;
                    jh.push({x, y});
                }
            }
        }
        jh_movement += 1;
    }
    
    if(escaped) cout << jh_movement - 1 << endl;
    else cout << IMPOSSIBLE << endl;
    
    return 0;
}
