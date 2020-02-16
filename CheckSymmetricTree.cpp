#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
  int isSameTree(TreeNode* A, TreeNode* B) {
  	if(A==NULL && B==NULL){
  		return 1;
  	}else if(A==NULL && B!=NULL){
  		return 0;
  	}else if(A!=NULL && B==NULL){
  		return 0;
  	}else{
  		return (A->val==B->val) && isSameTree(A->left,B->right) && isSameTree(A->right,B->left);
  	}
}

int isSymmetric(TreeNode* A) {
	return isSameTree(A,A);
}

int main() {
	cout<<"Hellow World!"<<endl;
	return 0;
}
