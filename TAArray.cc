#include "TAArray.h"
#include "TextArea.h"
#include <iostream>
#include <string>

TAArray::TAArray(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new TextArea*[capacity];
}

TAArray::TAArray() {
    this->capacity = 10;
    this->size = 0;
    this->arr = new TextArea*[capacity];
}

TAArray::~TAArray() {
    delete[] arr;
}

bool TAArray::add(TextArea* ta) {
    if (size >= capacity) {
        return false;
    }
    arr[size++] = ta;
    return true;
}

bool TAArray::add(TextArea* ta, int index) {
    if (index < 0 || index >= capacity) {
        return false;
    }
    for (int i = size; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = ta;
    size++;
    return true;
}

TextArea* TAArray::get(int index) const {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    return nullptr;
}

TextArea* TAArray::get(const std::string& id) const {
    for (int i = 0; i < size; ++i) {
        if (arr[i]->getID() == id) {
            return arr[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(const std::string& id) {
    for (int i = 0; i < size; ++i) {
        if (arr[i]->getID() == id) {
            TextArea* removed = arr[i];
            for (int j = i; j < size - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            size--;
            return removed;
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(int index) {
    if (index >= 0 && index < size) {
        TextArea* removed = arr[index];
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
        return removed;
    }
    return nullptr;
}

int TAArray::getSize() const {
    return size;
}
