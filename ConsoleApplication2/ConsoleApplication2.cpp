#include <iostream>
using namespace std;

template <typename T>
class Queue 
{
private:
    
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head; 
    Node* tail; 
    int count; 

public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    ~Queue() {
        while (!empty()) 
        {
            pop();
        }
    }

    void push(T val) 
    {
        Node* newNode = new Node(val);
        if (empty()) {
            head = tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    void pop()
    {
        if (empty()) return;

        Node* temp = head;
        head = head->next;

        if (head != nullptr) 
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }

        delete temp;
        count--;
    }

    T front() const 
    {
        if (empty()) 
        {
            throw std::out_of_range("Черга порожня!");
        }
        return head->data;
    }

    bool empty() const
    {
        return head == nullptr;
    }

    int size() const 
    {
        return count;
    }
};

int main() 
{
    Queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Перший елемент: " << q.front() << std::endl;
    std::cout << "Розмір черги: " << q.size() << std::endl;    

    q.pop(); 
    std::cout << "Після pop новий перший: " << q.front() << std::endl;

    return 0;
}