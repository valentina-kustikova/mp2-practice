#pragma once

#include <string>

struct TException
{
};

struct TBadIdException : TException
{

};

struct TBadEdgeException : TException
{

};

struct TContainerIsFullException : TException
{

};

struct TWrongGraphException : TException
{

};

struct TBadSizeException : TException
{

};