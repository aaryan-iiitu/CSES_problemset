#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

int maxbits;
struct trienode{
	int value;
	trienode *arr[2];
};

trienode *newNode(){
	trienode *temp = new trienode;
	temp->value = 0;
	temp->arr[0] = NULL;
	temp->arr[1] = NULL;
	return temp;
}
void insert(trienode *root, int pre_xor, int max_bits){
	trienode *temp = root;
 
	bool val;
	for (int i=max_bits; i>=0; i--){
		val = pre_xor & (1<<i);
 
		if (temp->arr[val] == NULL) temp->arr[val] = newNode();
		temp = temp->arr[val];
	}
 
	temp->value = pre_xor;
}
int query(trienode *root, int pre_xor, int max_bits){
	trienode *temp = root;
	
	bool val;
	for (int i=max_bits; i>=0; i--){
		val = pre_xor & (1<<i);
 
		if (temp->arr[!val] != NULL) temp = temp->arr[!val];
		else if (temp->arr[val] != NULL) temp = temp->arr[val];
	}
	
	return pre_xor^(temp->value);
}
signed main() {
	int n;
	cin>>n;
	vector<int>a(n);
	for(int &x:a)cin>>x;
	int mx=*max_element(a.begin(),a.end());
	for(int i=0;i<=32;i++){
	    if((1LL<<i)&mx)maxbits=i;
	}
	trienode*root=newNode();
	insert(root,0,maxbits);
	int res=0,pre_xor=0;
	for(int i=0;i<n;i++){
	    pre_xor^=a[i];
	    insert(root,pre_xor,maxbits);
	    res=max(res,query(root,pre_xor,maxbits));
	}
	cout<<res<<endl;
}
