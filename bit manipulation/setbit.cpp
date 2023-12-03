#include <iostream>
using namespace std;


int setbit(int n,int pos){
	return (n|(1<<pos));
}

int main() {
	// your code goes here
   	
   	cout<<setbit(5,1);
	return 0;
}
