class ArrayQueue {
private:
    int _head;
    int _tail;
    int _size;
    int * arr;
    int getIndex(int index) {
        while (index > _size) index -= (_size + 1);
        return index;
    }
public:
    ArrayQueue(int size = 4) {
        _head = 0;
        _tail = 0;
        arr = new int [size];
        _size = size - 1;
    }

    void enqueue(int value) {
        if (!full()) {
            arr[_tail] = value;
            _tail = getIndex(_tail + 1);
        }
    }

    bool full() {
        return getIndex(_tail + 1) == _head;
    }

    bool empty() {
        return _head == _tail;
    }

    int dequeue() {
        if (!empty()) {
            int retVal = arr[_head];
            _head = getIndex(_head + 1);
            return retVal;
        } else return -1;
    }
};