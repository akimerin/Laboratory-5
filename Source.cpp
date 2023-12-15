#include <iostream> //������ �,�

// ��������� ��� ���� ������������ ������
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// ������� ��� ������ ������
template <typename T>
void printList(Node<T>* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// ������� ��� ������� ���� ������������� �������
template <typename T>
Node<T>* mergeSortedLists(Node<T>* list1, Node<T>* list2) {
    Node<T>* result = nullptr;
    Node<T>* tail = nullptr;

    while (list1 && list2) {
        if (list1->data <= list2->data) {
            // ���� ������� ������� �� list1 ������ ��� ����� �������� �� list2
            if (!result) {
                // ���� ��� ������ ������� � �������������� ������, �������������� result � tail
                result = list1;
                tail = list1;
            }
            else {
                // ����� ��������� ������� �� list1 � ����� ��������������� ������ � ��������� tail
                tail->next = list1;
                tail = list1;
            }
            // ��������� � ���������� �������� � list1
            list1 = list1->next;
        }
        else {
            // ����������� ��������, ���� ������� ������� �� list2 ������ �������� �� list1
            if (!result) {
                result = list2;
                tail = list2;
            }
            else {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    // ��������� ���������� �������� �� list1 ��� list2 (���� ��� ����)
    if (list1)
        tail->next = list1;
    else if (list2)
        tail->next = list2;

    return result;
}

// ����� ��� ���������� ����� �� ����������� ������
template <typename T>
class Stack {
private:
    Node<T>* top; // ��������� �� ������� �����

public:
    Stack() : top(nullptr) {}

    // �������� �� ������� �����
    bool isEmpty() const {
        return top == nullptr;
    }

    // ���������� �������� � ����
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    // �������� �������� �� �����
    void pop() {
        if (!isEmpty()) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // ��������� �������� �������� �������� �����
    T peek() const {
        if (!isEmpty()) {
            return top->data;
        }
        else {
            throw std::out_of_range("Stack is empty");
        }
    }
};

int main() {
    // ������ ������������� ������� ���� ������������� �������
    Node<int>* list1 = new Node<int>(1);
    list1->next = new Node<int>(3);
    list1->next->next = new Node<int>(5);

    Node<int>* list2 = new Node<int>(2);
    list2->next = new Node<int>(4);
    list2->next->next = new Node<int>(6);

    std::cout << "List 1: ";
    printList(list1);

    std::cout << "List 2: ";
    printList(list2);

    Node<int>* mergedList = mergeSortedLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    // ������ ������������� ����� �� ����������� ������
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top of the stack: " << stack.peek() << std::endl;

    stack.pop();
    std::cout << "Top of the stack after pop: " << stack.peek() << std::endl;

    return 0;
}
