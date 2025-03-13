#include "count.h"

struct Pair
{
	// ������ʾ��ֵ��
	int key;
	string val;
	Pair(int key, string val) {
		this->key = key;
		this->val = val;
	}
};

// ��������ʵ�ֵĹ�ϣ��
class ArrayHashMap
{
public:
	ArrayHashMap();
	~ArrayHashMap();

	// ��ϣ����
	// ͨ����ϣ������ȷ��keyֵ
	int hashFunc(int key) {
		int index = key % 100;
		return index;
	}

	// ͨ��key��ѯ
	string get(int key) {
		int index = hashFunc(key);
		Pair* pair = buckets[index];
		if (pair == nullptr) {
			return " ";
		}
		return pair->val;
	}

	// ��Ӽ�ֵ��
	void put(int key, string val) {
		Pair* pair = new Pair(key, val);
		int index = hashFunc(key);
		buckets[index] = pair;
	}

	// ɾ��ָ����ֵ��
	void remove(int key) {
		int index = hashFunc(key);
		delete buckets[index];
		buckets[index] = nullptr;
	}

	// ��ȡ���м�ֵ��
	vector<Pair*>pairSet() {
		vector<Pair*>pairSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				pairSet.push_back(pair);
			}
		}
		return pairSet;
	}

	// ��ȡ���м�
	vector<int> keySet() {
		vector<int> keySet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				keySet.push_back(pair->key);
			}
		}
		return keySet;
	}

	// ��ȡ����ֵ
	vector<string> valSet() {
		vector<string> valSet;
		for (Pair* pair : buckets) {
			if (pair != nullptr) {
				valSet.push_back(pair->val);
			}
		}
		return valSet;
	}

	// ��ӡ��ϣ��
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