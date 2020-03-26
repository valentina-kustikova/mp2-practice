#pragma once

#include "TException.h"

TException::TException(TExceptionCode code_, size_t line_)
{
    code = code_;
    line = line_;
}