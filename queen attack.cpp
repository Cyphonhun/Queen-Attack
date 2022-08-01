#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {1, 0, 1, -1, -1, 0, -1, 1};
// le, fel, jobbra, balra


int n, k;  //chessboard size, obstacles
set<pair<int, int>> obstacles;

int search(int x, int y, int i, int j){ //Queen position and obstacles
    x+=i; y+=j;

    pair<int, int> temp; //storages of obstacles in temp 
    int steps = 0;
    while(x >= 1 && x <= n && y >= 1 && y <= n){ // start value on board
        temp = *(obstacles.lower_bound(make_pair(x, y))); 
        if(temp.first == x && temp.second == y) //run until hit the first obstacles
        return steps;
        steps++;  //after increase free steps
        x+=i; y+=j;
    }
    return steps;
}

int main(){
    scanf("%d%d", &n, &k);
    
    int x, y;
    scanf("%d%d", &x, &y);
    
    int a, b;
    for (int i = 0; i < k; i++){
        scanf("%d%d", &a, &b);
        obstacles.insert(make_pair(a, b));
    }
    
    int answer = 0;
    for (int i = 0; i < 8; i++){
        answer+=search(x, y, dx[i], dy[i]);
    }
    printf("%d\n", answer);
}
