//#include <iostream>
//using namespace std;
//
//bool isInRange(int y, int x, int n, int m){
//    if(y > n || x > m || y < 1 || x < 1) return false;
//    else return true;
//}
//
//int main(){
//    int n, m;
//    int y, x;
//    cin >> n >> m >> y >> x;
//    int **map = new int*[n+1];
//    for(int i=1; i<=n; i++) map[i] = new int[m+1];
//    for(int i=1; i<=n; i++)
//        for(int j=1; j<=m; j++) cin >> map[i][j];
//
//    if(map[y][x] == 1){
//        cout << "game over";
//        return 0;
//    }
//
//    int adj[3] = {-1, 0, 1};
//    int ans = 0;
//    for(int i=0; i<3; i++)
//        for(int j=0; j<3; j++){
//            int tempY = y + adj[i];
//            int tempX = x + adj[j];
//            if(isInRange(tempY, tempX, n, m)){
//                if(map[tempY][tempX] == 1) ans++;
//            }
//        }
//    cout << ans;
//}