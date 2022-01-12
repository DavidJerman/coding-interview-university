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


};