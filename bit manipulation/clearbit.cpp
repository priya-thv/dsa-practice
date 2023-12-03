#include <iostream>
using namespace std;

int clearbit(int n,int pos){
	int mask=~(1<<pos);
	return (n & mask);
}

int main() {
	// your code goes here
   	
   	cout<<clearbit(5,2);
	return 0;
}
