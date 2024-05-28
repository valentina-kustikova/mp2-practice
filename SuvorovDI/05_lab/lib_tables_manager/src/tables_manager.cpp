#include <iostream>
#include "tables_manager.h"

int Tables::choose_table() {
    int choice;
    std::cout << "TABLES" << "\n";
    std::cout << "1) Scan Table" << "\n";
    std::cout << "2) Sorted Table" << "\n";
    std::cout << "3) Array Hash Table" << "\n";
    std::cout << "0) CANCEL" << "\n";
    std::cout << "Enter:";
    if (!(std::cin >> choice)) {
      std::cout << "Invalid input." << "\n";
      return 0;
    }

    return choice;
}

void Tables::add_one(const std::string& str) {
  TPolynom* polynom = new TPolynom(str);
  switch (choose_table()) {
  case 0: return;
  case 1: {
    scanTable.Insert(str, polynom);
    break;
  }
  case 2: {
    sortedTable.Insert(str, polynom);
    break;
  }
  case 3: {
    arrayHashTable.Insert(str, polynom);
    break;
  }
  }
}

void Tables::add(const std::string& str) {
  int choice;
  std::cout << "1. Add to one table" << "\n";
  std::cout << "2. Add to all tables" << "\n";
  std::cout << "0. CANCEL" << "\n";
  std::cout << "Enter:";
  std::cin >> choice;
  switch (choice) {
  case 0: return;
  case 1: { add_one(str); break; }
  case 2: {
    TPolynom* polynom = new TPolynom(str);
    scanTable.Insert(str, polynom);
    sortedTable.Insert(str, polynom);
    arrayHashTable.Insert(str, polynom);
    break; 
  }
  }
}

void Tables::remove_one(const std::string& str) {
  switch (choose_table()) {
  case 0:return;
  case 1: {
    scanTable.Remove(str);
    break;
  }
  case 2: {
    sortedTable.Remove(str);
    break;
  }
  case 3: {
    arrayHashTable.Remove(str);
    break;
  }
  }
}

void Tables::remove(const std::string& str) {
  int choice;
  std::cout << "1. Remove from one table" << "\n";
  std::cout << "2. Remove from all tables" << "\n";
  std::cout << "0. CANCEL" << "\n";
  std::cout << "Enter:";
  std::cin >> choice;
  switch (choice) {
  case 0:return;
  case 1: { remove_one(str); break; }
  case 2: {
    scanTable.Remove(str);
    sortedTable.Remove(str);
    arrayHashTable.Remove(str);
    break;
  }
  }
}

void Tables::poly_ops() {
  std::string pol_name1, pol_name2;
  std::cout << "Enter first polynomial: ";
  std::cin >> pol_name1;

  TabRecord<std::string, TPolynom>* rec1 = find(pol_name1);
  if (rec1 != nullptr) {
    std::cout << "Enter second polynomial: ";
    std::cin >> pol_name2;

    TabRecord<std::string, TPolynom>* rec2 = find(pol_name2);
    if (rec2 != nullptr) {
      TPolynom p1 = *rec1->GetData();
      TPolynom p2 = *rec2->GetData();
      TPolynom p3;

      char choice;
      std::cout << "1) -> +" << "\n";
      std::cout << "2) -> -" << "\n";
      std::cout << "3) -> *" << "\n";
      std::cout << "Enter:";
      std::cin >> choice;
      switch(choice){
      case 0:return;
      case '+': { p3 = p1 + p2; break; }
      case '-': { p3 = p1 - p2; break; }
      case '*': { p3 = p1 * p2; break; }
      }
      std::cout << p3;
      add(p3.ToString());
    }
  }
}

TabRecord<std::string, TPolynom>* Tables::find(const std::string& str) {
  TabRecord<std::string, TPolynom>* record = nullptr;

  if ((record = scanTable.Find(str)) != nullptr) {
    return record;
  }
  if ((record = sortedTable.Find(str)) != nullptr) {
    return record;
  }
  if ((record = arrayHashTable.Find(str)) != nullptr) {
    return record;
  }

  return nullptr;
}

void Tables::menu() {
	int choice;
  do {
    std::cout << "Menu:" << "\n";
    std::cout << "1. Insert" << "\n";
    std::cout << "2. Remove" << "\n";
    std::cout << "3. See one table" << "\n";
    std::cout << "4. See all tables" << "\n";
    std::cout << "5. Polynoms" << "\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice) {
    case 0: break;
    case 1: { 
      std::cout << "Enter polynom:";
      std::string pol_name;
      std::cin >> pol_name;
      add(pol_name); 
      break; 
    }
    case 2: { 
      std::cout << "Enter polynom:";
      std::string pol_name;
      std::cin >> pol_name;
      remove(pol_name); 
      break; 
    }
    case 3: {
      switch (choose_table()) {
      case 0:return;
      case 1: {
        std::cout << scanTable;
        break;
      }
      case 2: {
        std::cout << sortedTable;
        break;
      }
      case 3: {
        std::cout << arrayHashTable;
        break;
      }
      }
      break;
    }
    case 4: { 
      std::cout << "ScanTable: " << "\n";
      std::cout << scanTable << "\n";
      std::cout << "SortedTable" << "\n";
      std::cout << sortedTable << "\n";
      std::cout << "ArrayHashTable" << "\n";
      std::cout << arrayHashTable << "\n";
      break;
    }
    case 5: { poly_ops(); break; }
    default:
      std::cout << "Invalid choice. Please try again." << "\n";
      break;
    }
  } while (choice != 0);    
}