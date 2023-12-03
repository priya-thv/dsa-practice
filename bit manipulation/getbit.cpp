#include <iostream>
using namespace std;

int getbit(int n,int pos){
	return ((n &(1 <<pos))!=0);
}

int main() {
	// your code goes here
	cout<<getbit(5,2)<<endl;
	return 0;
}
