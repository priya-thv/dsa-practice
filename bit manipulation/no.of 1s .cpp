class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
           count +=n&1;
           n>>=1;
        }
        return count;
    }
};

sol2
#include <iostream>
using namespace std;

int numberof1(int n){
	int count=0;
	while(n){
		n=n &(n-1);
		count++;
	}
	return count;
}

int main() {
	// your code goes here
   	
   	cout<<numberof1(7);
	return 0;
}
