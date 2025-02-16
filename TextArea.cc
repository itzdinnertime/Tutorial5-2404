#include "defs.h"
#include "RGB.h"
#include "TextArea.h"
#include <X11/Xlib.h>
#include <string>
#include <iostream>

// Constructor that takes individual x, y, width, height, id, text, fill, and border
TextArea::TextArea(int x, int y, int width, int height, const std::string& id, const std::string& label, RGB fill, RGB border)
    : dimensions({x, y, width, height}),  
      id(id),       
      text(label),  
      fill(fill),   
      border(border)
{}

TextArea::TextArea(const Rectangle& dimensions, const std::string& id, const std::string& text,
    RGB fill, RGB border)
    : dimensions(dimensions),  
      id(id),       
      text(text),  
      fill(fill),   
      border(border)
{}

// No-argument constructor with default values
TextArea::TextArea()
    : dimensions{0, 0, 100, 50}, text(""), id("default"), fill(RGB()), border(RGB(0, 0, 0)) {}

// Copy constructor, setting text to "DUPLICATE" instead of copying the original text
TextArea::TextArea(const TextArea &other)
    : dimensions(other.dimensions),
      id(other.id),
      text("DUPLICATE"),  // Set the new text to "DUPLICATE"
      fill(other.fill),
      border(other.border)
{}

TextArea::TextArea(int x, int y, int width, int height, const std::string& id, const std::string& text):
    dimensions({x, y, width, height}), id(id), text(text)
{}

TextArea::TextArea(Rectangle dimensions, std::string id, std::string text){
    this->dimensions = dimensions;
    this->id = id;
    this->text = text;
    this->fill = RGB().WHITE();
    this->border = RGB().BLACK();
}

// Getter methods
int TextArea::getX() {
    return dimensions.x;
}

int TextArea::getY() {
    return dimensions.y;
}

int TextArea::getWidth() {
    return dimensions.width;
}

int TextArea::getHeight() {
    return dimensions.height;
}

std::string TextArea::getID() {
    return id;
}

std::string TextArea::getLabel() {
    return text;
}

RGB TextArea::getFill() {
    return fill;
}

RGB TextArea::getBorder() {
    return border;
}

// Setter methods
void TextArea::setX(int x) {
    dimensions.x = x;
}

void TextArea::setY(int y) {
    dimensions.y = y;
}

void TextArea::setWidth(int width) {
    dimensions.width = width;
}

void TextArea::setHeight(int height) {
    dimensions.height = height;
}

void TextArea::setFill(RGB fill){
    fill = fill;
}

void TextArea::setBorder(RGB border){
    border = border;
}

// Member function to draw the TextArea
void TextArea::draw(Display *display, Window win, GC gc, int x, int y) {
    // Fill rectangle (background)
    XSetForeground(display, gc, WhitePixel(display, 0)); // Set fill color (hardcoded)
    XFillRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);

    // Draw border
    XSetForeground(display, gc, BlackPixel(display, 0)); // Set border color (hardcoded)
    XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);

    // Draw text (simple version, no wrapping)
    int text_x = x + 5;
    int text_y = y + 15;
    XDrawString(display, win, gc, text_x, text_y, text.c_str(), text.length());
}

// Function to check if this TextArea overlaps with another TextArea
bool TextArea::overlaps(const TextArea& ta) const{
    return dimensions.overlaps(ta.dimensions);
}

// Print out the TextArea details to the console
void TextArea::print() const {
    std::cout << "TextArea id:\n"
              << "  " << id << "\n"
              << "Preferred location: " << dimensions.x << ", " << dimensions.y << "\n"
              << "Size:\n"
              << "  " << dimensions.width << ", " << dimensions.height << "\n"
              << "Text:\n"
              << "  " << text << "\n";
}
