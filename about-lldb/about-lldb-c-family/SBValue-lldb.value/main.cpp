#include <iostream>

struct A {
  int x{100};
  bool y{false};
  int z{101};
};

int main(int argc, const char * argv[]) {
  A* a = new A{};
  /*
   SBValue

   (lldb) script a = lldb.frame.EvaluateExpression('a')
   (lldb) script print(a.type.name)
   A *
   (lldb) script print(a.size)
   8
   (lldb) script print(a.deref.type.name)
   A
   (lldb) script print(a.deref.size)
   12
   (lldb) script print(a.data)
   30 80 00 00 00 60 00 00                          0....`..
   (lldb) expression a
   (A *) $1 = 0x0000600000008030
   (lldb) script print(len(a.children))
   3
   (lldb) script print(a.children[0])
   (int) x = 100
   (lldb) script print(a.GetValueForExpressionPath('.z'))
   (int) z = 101

   lldb.value
   (lldb) script a_value = lldb.value(a)
   (lldb) script print(a_value.x)
   (int) x = 100

   SBExpressionOptions
   script options = lldb.SBExpressionOptions()
   script options.SetLanguage(lldb.eLanguageTypeSwift)
   script options.SetCoerceResultToId() // po
   script b = lldb.target.EvaluateExpression('expression', options)

   expression -lswift -O -- expression
   */
  std::cout << "C++" << std::endl;
}
