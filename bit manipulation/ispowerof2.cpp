#include <iostream>
using namespace std;

bool ispowerof2(int n){
	return (n && !(n & n-1));
}

int main() {
	// your code goes here
   	
   	cout<<ispowerof2(16);
	return 0;
}
