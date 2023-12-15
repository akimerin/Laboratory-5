#include <iostream> //пункты а,б

// Структура для узла односвязного списка
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// Функция для печати списка
template <typename T>
void printList(Node<T>* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Функция для слияния двух упорядоченных списков
template <typename T>
Node<T>* mergeSortedLists(Node<T>* list1, Node<T>* list2) {
    Node<T>* result = nullptr;
    Node<T>* tail = nullptr;

    while (list1 && list2) {
        if (list1->data <= list2->data) {
            // Если текущий элемент из list1 меньше или равен элементу из list2
            if (!result) {
                // Если это первый элемент в результирующем списке, инициализируем result и tail
                result = list1;
                tail = list1;
            }
            else {
                // Иначе добавляем элемент из list1 в конец результирующего списка и обновляем tail
                tail->next = list1;
                tail = list1;
            }
            // Переходим к следующему элементу в list1
            list1 = list1->next;
        }
        else {
            // Аналогичные действия, если текущий элемент из list2 меньше элемента из list1
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

    // Добавляем оставшиеся элементы из list1 или list2 (если они есть)
    if (list1)
        tail->next = list1;
    else if (list2)
        tail->next = list2;

    return result;
}

// Класс для реализации стека на односвязном списке
template <typename T>
class Stack {
private:
    Node<T>* top; // Указатель на вершину стека

public:
    Stack() : top(nullptr) {}

    // Проверка на пустоту стека
    bool isEmpty() const {
        return top == nullptr;
    }

    // Добавление элемента в стек
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    // Удаление элемента из стека
    void pop() {
        if (!isEmpty()) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Получение значения верхнего элемента стека
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
    // Пример использования слияния двух упорядоченных списков
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

    // Пример использования стека на односвязном списке
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top of the stack: " << stack.peek() << std::endl;

    stack.pop();
    std::cout << "Top of the stack after pop: " << stack.peek() << std::endl;

    return 0;
}
