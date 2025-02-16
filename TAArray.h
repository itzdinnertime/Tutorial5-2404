#ifndef TAARRAY_H
#define TAARRAY_H

#include "defs.h"
#include "TextArea.h"
#include <string>

class TAArray {
private:
    TextArea** arr;
    int size;
    int capacity;

public:
    TAArray(int capacity);
    TAArray(); 
    ~TAArray();
    bool add(TextArea* ta);  
    bool add(TextArea* ta, int index); 
    TextArea* get(int index) const;
    TextArea* get(const std::string& id) const;
    TextArea* remove(const std::string& id);
    TextArea* remove(int index);
    int getSize() const;
};

#endif
