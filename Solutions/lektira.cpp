#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
   string str;
    string r = "~";
   cin >> str;

   for(int i = 1; i < str.size(); ++i) {
      for( int j = i+1; j < str.size(); ++j ) {
         string x = str.substr( 0, i );
         string y = str.substr( i, j-i );
         string z = str.substr( j );
         reverse( x.begin(), x.end() );
         reverse( y.begin(), y.end() );
         reverse( z.begin(), z.end() );
         string t = x+y+z;
          if(t < r){
             r = t;
          }
      }
   }
   cout << r << endl;
   return 0;
}
