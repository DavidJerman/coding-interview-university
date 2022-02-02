class Vector {

private:
    int * arr;
    int _capacity;
    int _size;

public:
    /**
     * Vector constructor
     *
     * @param size Initial size of the array
     */
    Vector(int size = 16) {
        _capacity = 16;
        while (_capacity < size) _capacity *= 2;
        _size = 0;
        arr = new int[_capacity];
    }

    /**
     * Returns the size of the vector
     *
     * @return Size
     */
    int size() {
        return _size;
    }

    /**
     * Returns the capacity of the vector
     *
     * @return Capacity
     */
    int capacity() {
        return _capacity;
    }

    /**
     * Returns a bool value, whether the array is empty
     *
     * @return Is vector empty
     */
    bool isEmpty() {
        return _size == 0;
    }

    /**
     * Returns the element at a specified index in the vector,
     * if it is out of range, returns -1
     *
     * @param index Index
     * @return Element
     */
    int at(int index) {
        if (index < 0 || index >= _size) return -1; // Error - index out of range
        else return arr[index];
    }

    /**
     * Pushes an element at the end of the vector
     *
     * @param item Element
     */
    void push(int item) {
        if (_size == _capacity) resize(true);
        arr[_size] = item;
        _size++;
    }

    /**
     * Returns an element at the end of the vector and removes it
     *
     * @return Element
     */
    int pop() {
        if (isEmpty()) return -1; // Error - array is empty
        else {
            _size--;
            if (_size <= _capacity / 4) resize(false);
            return arr[_size];
        }
    }

    /**
     * Inserts an item into the vector at given index
     *
     * @param index Index
     * @param item Item
     */
    void insert(int index, int item) {
        if (index >= _size || index < 0) return;
        else {
            if (_size + 1 == _capacity) resize(true);
            for (int i = _size; i > index; i--) arr[i] = arr[i - 1];
            arr[index] = item;
            _size++;
        }
    }

    /**
     * Prepends an item in the vector
     *
     * @param item Item
     */
    void prepend(int item) {
        insert(0, item);
    }

    /**
     * Deletes an item from the vector at a specified index
     *
     * @param item Item
     */
    void _delete(int index) {
        if (index >= _size || index < 0) return;
        else {
            for (int i = index; i < _size; i++) arr[i] = arr[i + 1];
            pop();
        }
    }

    /**
     * Find the index of an item
     *
     * @param item Item
     * @return Index
     */
    int find(int item) {
        for (int i = 0; i < _size; i++)
            if (arr[i] == item) return i;
        return -1;
    }

    /**
     * Removes item(s) from the vector
     *
     * @param item Item
     */
    void remove(int item) {
        for (int i = 0; i < _size; i++)
            if (arr[i] == item) _delete(i);
    }

private:
    /**
     * Resizes the array
     *
     * @param expand If set to true, doubles the array size, else halves it
     */
    void resize(bool expand) {
        if (!expand && _capacity <= 16) return; // Vector capacity stays at min. 16
        int * temp;
        if (expand) _capacity *= 2;
        else _capacity /= 2;
        temp = new int[_capacity];
        for (int i = 0; i < _size; i++) temp[i] = arr[i];
        delete [] arr;
        arr = temp;
    }
};
