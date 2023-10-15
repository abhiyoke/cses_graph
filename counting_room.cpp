#include <iostream>
#include <vector>
 
using namespace std;
 
// Define directions for moving up, down, left, and right
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
 
void dfs(vector<vector<char>>& map, vector<vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;
    
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size() && map[newX][newY] == '.' && !visited[newX][newY]) {
            dfs(map, visited, newX, newY);
        }
    }
}
 
int countRooms(vector<vector<char>>& map) {
    int n = map.size();
    int m = map[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    int roomCount = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.' && !visited[i][j]) {
                dfs(map, visited, i, j);
                roomCount++;
            }
        }
    }
    
    return roomCount;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
 
    int rooms = countRooms(map);
    cout << rooms << endl;
 
    return 0;
}
