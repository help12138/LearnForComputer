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
/*
***************************************
* *******�й�ϣ��ͻ�汾****************
* *************************************
*/
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



/*
***************************************
* *******�޹�ϣ��ͻ�汾****************
* *************************************
*/

class HashMapChaining {
private:
	int size;  // ��ֵ������
	int capacity;  // ��ϣ������
	double loadThres;  // ������ֵ
	int extendRatio;  // ���ݱ���
	vector<vector<Pair*>> buckets;  // Ͱ����
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

	// ��������
	double loadFactor() {
		return (double)size / (double)capacity;
	}

	// ����
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

	// ��ѯ
	string get(int key) {
		int index = hasFunc(key);
		for (Pair* pair : buckets[index]) {
			if (pair->key == key) {
				return pair->val;
			}
		}
		return "";
	}

	// ���
	void put(int key, string val) {
		// ���������ӳ�����ֵʱ, ִ������
		if (loadFactor() > loadThres) {
			extend();
		}
		int index = hasFunc(key);
		for (Pair *pair: buckets[index]) {
			if (pair->key == key) {
				// �������
				pair->val = val;
			}
		}
		buckets[index].push_back(new Pair(key, val));
		size++;

	}
	// ɾ��
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
	// ��ӡ
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