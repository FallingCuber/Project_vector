#include <iostream>
using namespace std;
template <typename T>
class vector {
    public:
        vector() :data(nullptr), size(0), capacity(0) {}
        ~vector() {
            if (data != nullptr) {
                delete[] data;
            }
            size = 0;
            capacity = 0;
        }
        T& at(int index) {
            if (index < 0 || index >= size) {
                throw out_of_range("out of range");
            }
            return data[index];
        }
        T& front() {
            if (data == nullptr) {
                throw out_of_range("out of range");
            }
            return data[0];
        }
        T& back() {
            return data[size - 1];
        }
        T& operator [] (int index) {
            return data[index];
        }
        void push_back(const T& value) {
            if (size < capacity) {
                data[size] = value;
                size++;
                return;
            }
            if (capacity == 0) {
                capacity = 1;
            }
            else {
                capacity *= 2;
            }
            resize(capacity);
            data[size] = value;
            size++;
        }
        void pop_back() {
            if (size > 0) {
                size--;
            }
        }
        class Iterator {
            private:
                T* ptr;
            public:
                Iterator(T* p) : ptr(p) {}
                T& operator*() {
                    return *ptr;
                }
                Iterator& operator++() {
                    ++ptr;
                    return *this;
                }
                bool operator!=(const Iterator& other) const {
                    return ptr != other.ptr;
                }
        };
        Iterator begin() {
            return Iterator(data);
        }
        Iterator end() {
            return Iterator(data + size);
        }
    private:
        T* data;
        int size;
        int capacity;
        void resize(size_t new_capacity) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
};
int main() {

    return 0;
}
