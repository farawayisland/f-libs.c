// ~/.config/c-cpp/c/libraries/f-libs/include/f-core/fcommon.h
#ifndef FCORE_FCOMMON_H_
#define FCORE_FCOMMON_H_

#include <stddef.h>

/* enums */
enum ArraySize {
  MAX_SIZE_STR_GENERAL = 22,
};

enum ExitCode {
  ERROR_INVALID_INDEX = -4,
  ERROR_INVALID_INPUT = -3,
  ERROR_INVALID_SIZE = -2,
  ERROR_KEY_NOT_FOUND = -1,
  SUCCESS = 0
};

#endif
