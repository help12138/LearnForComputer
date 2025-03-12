#include "count.h"

struct ListNode
{
	// 单向链表
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {};
};

//struct ListNode
//{
//	// 双向链表
//	int val;
//	ListNode* next;
//	ListNode* prev;
//	ListNode(int x) :val(x), next(nullptr), prev(nullptr) {};
//};

void insert(ListNode* n0, ListNode* p) {
	// 在n0位置插入p
	ListNode* n1 = n0->next;
	n0->next = p;
	p->next = n1;

}

void remove(ListNode* n0) {
	// 删除首节点下的第一个节点
	if (n0->next == nullptr) {
		return;
	}
	ListNode* p = n0->next;
	ListNode* n1 = p->next;
	n0->next = n1;
	delete p;
}

ListNode* access(ListNode* head, int index) {
	// 查找第index位的节点
	for (int i = 0; i < index; i++)
	{
		if (head->next == nullptr) {
			return nullptr;
		}
		head = head->next;
	}
	return head;
}

int find(ListNode* head, int target) {
	// 查找target所在的节点位置
	int index = 0;
	while (head != nullptr) {
		if (head->val == target) {
			return index;
		}
		head = head->next;
		index++;
	}
	return 0;
}

int mai() {
	ListNode* n0 = new ListNode(1);
	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(6);
	ListNode* n4 = new ListNode(4);

	ListNode* p = new ListNode(15);

	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	
	insert(n0, p);
	remove(n0);
	ListNode* result = access(n0, 4);
	int res = find(n0, 14);
	cout << res;
	return 0;
}