#pragma once

#include <iostream>
#include "sorted_table.h"
#include "array_hash_table.h"
#include "tpolynom.h"

class Tables {
private:
  ScanTable<std::string, TPolynom > scanTable;
  SortedTable<std::string, TPolynom> sortedTable;
  StringHashTable<TPolynom> arrayHashTable;

  void poly_ops();
  int choose_table();
  void remove(const std::string& str);
  void remove_one(const std::string& str);
  void add(const std::string& str);
  void add_one(const std::string& str);
  TabRecord<std::string, TPolynom>* find(const std::string& str);
public:
  Tables() : scanTable(10), sortedTable(10), arrayHashTable(10,1) {}
  void menu();
};