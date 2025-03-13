#include "count.h"

struct Pair
{
	// 用来表示键值对
	int key;
	string val;
	Pair(int key, string val) {
		this->key = key;
		this->val = val;
	}
};

// 基于数组实现的哈希表
class ArrayHashMap
{
public:
	ArrayHashMap();
	~ArrayHashMap();

	// 哈希函数
	// 通过哈希函数来确认key值
	int hashFunc(int key) {
		int index = key % 100;
		return index;
	}

	// 通过key查询
	string get(int key) {
		int index = hashFunc(key);
		Pair* pair = buckets[index];
		if (pair == nullptr) {
			return " ";
		}
		return pair->val;
	}

	// 添加键值对
	void put(int key, string val) {
		Pair* pair = new Pair(key, val);
		int index = hashFunc(key);
		buckets[index] = pair;
	}

	// 删除指定键值对
	void remove(int key) {
		int index = hashFunc(key);
		delete buckets[index];
		buckets[index] = nullptr;
	}

	// 获取所有键值对
	vector<Pair*>pairSet() {
		vector<Pair*>pairSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				pairSet.push_back(pair);
			}
		}
		return pairSet;
	}

	// 获取所有键
	vector<int> keySet() {
		vector<int> keySet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				keySet.push_back(pair->key);
			}
		}
		return keySet;
	}

	// 获取所有值
	vector<string> valSet() {
		vector<string> valSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				valSet.push_back(pair->val);
			}
		}
		return valSet;
	}

	// 打印哈希表
	void print() {
		for (Pair* kv : buckets) {
			if (kv != nullptr) {
				cout << kv->key << "-->" << kv->val << endl;
			}
			
		}
	}

private:
	vector<Pair*> buckets;
};

ArrayHashMap::ArrayHashMap()
{
	buckets = vector<Pair*>(100);
}

ArrayHashMap::~ArrayHashMap()
{
	for (const auto& bucket : buckets) {
		delete bucket;
	}
	buckets.clear();
}

int main() {
	ArrayHashMap map;
	map.put(1, "man");
	map.put(2, "man");
	map.put(3, "man");
	map.put(4, "man");
	map.remove(4);
	map.print();
	return 0;
}