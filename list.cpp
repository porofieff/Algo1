template <typename T>
struct Node
{
    T value;
    Node* next;
    Node* prev;

    Node(){};

    Node (Node* new_next, Node* new_prev, T new_value)
    {
        next = new_next; prev = new_prev; value = new_value;
    }
};

template <typename T>
class List
{
    Node<T>* head;
    Node<T>* tail;

    Node<T>* get(int pos)
    {
        if (pos <= size()/2)
        {
            Node<T>* curr = head;
            for (int i = 0; i < pos-1; i++)
            {
                curr = curr->next;
            }
            return curr;
        }
        Node<T>* curr = tail;
        for (int i = size(); i > pos; i--)
            curr = curr->prev;
        return curr;
    }

    public:
        List()
        {
            head = nullptr; tail = nullptr;
        }

        bool is_empty()
        {
            if (head) return false; return true;
        }

        void push_front(T new_val)
        {
            if(!head)
            {
                head = new Node<T>;
                head->next = nullptr;
                head->prev = nullptr;
                tail = head;
                head->value = new_val;
                return;
            }
            Node<T>* new_head = new Node<T>;
            new_head->next = head;
            head->prev = new_head;
            new_head->prev = nullptr;
            head = new_head;
            new_head->value = new_val;
        }

        void push_back(T new_val)
        {
            if(!head)
            {
            head = new Node<T>;
            head->next = nullptr;
            head->prev = nullptr;
            tail = head;
            head->value = new_val;
            return;
            }
            Node<T>* new_tail = new Node<T>;
            new_tail->prev = tail;
            tail->next = new_tail;
            new_tail->next = nullptr;
            tail = new_tail;
            new_tail->value = new_val;
        }

        Node<T>* front()
        {
            return head;
        }

        Node<T>* back()
        {
            return tail;
        }

        int size()
        {
            Node<T>* curr = head;
            if (curr == nullptr)
                return 0;
            int counter = 1;
            while(curr != tail)
            {
                counter++;
                curr = curr->next;
            }
            return counter;
        }

        T get_val(int pos)
        {
            Node<T>* curr = get(pos);
            return curr->value;
        }

        void remove(int pos)
        {
            Node<T>* curr = get(pos);
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
};
