#include "Algorithms.h"
#include <time.h>

//------------------------------------ Test (classic) -----------------------------------//

void _tCTestMain()
{
  int maxSize = 10;
  int size = 10;
  int* keys = new int[maxSize];
  keys[0] = -1;
  keys[1] =  8;
  keys[2] =  0;
  keys[3] = -4;
  keys[4] = -2;
  keys[5] =  5;
  keys[6] =  4;
  keys[7] =  1;
  keys[8] =  2;
  keys[9] =  7;

  std::cout << "   Keys: " << std::endl;
  std::cout << "[ ";
  for (int i = 0; i < size; i++)
    std::cout << keys[i] << " ";
  std::cout << "]" << std::endl;

  try
  {
    HeapSort::heapSort(size, keys);

    std::cout << std::endl << "   Sorted keys: " << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < size; i++)
      std::cout << keys[i] << " ";
    std::cout << "]" << std::endl << std::endl;
  }
  catch (ExceptionOutOfRange const& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }

  delete[] keys;
}

//---------------------------------- Test (random array) --------------------------------//

void _tRATestMain()
{
  int _min;
  int _max;
  int _size;

  srand((unsigned int)time(0));

  std::cout << "Enter count of elements: ";
  std::cin >> _size;
  while (_size < 0)
  {
    std::cout << std::endl;
    std::cout << "Count of elements must be > 0!" << std::endl;
    std::cout << "Enter count of elements: ";
    std::cin >> _size;
  };

  std::cout << std::endl;
  std::cout << "Enter left border value: ";
  std::cin >> _min;
  std::cout << "Enter right border value: ";
  std::cin >> _max;

  while (_min > _max)
  {
    std::cout << std::endl;
    std::cout << "Left border value must be < right border value!" << std::endl;
    std::cout << "Enter left border value: ";
    std::cin >> _min;
    std::cout << "Enter right border value: ";
    std::cin >> _max;
  };
  
  int* keys = new int[_size];
  for (int i = 0; i < _size; i++)
    keys[i] = (_max - _min + 1) / (double)RAND_MAX * rand() + _min;

  std::cout << std::endl << "   Random keys (array with random elements" 
    << "between left border value = " << _min
    << " and right border value = " << _max << "): " << std::endl;
  std::cout << "[ ";
  for (int i = 0; i < _size; i++)
    std::cout << keys[i] << " ";
  std::cout << "]" << std::endl;

  try
  {
    HeapSort::heapSort(_size, keys);

    std::cout << std::endl << "   Sorted keys: " << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < _size; i++)
      std::cout << keys[i] << " ";
    std::cout << "]" << std::endl << std::endl;
  }
  catch (ExceptionOutOfRange const& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }

  delete[] keys;
}

//----------------------------------- Test (user input) ---------------------------------//

void _tUITestMain()
{
  int _size;

  std::cout << "Enter count of elements: ";
  std::cin >> _size;
  while (_size < 0)
  {
    std::cout << std::endl;
    std::cout << "Count of elements must be > 0!" << std::endl;
    std::cout << "Enter count of elements: ";
    std::cin >> _size;
  };

  int* keys = new int[_size];
  for (int i = 0; i < _size; i++)
  {
    std::cout << "Enter key with index i = " << (i + 1) << " : ";
    std::cin >> keys[i];
  }

  std::cout << std::endl << "   Keys: " << std::endl;
  std::cout << "[ ";
  for (int i = 0; i < _size; i++)
    std::cout << keys[i] << " ";
  std::cout << "]" << std::endl;

  try
  {
    HeapSort::heapSort(_size, keys);

    std::cout << std::endl << "   Sorted keys: " << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < _size; i++)
      std::cout << keys[i] << " ";
    std::cout << "]" << std::endl << std::endl;
  }
  catch (ExceptionOutOfRange const& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }

  delete[] keys;
}

//----------------------------------------- Main ----------------------------------------//

int main()
{
  _tCTestMain();
  std::cout << "//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//";
  std::cout << std::endl << std::endl;

  _tRATestMain();
  std::cout << "//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//";
  std::cout << std::endl << std::endl;

  _tUITestMain();
  std::cout << "//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//";
  std::cout << std::endl << std::endl;

  system("pause");
  return 0;
}