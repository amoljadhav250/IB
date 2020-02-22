#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
	map<char, TrieNode*> m;
	bool isEnd;
};

TrieNode *getTrieNode(){
	TrieNode* node = new TrieNode;
	node->isEnd=false;
	return node;
}

void insert(TrieNode* root, string s){
	char c;
	TrieNode* t=root;
	for(int i=0;i<s.length();i++){
		c=s[i];
		if(t->m[c]==NULL){
			t->m[c]=getTrieNode();
		}
		t=t->m[c];
	}
	t->isEnd=true;
}

int search(TrieNode *root, string s){
	char c;
	TrieNode *t=root;
	for(int i=0;i<s.length();i++){
		c=s[i];
		if(t->m[c]==NULL){
			return 0;
		}
		t=t->m[c];
	}
	if(t!=NULL && t->isEnd==true){
		return 1;
	}
	return 0;
}

void insert_good_words(TrieNode *root, string s){
	int sum=0;
	string a="";
	for(int i=0;i<s.length();i++){
		if(s[i]=='_'){
			if(a.length()>0){
				//sum++;
				//cout<<a<<endl;
				insert(root,a);
			}
			a="";
			continue;
		}else{
			a+=s[i];
		}
	}
	if(a.length()>0){
		//sum++;
		insert(root,a);
	}
	//return sum;
}


int good_words_count(TrieNode *root, string s){
	int sum=0;
	string a="";
	for(int i=0;i<s.length();i++){
		if(s[i]=='_'){
			if(a.length()>0){// greater than 0 important
				if(search(root,a)==1) sum++;
			}
			a="";
			continue;
		}else{
			a+=s[i];
		}
	}
	if(a.length()>0){
			if(search(root,a)==1) sum++;
	}
	return sum;
}

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first>b.first){
		return true;
	}else if(a.first<b.first){
		return false;
	}else{
		if(a.second<=b.second){
			return true;
		}else{
			return false;
		}
	}
}

void printTemp(vector< pair<int,int> > temp){
	for(int i=0;i<temp.size();i++){
		cout<<temp[i].first<<" "<<temp[i].second<<endl;
	}
	cout<<endl;
}


vector<int> solveUtil(string S, vector<string> &R){
	vector<int> ans;
	TrieNode *root=getTrieNode();
	insert_good_words(root, S);
	vector< pair<int,int> > temp;
	for(int i=0;i<R.size();i++){
		temp.push_back(make_pair(good_words_count(root, R[i]),i));
	}
	//printTemp(temp);
	stable_sort(temp.begin(), temp.end(), compare);
	//printTemp(temp);
	for(int i=0;i<temp.size();i++){
		ans.push_back(temp[i].second);
	}
	return ans;
}

vector<int> solve(string A, vector<string> &B) {
	return solveUtil(A,B);
}


int main() {
	
	string S = "cool_ice_wifi";
    vector<string> R = {"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};

	vector<int> ans=solve(S,R);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
