#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair <int, int> L, pair <int, int> U) {
    if(L.second == U.second) {
        return L.first < U.first;
    }
    return L.second < U.second;
}

int main() {
    int N;
	int room = 1;
    cin >> N;
    vector <pair <int, int> > minion;
    for(int i = 0; i < N; i++) {
        pair <int, int> tem;
        cin >> tem.first >> tem.second;
        minion.push_back(tem);
    }
    sort(minion.begin(), minion.end(), cmp);
    int x = minion[0].second;

    for(int i = 1; i < minion.size(); i++) {
        if(minion[i].first > x) {
            x = minion[i].second;
            room++;
        }
    }
	
    cout << room << endl;
}