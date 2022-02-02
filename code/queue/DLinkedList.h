namespace DLL {
    struct Node {
        int value;
        Node * next;
        Node * prev;
    };
}

class DLinkedList {
private:
    DLL::Node * head;
    DLL::Node * tail;
    int _size;
public:
    DLinkedList() {
        head = new DLL::Node;
        tail = new DLL::Node;
        head->value = 0;
        head->next = tail;
        head->prev = nullptr;
        tail->value = 0;
        tail->prev = head;
        tail->next = nullptr;
        _size = 0;
    }

    /**
     * Returns the size of the list
     * @return
     */
    int size() {
        return _size;
    }

    /**
     * Is the list empty
     * @return Is it empty
     */
    bool empty() {
        return !_size;
    }

    /**
     * Pushes a value at the front of the list
     * @param value Value
     */
    void push_front(int value) {
        DLL::Node * node = new DLL::Node;
        node->value = value;
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        _size++;
    }

    /**
     * Returns the value at the front of the list
     * @return Value
     */
    int pop_front() {
        if (_size > 0) {
            int temp = head->next->value;
            head->next = head->next->next;
            delete head->next->prev;
            head->next->prev = head;
            _size--;
            return temp;
        } else return 0;
    }

    /**
     * Pushes a value at the back of the list
     * @param value Value
     */
    void push_back(int value) {
        DLL::Node * node = new DLL::Node;
        node->value = value;
        node->next = tail;
        node->prev = tail->prev;
        node->prev->next = node;
        tail->prev = node;
        _size++;
    }

    /**
     * Pops the last value from the list
     * @return Value
     */
    int pop_back() {
        if (_size > 0) {
            int temp = tail->prev->value;
            tail->prev = tail->prev->prev;
            delete tail->prev->next;
            tail->prev->next = tail;
            _size--;
            return temp;
        } else return 0;
    }

    /**
     * Gets the first value in the list
     * @return Value
     */
    int front() {
        if (_size > 0) return head->next->value;
        else return 0;
    }

    /**
     * Gets the last value in the list
     * @return Value
     */
    int back() {
        if (_size > 0) return tail->prev->value;
        else return 0;
    }

    /**
     * Inserts a value at the given index
     * @param value Value
     * @param index Index
     */
    void insert(int value, int index) {
        if (index > _size) return;
        else {
            DLL::Node * node = new DLL::Node;
            node->value = value;
            DLL::Node * temp = head;
            while (index-- > 0) temp = temp->next;
            node->next = temp->next;
            node->prev = temp;
            temp->next->prev = node;
            temp->next = node;
            _size++;
        }
    }
};