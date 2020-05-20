#include "MyExceptions.h"

MyException::MyException()
{
  str_what = 0;
  line = 0;
  file = 0;
}

MyException::MyException(int _line, const char *_file)
{
  str_what = 0;
  line = _line;
  file = _file;
}

MyException::MyException(const MyException& _exception)
  : str_what(_exception.what()),
  line(_exception.errorLine()),
  file(_exception.errorFile()) {}

MyException::MyException(const char* message, int _line, const char *_file)
  : str_what(message),
  line(_line),
  file(_file) {}

MyException::~MyException()
{
  line = -1;
}

ExceptionOutOfRange::ExceptionOutOfRange()
{
  str_what = "Index out of bounds!";
  line = -1;
  file = 0;
}

ExceptionOutOfRange::ExceptionOutOfRange(const ExceptionOutOfRange& _exception)
{
  str_what = _exception.what();
  line = _exception.errorLine();
  file = _exception.errorFile();
}

ExceptionOutOfRange::ExceptionOutOfRange(int _line, const char* _file)
{
  str_what = "Index out of bounds!"; 
  line = _line; 
  file = _file;
}

ExceptionOutOfRange::~ExceptionOutOfRange()
{
  line = -1;
}

ExceptionDisconnectedGraph::ExceptionDisconnectedGraph()
{
  str_what = "Graph is disconnected!";
  line = -1;
  file = 0;
}

ExceptionDisconnectedGraph::ExceptionDisconnectedGraph(const ExceptionDisconnectedGraph& _exception)
{
  str_what = _exception.what();
  line = _exception.errorLine();
  file = _exception.errorFile();
}

ExceptionDisconnectedGraph::ExceptionDisconnectedGraph(int _line, const char* _file)
{
  str_what = "Graph is disconnected!";
  line = _line;
  file = _file;
}

ExceptionDisconnectedGraph::~ExceptionDisconnectedGraph()
{
  line = -1;
}

ExceptionGraphWithoutVertices::ExceptionGraphWithoutVertices()
{
  str_what = "The graph has no vertices!";
  line = -1;
  file = 0;
}

ExceptionGraphWithoutVertices::ExceptionGraphWithoutVertices(const ExceptionGraphWithoutVertices& _exception)
{
  str_what = _exception.what();
  line = _exception.errorLine();
  file = _exception.errorFile();
}

ExceptionGraphWithoutVertices::ExceptionGraphWithoutVertices(int _line, const char* _file)
{
  str_what = "The graph has no vertices!";
  line = _line;
  file = _file;
}

ExceptionGraphWithoutVertices::~ExceptionGraphWithoutVertices()
{
  line = -1;
};