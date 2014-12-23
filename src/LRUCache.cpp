#include <iostream>
#include <unordered_map>

using namespace std;

// Least Recently Used (LRU) cache
class LRUCache {
public:
	LRUCache(int capacity) {
		len = capacity;
	}

	// Get the value (will always be positive) of the key if the key exists in the cache, 
	// otherwise return -1.
	int get(int key) {
		if (kv.find(key) == kv.end())
			return -1;
		freshKeyList(key);
		return kv[key];
	}

	// Set or insert the value if the key is not already present. 
	// When the cache reached its capacity, 
	// it should invalidate the least recently used item before inserting a new item.
	void set(int key, int value) {
		if (top < len) {
			if (kv.find(key) == kv.end()) {
				kl.insert(kl.begin(), key);
			}
			else {
				freshKeyList(key);
			}
			top++;
		}
		else {
			kv.erase(kl.front());
			ki.erase(kl.front());
			kl.front() = key;
		}
		kv[key] = value;
		ki[key] = kl.begin();
	}

private:
	void freshKeyList(int key) {
		int t = *ki[key];
		kl.erase(ki[key]);
		kl.insert(kl.begin(), t);
		ki[key] = kl.begin();
	}

private:
	unordered_map<int, int> kv;
	unordered_map<int, list<int>::iterator> ki;
	list<int> kl;
	int len;
	int top;
};

int main(void) {

	LRUCache lru(1);
	int res;
	lru.set(2, 1);
	res = lru.get(2); cout << res << ", ";
	lru.set(3, 2);
	res = lru.get(2); cout << res << ", ";
	res = lru.get(3); cout << res << ", ";

	return 0;
}