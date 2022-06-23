#include <string>
#include <iostream>
using namespace std;

string T[50];

int main(){
	int R, C;
	cin >> R >> C;
    for (int i = 0; i < R; i++){
		cin >> T[i];
    }

	int sq[5] = {0};

    for (int i = 0 ; i + 1 < R; i++){
		for (int j = 0; j + 1 < C; j++){
			int s = 0;
            for (int k = 0; k < 2; k++){
                for (int l = 0; l < 2; l++){
					s += T[i + k][j + l] == '#' ? 100 : (T[i + k][j + l] == 'X' ? 1 : 0);
                }
            }
			if (s < 100)
				sq[s]++;
		}
    }

    for (int i = 0; i < 5; i++){
		cout << sq[i] << endl;
    }

	return 0;
}
