#include <unordered_map>
#include <list>
#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

class LRU{
	
	public:
	int capacity;
	int size;
	unordered_map<int,int> cache;
	list<int> lru;
	
	LRU(int c){
		size=c;
	}
	void Set(int key, int value){
		if(cache.find(key)!=cache.end()){
			cache[key]=value;
			lru.remove(key);
			lru.push_back(key);
		}else{
			if(lru.size()==capacity){
				int f=lru.front();
				lru.pop_front();
				cache.erase(f);
				cache[key]=value;
				lru.push_back(key);
			}else{
			cache[key]=value;
			lru.push_back(key);				
			}
		}
	}
	
	int Get(int key){
		if(cache.find(key)!=cache.end()){
			lru.remove(key);
			lru.push_back(key);
			return cache[key];
		}else{
			return -1;
		}
	}
};

LRU Cache(1000005);

class LRUCache{
	public:
	LRUCache(int capacity);
	int get(int key);
	void set(int key, int value) ;
};

LRUCache::LRUCache(int capacity) {
		Cache.capacity=capacity;
		Cache.lru.clear();
		Cache.cache.clear();
	}

int LRUCache::get(int key) {
		return Cache.Get(key);
	}

void LRUCache::set(int key, int value) {
	Cache.Set(key, value);
	}

int main() {
	LRUCache Cache(2);
	Cache.set(1,10);
	Cache.set(5,12);
	cout<<Cache.get(5)<<endl;
	cout<<Cache.get(1)<<endl;
	cout<<Cache.get(10)<<endl;
	Cache.set(6,14);
	cout<<Cache.get(5)<<endl;
	return 0;
}
