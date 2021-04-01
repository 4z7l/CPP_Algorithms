#include <iostream>
#include <stack>

using namespace std;

class QueueElement {
private:
    int data;
    QueueElement* next;
public:
    QueueElement() { data = -1; next = NULL; }
    void setData(int data) { this->data = data; }
    void setNext(QueueElement*next) { this->next = next; }
    int getData() { return data; }
    QueueElement* getNext() { return next; }
};

class MyQueue {
private:
    QueueElement* front;
    QueueElement* back;
    int size;
public:
    MyQueue() { front = back = NULL; size = 0; }
    void push(int x);
    int pop();
    int getSize();
    bool isEmpty();
    int getFront() { 
        if (front != NULL) return front->getData();
        else return -1; 
    }
    int getBack() {
        if (back != NULL) return back->getData();
        else return -1;
    }
};
void MyQueue::push(int x) {
    //공백 큐인 경우
    if (isEmpty()) {
        QueueElement* temp = new QueueElement();
        temp->setData(x);
        temp->setNext(NULL);
        front = temp;
        back = temp;
    }
    //공백 큐가 아닌 경우 back에 삽입
    else {
        QueueElement* temp = new QueueElement();
        temp->setData(x);
        temp->setNext(back->getNext());
        back->setNext(temp);
        back = temp;
    }
    size++;
}
int MyQueue::pop() {
    int ret;
    if (!isEmpty()) {
        QueueElement* temp = front;
        ret = temp->getData();
        front = temp->getNext();
        if (front == NULL) back = NULL;
        delete temp;
        size--;
    }
    else {
        ret = -1;
    }

    return ret;
}
int MyQueue::getSize() {
    return size;
}
bool MyQueue::isEmpty() {
    if (front == NULL) return true;
    return false;
}

class Console {
    string cmd;
    int n;
    int input;
    MyQueue queue;
public:
    void run();
};
void Console::run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd.compare("push") == 0) {
            cin >> input;
            queue.push(input);
        }
        else if (cmd.compare("pop") == 0) {
            cout << queue.pop() << '\n';
        }
        else if (cmd.compare("size") == 0) {
            cout << queue.getSize() << '\n';
        }
        else if (cmd.compare("empty") == 0) {
            queue.isEmpty() ? cout << 1 : cout << 0;
            cout << '\n';
        }
        else if (cmd.compare("front") == 0) {
            cout << queue.getFront() << '\n';
        }
        else if (cmd.compare("back") == 0) {
            cout << queue.getBack() << '\n';
        }
        else { }
    }
}

int main() {
    //출력 속도 상승
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Console console;
    console.run();
    return 0;
}