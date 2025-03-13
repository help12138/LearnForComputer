#include "count.h"

/************************************/
// ����ʵ��ջ

struct ListNode
{
	// ��������
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {};
};

class LinkedListStack
{
private:
	ListNode* stackTop; // ͷ�ڵ�Ϊջ��
	int stkSize; // ջ�ĳ���
public:
	LinkedListStack();
	~LinkedListStack();

	int size() {
		// ��ȡջ�ĳ���
		return stkSize;
	}

	bool isEmpty() {
		// �ж��Ƿ�Ϊ��
		return size() == 0;
	}

	void push(int num) {
		// ��ջ
		ListNode* node = new ListNode(num);
		node->next = stackTop;
		stackTop = node;
		stkSize++;
	}
	
	int pop() {
		// ɾ��ͷԪ��
		int num = top();
		ListNode* tmp = stackTop;
		stackTop = stackTop->next;
		delete tmp;
		stkSize--;
		return num;
	}
	
	int top() {
		if (isEmpty()) {
			throw out_of_range("ջΪ��");
		}
		return stackTop->val;
	}
};

LinkedListStack::LinkedListStack()
{
	stackTop = nullptr;
	stkSize = 0;
}

LinkedListStack::~LinkedListStack()
{
	while (!isEmpty()) {
		pop();
	}
}


