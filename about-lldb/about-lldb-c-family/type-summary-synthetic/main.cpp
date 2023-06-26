#include <iostream>

class Rectangle {
public:
  int height;
  int width;
  int private_field;
  Rectangle(int height, int width) : height(height), width(width) {}
};

class RectanglePointer {
  Rectangle *_pointer;
public:
  RectanglePointer(Rectangle *p): _pointer{p} {};
};

class RectangleBox {
  Rectangle *_pointer;
public:
  RectangleBox(Rectangle *p): _pointer{p} {};
};

int main(int argc, const char * argv[]) {
  Rectangle rectangle{10, 20};
  RectanglePointer rectangle_pointer{&rectangle};
  RectangleBox rectangle_box{&rectangle};
  
  /*
   (lldb) command script import <path>/providers.py
   
   (lldb) type summary add --expand --python-function providers.RectangleSummaryProvider Rectangle
   (lldb) type synthetic add --python-class  providers.RectangleSyntheticChildrenProvider Rectangle
   
   (lldb) type synthetic add --python-class  providers.RectanglePointerSyntheticChildrenProvider RectanglePointer
   (lldb) type synthetic add --python-class  providers.RectangleBoxSyntheticChildrenProvider RectangleBox
   
   frame variable rectangle *rectangle_pointer rectangle_box
   */
  printf("");
}
