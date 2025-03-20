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
/*
***************************************
* *******有哈希冲突版本****************
* *************************************
*/
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



/*
***************************************
* *******无哈希冲突版本****************
* *************************************
*/

class HashMapChaining {
private:
	int size;  // 键值对数量
	int capacity;  // 哈希表容量
	double loadThres;  // 扩容阈值
	int extendRatio;  // 扩容倍数
	vector<vector<Pair*>> buckets;  // 桶数组
public:
	HashMapChaining() :size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2) {
		buckets.resize(capacity);
	}

	~HashMapChaining(){
		for (auto& bucket : buckets) {
			for (Pair* pair : bucket) {
				delete pair;
			}
		}
	}

	int hasFunc(int key) {
		return key % capacity;
	}

	// 负载因子
	double loadFactor() {
		return (double)size / (double)capacity;
	}

	// 扩容
	void extend() {
		vector<vector<Pair*>> bucketsTmp = buckets;
		capacity *= extendRatio;
		buckets.clear();
		buckets.resize(capacity);
		size = 0;
		for (auto& bucket : bucketsTmp) {
			for (Pair* pair : bucket) {
				put(pair->key, pair->val);
				delete pair;
			}
		}
	}

	// 查询
	string get(int key) {
		int index = hasFunc(key);
		for (Pair* pair : buckets[index]) {
			if (pair->key == key) {
				return pair->val;
			}
		}
		return "";
	}

	// 添加
	void put(int key, string val) {
		// 当负载因子超过阈值时, 执行扩容
		if (loadFactor() > loadThres) {
			extend();
		}
		int index = hasFunc(key);
		for (Pair *pair: buckets[index]) {
			if (pair->key == key) {
				// 有则更新
				pair->val = val;
			}
		}
		buckets[index].push_back(new Pair(key, val));
		size++;

	}
	// 删除
	void remove(int key) {
		int index = hasFunc(key);
		auto& bucket = buckets[index];
		for (int i = 0; i < bucket.size(); i++) {
			if (bucket[i]->key == key) {
				Pair* tmp = bucket[i];
				bucket.erase(bucket.begin() + i);
				delete tmp;
				size--;
				return;
			}
		}
	}
	// 打印
	void print() {
		for (auto& bucket : buckets) {
			cout << "[";
			for (Pair* pair : bucket) {
				cout << pair->key << " -> " << pair->val << ", ";
			}
			cout << "]\n";
		}
	}

};

int main() {
	ArrayHashMap map;
	map.put(1, "man");
	map.put(2, "man");
	map.put(3, "man");
	map.put(4, "man");
	map.remove(2);
	map.print();
	return 0;
}