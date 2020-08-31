#include <iostream>

using namespace std;

class StackElement {
public:
	int data;
	StackElement* next;
	StackElement() {
		data = 0;
		next = NULL;
	}
};

class MyStack {
	StackElement* mtop;
public:
	MyStack() { mtop = NULL; }
	void push(int x);
	int pop();
	int size();
	bool empty();
	int top();
};

void MyStack::push(int x) {
	if (empty()) {
		StackElement* temp = new StackElement();
		temp->data = x;
		temp->next = NULL;
		mtop = temp;
	}
	else {
		StackElement* temp = new StackElement();
		temp->data = x;
		temp->next = mtop;
		mtop = temp;
	}
}
int MyStack::pop() {
	if (empty()) {
		return -1;
	}
	StackElement* temp = mtop;
	int ret = temp->data;
	mtop = mtop->next;
	delete temp;
	return ret;
}
int MyStack::size() {
	int cnt = 0;
	StackElement* temp = mtop;
	while (temp) {
		cnt++;
		temp = temp->next;
	}
	return cnt;
}
bool MyStack::empty() {
	if (mtop == NULL) {
		return true;
	}
	return false;
}
int MyStack::top() {
	if (empty()) {
		return -1;
	}
	return mtop->data;
}

class Console {
	MyStack stack;
	string cmd;
	int x;
public:
	void run() {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> cmd;
			if (cmd.compare("push") == 0) {
				cin >> x;
				stack.push(x);
			}
			else if (cmd.compare("pop") == 0) {
				cout << stack.pop() << endl;
			}
			else if (cmd.compare("size") == 0) {
				cout << stack.size() << endl;
			}
			else if (cmd.compare("empty") == 0) {
				if (stack.empty()) cout << 1 << endl;
				else cout << 0 << endl;
			}
			else if (cmd.compare("top") == 0) {
				cout << stack.top() << endl;
			}
			else {
				cout << "command is not valid" << endl;
			}
		}
	}
};

int main() {
	Console console;
	console.run();

	return 0;
}