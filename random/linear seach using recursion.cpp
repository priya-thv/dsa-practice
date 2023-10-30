#include <iostream>
using namespace std;
bool search(int *arr,int size,int key){
	if(size==0){
		return false;
	}
	if(arr[0]==key){
		return true;
	}
	else{
		bool l=search(arr+1,size-1,key);
		return l;
	}
}

int main() {
	int arr[5]={4,2,3,1,6};
	int key=1;
	int size=5;
	bool ans=search(arr,size,key);
	if(ans){
		cout<<"present";
	}else{
		cout<<"not present";
	}
}
