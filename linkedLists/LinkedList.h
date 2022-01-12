namespace LL {
    struct Node {
        int value;
        Node * next;
    };
}

/**
 * Linked list with front guard
 */
class LinkedList {
private:
    LL::Node * head;
    int _size;
public:
    LinkedList() {
        head = new LL::Node;
        head->value = 0;
        head->next = nullptr;
        _size = 0;
    }

    /**
     * Returns the size of the list
     * @return Size
     */
    int size() {
        return _size;
    }

    /**
     * Is the list empty?
     * @return Is it empty:
     */
    bool empty() {
        return !_size;
    }

    /**
     * Pushes an value at the front
     * @param value Value
     */
    void push_front(int value) {
        LL::Node * node = new LL::Node;
        node->value = value;
        node->next = head->next;
        head->next = node;
        _size++;
    }

    /**
     * Pops a value from the front
     * @return Value
     */
    int pop_front() {
        if (_size > 0) {
            LL::Node * temp = head->next;
            int retVal = temp->value;
            head->next = head->next->next;
            delete temp;
            _size--;
            return retVal;
        } else return 0;
    }

    /**
     * Pushes a value at the end
     * @param value Value
     */
    void push_back(int value) {
        LL::Node * temp = head;
        while (temp->next != nullptr) temp = temp->next;
        LL::Node * node = new LL::Node;
        node->value = value;
        node->next = nullptr;
        temp->next = node;
        _size++;
    }

    /**
     * Pops a value from the back of the list
     * @return Value
     */
    int pop_back() {
        if (_size > 0) {
            LL::Node * temp = head;
            while (temp->next->next != nullptr) temp = temp->next;
            int retVal = temp->next->value;
            delete temp->next;
            temp->next = nullptr;
            _size--;
            return retVal;
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
        if (_size > 0) {
            LL::Node * temp = head;
            while (temp->next != nullptr) temp = temp->next;
            return temp->value;
        } else return 0;
    }

    /**
     * Inserts a value at the given index
     * @param value Value
     * @param index Index
     */
    void insert(int value, int index) {
        if (index > _size) return;
        else {
            LL::Node * temp = head;
            while (index-- > 0) temp = temp->next;
            LL::Node * node = new LL::Node;
            node->next = temp->next;
            node->value = value;
            temp->next = node;
            _size++;
        }
    }

    /**
     * Erases a value at a given index
     * @param index Index
     */
    void erase(int index) {
        if (index >= _size) return;
        else {
            LL::Node * temp = head;
            while (index-- > 0) temp = temp->next;
            LL::Node * tmp = temp->next;
            temp->next = tmp->next;
            delete tmp;
            _size--;
        }
    }

    /**
     * Returns the value at the given index
     * @param index Index
     * @return Value
     */
    int at(int index) {
        if (index >= _size) return 0;
        else {
            LL::Node * temp = head->next;
            while (index-- > 0) temp = temp->next;
            return temp->value;
        }
    }

    /**
     * Returns an element from n-places the back
     * @param n N-places
     * @return Value
     */
    int value_n_from_back(int n) {
        if (n >= _size) return 0;
        else {
            n = _size - n - 1;
            return at(n);
        }
    }

    /**
     * Reverses the order of the list
     */
    void reverse() {
        if (_size > 1) {
            LL::Node * left = head->next;
            LL::Node * mid = head->next->next;
            LL::Node * right = head->next->next->next;
            head->next = nullptr;
            left->next = nullptr;
            while (right != nullptr) {
                mid->next = left;
                left = mid;
                mid = right;
                right = right->next;
            }
            mid->next = left;
            head->next = mid;
        }
    }

    /**
     * Removes the first found equal value from the list
     * @param value Value
     */
    void remove_value(int value) {
        if (_size > 0) {
            int c = 0;
            LL::Node * temp = head->next;
            while (temp != nullptr) {
                if (temp->value == value) {
                    erase(c);
                    break;
                }
                c++;
                temp = temp->next;
            }
        }
    }
};