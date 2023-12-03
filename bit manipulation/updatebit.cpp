#include <iostream>
using namespace std;

int updatebit(int n,int pos ,int val){
	int mask=~(1<<pos);
	 int t=n & mask;
	 return (t|(val<<pos));
}

int main() {
	// your code goes here
   	
   	cout<<updatebit(5,1,1);
	return 0;
}
