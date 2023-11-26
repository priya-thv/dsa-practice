#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here'
	priority_queue<int,vector<int>>pq;
	pq.push(3);
	pq.push(1);
	pq.push(2);
	cout<<pq.top();
	//in the stl library max heap is the default creation that is why we use greater<int>to reverse it so it will create min heap stl l instead of max heap
	//vector<int>is a container for both the min and max heap
	priority_queue<int,vector<int>,greater<int>>pqm;
	pqm.push(3);
	pqm.push(1);
	pqm.push(2);
	cout<<pqm.top();
	return 0;
}
