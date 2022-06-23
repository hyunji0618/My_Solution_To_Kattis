#include <iostream>
#include <string>
#include <vector>

int main() {
	int n,m;
	double long r;
    while(std::cin>>n){
    	while(std::cin>>m){
    		r = double (n)/double (m);
    		std::cout << r << std::endl;
    		break;
    	}
    }
}