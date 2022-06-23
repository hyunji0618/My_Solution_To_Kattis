#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void factoring(vector<int> &v, string &cha, int a) {
    int left = 0;
    int right = 0;
	v.assign(cha.length() - a, -1);
    int N = cha.length() - a;
	for (int i = 1; i < N; i++) {
        if (i > right) {
			left = right = i;
			while (cha[right - left + a] == cha[right + a] && right < N) right++;
			v[i] = right - left; 
            right--;
		} 
        else if (v[i - left] >= right - i + 1) {
			left = i;
			while (cha[right - left + a] == cha[right + a] && right < N) right++;
			v[i] = right - left; 
            right--;
		} 
        else {
            v[i] = v[i - left];
        }
	}
}

int main() {
	string S;
	cin >> S;
	vector <vector<int> > substring(S.length(), vector<int>(S.length(), 100000));
	for (int i = S.length() - 1; i >= 0; i--) {
		vector<int> v;
		factoring(v, S, i);
		for (int j = i; j < S.length(); j++) {
			bool f;
            int b = j - i + 1;
            f = false;
			for (int k = 0; k < b; k++) {
				if (b % (k+1) != 0) continue;
				f = true;
				for (int l = k + 1; f && l < b; l = l * 2) {
					f = f && (l + v[l] >= min(b, 2 * l));
				}
				if (f == true) { 
					substring[i][j] = min(substring[i][i + k], substring[i][j]);				
				}
			}
			for (int k = i; k < j; k++){
				if (substring[i][j] > substring[i][k] + substring[k + 1][j]) {
					substring[i][j] = substring[i][k] + substring[k + 1][j];
                }
            }
			if (substring[i][j] > 10000) {
                substring[i][j] = j - i + 1;
            }
		}
	}
	cout << substring[0][S.length() - 1] << endl;
}