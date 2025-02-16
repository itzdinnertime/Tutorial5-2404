#ifndef TEXTAREA_H 
#define TEXTAREA_H

#include "defs.h"
#include "RGB.h"
#include <string>
#include <iostream>
#include <X11/Xlib.h>

class TextArea {
    private:
        Rectangle dimensions;
        std::string text;
        std::string id;
        RGB fill, border;

    public:
        // Constructors
        TextArea(int x, int y, int width, int height, const std::string& id, const std::string& text,
            RGB fill, RGB border);
        TextArea(const Rectangle& dimensions, const std::string& id, const std::string& text,
                RGB fill, RGB border);
        TextArea();  // No-argument constructor
        TextArea(const TextArea& other);
        TextArea(Rectangle dimensions, std::string id, std::string text);
        TextArea(int x, int y, int width, int height, const std::string& id, const std::string& text);

        // Getter Methods
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        std::string getID();
        std::string getLabel();
        RGB getFill();
        RGB getBorder();

        // Setter Methods
        void setX(int x);
        void setY(int y);
        void setWidth(int width);
        void setHeight(int height);
        void setID(std::string &id);
        void setLabel(std::string &label);
        void setFill(RGB fill);
        void setBorder(RGB border);

        // Member Functions
        void draw(Display *display, Window win, GC gc, int x, int y);
        bool overlaps(const TextArea& ta) const;
        void print() const;  // Make print() const
};

#endif
