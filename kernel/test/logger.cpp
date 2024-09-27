#include "logger.hpp"

#include <cstddef>
#include <cstdio>

namespace {
  LogLevel log_level = kWarn;
}

void SetLogLevel(LogLevel level) {
  log_level = level;
}

int Log(LogLevel level, const char* format, ...) {
  if (level > log_level) {
    return 0;
  }

  va_list ap;
  int result;

  va_start(ap, format);
  result = vprintf(format, ap);
  va_end(ap);

  return result;
}
 5 changes: 5 additions & 0 deletions5  
kernel/test/main.cpp
Original file line number	Original file line	Diff line number	Diff line change
@@ -0,0 +1,5 @@
#include <CppUTest/CommandLineTestRunner.h>

int main(int argc, char** argv) {
  return RUN_ALL_TESTS(argc, argv);
}