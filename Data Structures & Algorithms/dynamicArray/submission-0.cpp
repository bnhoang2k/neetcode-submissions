class DynamicArray {
public:

    int size;
    int* data = nullptr;
    int capacity;

    DynamicArray(int capacity) {
        size = 0;
        this->capacity = capacity;
        data = new int[capacity];
    }

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if ((size + 1) > (capacity)) {
            resize();
        }
        data[size] = n;
        size += 1;
    }

    int popback() {
        int res = data[size - 1];
        size -= 1;
        return res;
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = data[i];
        }
        int* old = data;
        data = newArr;
        delete[] old;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
