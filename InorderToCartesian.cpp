#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
 
  
  void inOrder(TreeNode *root){
  		if(root==NULL){
  			return;
  		}
  		inOrder(root->left);
  		cout<<root->val<<" ";
  		inOrder(root->right);
  }
  
    void preOrder(TreeNode *root){
  		if(root==NULL){
  			return;
  		}
  		cout<<root->val<<" ";
  		preOrder(root->left);
  		preOrder(root->right);
  }
  
    void postOrder(TreeNode *root){
  		if(root==NULL){
  			return;
  		}
  		postOrder(root->left);
  		postOrder(root->right);
  		cout<<root->val<<" ";
  }
  
  TreeNode* getCartesian(vector<int> &in,int l,int h){
  		if(l>h){
  			return NULL;
  		}
  		int m=l;
  		for(int i=l;i<=h;i++){
  			if(in[i]>in[m]){
  				m=i;
  			}
  		}
  		//cout<<l<<" "<<h<<" "<<m<<" "<<in[m]<<endl;
  		
  		TreeNode* t=new TreeNode(in[m]);
  		/*if(l==h){
  			return t;
  		}*/
  		t->left=getCartesian(in,l,m-1);
  		t->right=getCartesian(in,m+1,h);
  		return t;
  }


TreeNode* buildTree(vector<int> &A) {
	return getCartesian(A,0,A.size()-1);
}

int main() {
	TreeNode *root1=new TreeNode(3);
	root1->left=new TreeNode(2);
	root1->left->left=new TreeNode(1);
	/*inOrder(root1);
	cout<<endl;
	preOrder(root1);
	cout<<endl;
	postOrder(root1);
	cout<<endl;*/
	vector<int> A{4,1,5,2,3};
	TreeNode *root2=buildTree(A);
	inOrder(root2);
	cout<<endl;
	preOrder(root2);
	cout<<endl;
	postOrder(root2);
	cout<<endl;
	return 0;
}
