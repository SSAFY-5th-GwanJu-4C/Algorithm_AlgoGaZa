#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n, m; cin >> n >> m; // 도시, 버스 갯수 정의 및 입력
    vector<pair<int, int>> list[n+1];
    vector<int> pass(n+1, -1);
                             
    for(int i=0; i < m; i++){
        int x, y, value;
        cin >> x >> y >> value;
        list[x].push_back(make_pair(y, value));
    }
    int start, end; cin >> start >> end;
    
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    pass[start] = 0;
    
    while (!q.empty()) {
        int now = q.front().first;
        int value = q.front().second;
        q.pop();
        for(int i=0; i < list[now].size(); i++){
            int next = list[now][i].first;
            int next_value = list[now][i].second + value;
            if(pass[next] == -1 || pass[next] > next_value){
                pass[next] = next_value;
                q.push(make_pair(next, next_value));
            }
        }
    }
    cout << pass[end] << "\n";

    
    return 0;
}
