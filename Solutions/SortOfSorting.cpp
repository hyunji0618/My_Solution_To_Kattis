#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return (a.substr(0,2) < b.substr(0,2));
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        vector<string> names(n,"");
        for (int i=0; i<n; i++){
            cin >> names[i];
        }
        stable_sort(names.begin(),names.end(), cmp);
        for (int j=0; j<n; j++){
            cout << names[j] << endl;
        }
        cout << endl;
    }
    return 0;
}