#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node* next;
    Node* prev;
    Node()
    {
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(T value) :Node()
    {
        this->value = value;
    }
    T GetValue()
    {
        return this->value;
    }
};

template <typename T>
class Queue
{
private:
    Node<T>* head;
    Node<T>* tail;
    uint32_t length;
public:
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    bool Enqueue(T elem)
    {
        Node<T>* node_elem = new Node<T>(elem);
        if (length == 0)
        {
            head = tail = node_elem;
        }
        else
        {
            tail->next = node_elem;
            node_elem->prev = tail;
            tail = node_elem;
        }
        length++;
        return true;
    }

    bool Dequeue()
    {
        Node<T>* node_elem = new Node<T>();
        node_elem = head;
        if (node_elem->next == nullptr)
        {
            tail = head = nullptr;
        }
        else
        {
            head = node_elem->next;
            head->prev = nullptr;
        }
        length--;
        delete node_elem;
        return true;
    }

    uint32_t size()
    {
        return length;
    }


    bool IsEmpty()
    {
        return (length == 0) ? true : false;
    }

    bool IsFull()
    {
        return (length != 0) ? true : false;
    }

    T Back()
    {
        if (length == 0)
        {
            return (T)NULL;
        }
        else
        {
            return tail->GetValue();
        }
    }

    T Front()
    {
        if (length == 0)
        {
            return (T)NULL;
        }
        else
        {
            return head->GetValue();
        }
    }

    void Show()
    {
        Node<T>* node_elem = new Node<T>();
        if (length == 0)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Queue -> ";
            node_elem = head;
            do
            {
                cout << node_elem->GetValue() << '\t';
                node_elem = node_elem->next;
            } while (node_elem != nullptr);
            cout << endl;
        }
    }

    bool Clear()
    {
        do
        {
            Dequeue();
        } while (tail != nullptr);
        return true;
    }
};

int main()
{
    srand(time(0));
    Queue <int> queue;
    for (size_t i = 0; i < 5; i++)
    {
        cout << "Iteration #" << i << endl;
        queue.Enqueue(rand() % 10);
        cout << "Front = " << queue.Front() << endl;
        cout << "Back = " << queue.Back() << endl;
        cout << endl << endl;
    }
    queue.Show();
    queue.Dequeue();
    cout << "Front = " << queue.Front() << endl;
    queue.Dequeue();
    cout << "Front = " << queue.Front() << endl;
    queue.Show();
    if (queue.IsEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }
    queue.Clear();
    if (queue.IsEmpty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }



    return 0;
}
