#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int n,m,k,l;
    int note;
    int switches = 0;
    bool notes_usable[1000][1000];
    memset(notes_usable,false,sizeof(notes_usable));
    vector<int> note_song;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> k;
        for (int j = 0; j < k; j++){
            cin >> l;
            notes_usable[i][l] = true;
        }
    }
    for (int i = 0; i < m; i++){
        cin >> note;
        note_song.push_back(note);
    }
 
    int a, b, c;
    a = 0;
    while (a < m){
        b = -1;
        for (int i = 0; i < n; i++) {
            c = 0;
            for (int j = a; j < m; j++) {
                if (notes_usable[i][note_song[j]] == true){
                    c++;
                }
                else break;
            }
            b = max(c,b);
        }
        a = a + b;
        switches++;
    }
    cout << switches-1 << endl;
    return 0;
}