#include <iostream>
#include <string>
#define MAXN 10000
using namespace std;

string phone[MAXN];
bool call;

int main() {
    int t; 
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n; 
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> phone[j];
        }
        sort(phone, phone + n);
        call = true; 
        for (int j = 0; j < n-1; j++) {
            int k = 0;
            while (k < phone[j+1].size() && k < phone[j].size() && phone[j][k] == phone[j+1][k]) {
                k++;
            }
            if (k == phone[j+1].size()|| k == phone[j].size() || phone[j][k] == phone[j+1][k]) {
                call = false;
            } 
        }
        if (call) cout << "YES\n";
        else cout << "NO\n";
    }
}
