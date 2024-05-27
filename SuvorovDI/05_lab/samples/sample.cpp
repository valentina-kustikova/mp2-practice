//#include <QApplication>
#include <iostream>
#include "table.h"
#include "array_hash_table.h"

int main(int argc, char* argv[]) {
  try {
    ArrayHashTable<std::string, int> s_table(10, 3);
    s_table.Insert("first", new int(43));
    s_table.Insert("second", new int(84));
    s_table.Insert("third", new int(9));
    s_table.Remove("second");
    std::cout << (s_table.Find("second") == nullptr);
  } catch (const std::exception ex) {
    std::cerr << ex.what() << "\n";
  }
	// s_table.Find("second") == nullptr;

  return 0;
}