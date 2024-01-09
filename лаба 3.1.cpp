#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNode(Node*& head, int data);
void removeEven(Node*& head);
void Print_List(Node* head);

int main()
{
    setlocale(0, "");
    Node* head = NULL;
    int n, num;

    cout << "Введите количество элементов в списке: ";
    cin >> n;
    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        addNode(head, num);
    }

    cout << "Исходный список: ";
    Print_List(head);
    cout << "Удаление из списка всех элементов с четным информационным полем:\n";
    removeEven(head);
}

void addNode(Node*& head, int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)  // Поиск последнего элемента в списке
        {
            temp = temp->next;
        }
        temp->next = newNode;       // Добавление нового элемента в конец списка
    }
}

void removeEven(Node*& head) {
    while (head != NULL && head->data % 2 == 0) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == NULL) { // Весь список состоял из четных элементов
        cout << "Весь список состоял из четных элементов" << endl;
        return;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL) 
    {
        if (curr->data % 2 == 0)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    cout << "Список после удаления четных элементов: ";
    Print_List(head);
}
void Print_List(Node* head) 
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}