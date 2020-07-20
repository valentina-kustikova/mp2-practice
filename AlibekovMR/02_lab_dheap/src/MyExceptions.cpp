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

ExceptionIncorrectSize::ExceptionIncorrectSize()
{
  str_what = "Incorrect size!";
  line = -1;
  file = 0;
}

ExceptionIncorrectSize::ExceptionIncorrectSize(const ExceptionIncorrectSize& _exception)
{
  str_what = _exception.what();
  line = _exception.errorLine();
  file = _exception.errorFile();
}

ExceptionIncorrectSize::ExceptionIncorrectSize(int _line, const char* _file)
{
  str_what = "Incorrect size!";
  line = _line;
  file = _file;
}

ExceptionIncorrectSize::~ExceptionIncorrectSize()
{
  line = -1;
}

ExceptionIncorrectVertex::ExceptionIncorrectVertex()
{
  str_what = "There is no such vertex in the graph!";
  line = -1;
  file = 0;
}

ExceptionIncorrectVertex::ExceptionIncorrectVertex(const ExceptionIncorrectVertex& _exception)
{
  str_what = _exception.what();
  line = _exception.errorLine();
  file = _exception.errorFile();
}

ExceptionIncorrectVertex::ExceptionIncorrectVertex(int _line, const char* _file)
{
  str_what = "There is no such vertex in the graph!";
  line = _line;
  file = _file;
}

ExceptionIncorrectVertex::~ExceptionIncorrectVertex()
{
  line = -1;
}

ExceptionEmptyData::ExceptionEmptyData()
{
  str_what = "Empty data!";
  line = -1;
  file = 0;
}

ExceptionEmptyData::ExceptionEmptyData(const ExceptionEmptyData& _exception)
{
  str_what = _exception.what();
  line = _exception.errorLine();
  file = _exception.errorFile();
}

ExceptionEmptyData::ExceptionEmptyData(int _line, const char* _file)
{
  str_what = "Empty data!";
  line = _line;
  file = _file;
}

ExceptionEmptyData::~ExceptionEmptyData()
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
}

ExceptionGraphWithLoop::ExceptionGraphWithLoop()
{
  str_what = "The graph has loop!";
  line = -1;
  file = 0;
}

ExceptionGraphWithLoop::ExceptionGraphWithLoop(const ExceptionGraphWithLoop& _exception)
{
  str_what = _exception.what();
  line = _exception.errorLine();
  file = _exception.errorFile();
}

ExceptionGraphWithLoop::ExceptionGraphWithLoop(int _line, const char* _file)
{
  str_what = "The graph has loop!";
  line = _line;
  file = _file;
}

ExceptionGraphWithLoop::~ExceptionGraphWithLoop()
{
  line = -1;
};