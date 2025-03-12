#include "ListNode.cpp"

#define DEBUG

#ifdef DEBUG
/************************************/
// 链表实现栈
class LinkedListStack
{
private:
	ListNode* stackTop; // 头节点为栈顶
	int stkSize; // 栈的长度
public:
	LinkedListStack();
	~LinkedListStack();

	int size() {
		// 获取栈的长度
		return stkSize;
	}

	bool isEmpty() {
		// 判断是否为空
		return size() == 0;
	}

	void push(int num) {
		// 入栈
		ListNode* node = new ListNode(num);
		node->next = stackTop;
		stackTop = node;
		stkSize++;
	}
	
	int pop() {
		// 删除头元素
		int num = top();
		ListNode* tmp = stackTop;
		stackTop = stackTop->next;
		delete tmp;
		stkSize--;
		return num;
	}
	
	int top() {
		if (isEmpty()) {
			throw out_of_range("栈为空");
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



int main() {

	return 0;
}

#else
/************************************/
// 数组实现栈

int main() {

	return 0;
}
#endif // DEBUG

