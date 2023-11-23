#include<bits/stdc++.h>
using namespace std;
int binary(vector<int>a,int start,int end,int key){
	if(start>end){
		return -1;
	}
	int mid=start+(end-start)/2;
	if(a[mid]==key && a[mid-1]!=key){
		return mid;
	}
	else if(key<=a[mid]){
		return binary(a,start,mid-1,key);
	}
	else if(key>a[mid]){
		return binary(a,mid+1,end,key);
	}
}

int main(){
	vector<int>a(10);
	for(int i=0;i<a.size();i++){
		cin>>a[i];
	}
	int key;
	cin>>key;
   int result = binary(a, 0, a.size() - 1, key);
    
    if (result != -1) {
        cout << "First occurrence found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }
}
