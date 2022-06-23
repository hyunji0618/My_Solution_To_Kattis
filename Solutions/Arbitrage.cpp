#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdexcept>
#include <map>
#define M 200
using namespace std;

int prime_number[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101}; 
const int L = sizeof(prime_number)/sizeof(prime_number[0]);
map<string,int> currencies;

class Arbitrage
{
public:
    int p[L];
    bool ton;
    Arbitrage(){
        ton = true;
    }
    Arbitrage(int a){            
        if (a == 0)
            ton = true;
        else{
            ton = false;
            for (int i = 0; i < L; i++){
                p[i] = 0;
                while (a % prime_number[i] == 0 && a > 0){
                    a /= prime_number[i];
                    p[i]++;
                }
            }
        }
    }
    
    bool operator>(const Arbitrage& b);
    Arbitrage operator*(const Arbitrage& b);
    Arbitrage operator/(const Arbitrage& b);
};

bool Arbitrage::operator>(const Arbitrage& b)
{
    if (ton && b.ton) return false;
    else if (ton && !b.ton) return false;
    else if (!ton && b.ton) return true;
    Arbitrage c = *(this) / b;
    double cal = 0.0;
    for (int i = 0; i < L; i++)
        cal += (double)(c.p[i]) * log((double)prime_number[i]);
    return cal > 0;
}

Arbitrage Arbitrage::operator*(const Arbitrage& b){
    Arbitrage c; 
    if (ton || b.ton){
        c.ton = true; 
    }
    else{
        c.ton = false;
        for (int i = 0; i < L; i++){
            c.p[i] = p[i] + b.p[i];
        }
    }
    return c;
}

Arbitrage Arbitrage::operator/(const Arbitrage& b){
    Arbitrage c;   
    if (ton){
        c.ton = true;
    }
    else {
        c.ton = false;
        for (int i = 0; i < L; i++)
            c.p[i] = p[i] - b.p[i];
    }
    return c;
}

int main(int argc, char* argv[]){
    Arbitrage e[M][M];
    while(1){
        int C, R;
        string cur;
        cin >> C;
        if (!C) break;
        for(int i = 0; i < C; i++){
            cin >> cur;
            currencies[cur] = i;
        }
        cin >> R;
        for(int i = 0; i < C; i++){
            for(int j = 0; j < C; j++){
                e[i][j]=0;
            }
        }
        for(int i = 0; i < C; i++){
            e[i][i]=1;
        }
        for(int i = 0; i < R; i++){
            string code1, code2;
            int Ai, Bi;
            char colon;
            cin >> code1 >> code2;
            cin >> Ai >> colon >> Bi; 
            e[currencies[code1]][currencies[code2]] = Arbitrage(Bi)/Arbitrage(Ai);
        }
        bool OK = true;
        for(int i = 0; i < C; i++){
            for(int j = 0; j < C; j++)	{
                for(int k = 0; k < C; k++){
                    Arbitrage r = e[j][i] * e[i][k];
                    if(r > e[j][k]){
                        e[j][k] = r;
                        if (j == k && e[j][k] > Arbitrage(1)) {
                            OK = false;
                            goto A;
                        }   
                    }
                }
            }
        }
A:  if (OK) cout << "Ok" << endl;
    else cout << "Arbitrage" << endl;
    }
}