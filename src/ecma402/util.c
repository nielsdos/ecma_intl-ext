/*
   +----------------------------------------------------------------------+
   | ecma_intl extension for PHP                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) Ben Ramsey <ben@benramsey.com>                         |
   | This source file is subject to the MIT license that is bundled with  |
   | this package in the file LICENSE, and is available at the following  |
   | web address: https://opensource.org/license/mit/                     |
   +----------------------------------------------------------------------+
*/

#include "util.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static void sort(char **array, int length);
static int compareStrings(const void *left, const void *right);
static int removeDuplicates(char **array, int length);
static void strArrayWalk(char **array, int length, char *(*callback)(char *));

int sortAndRemoveDuplicates(char **array, int length,
                            char *(*callback)(char *)) {
  if (callback != NULL) {
    strArrayWalk(array, length, (*callback));
  }

  sort(array, length);

  return removeDuplicates(array, length);
}

char *strToLower(char *string) {
  for (char *p = string; *p; p++) {
    *p = tolower(*p);
  }

  return string;
}

char *strToUpper(char *string) {
  for (char *p = string; *p; p++) {
    *p = toupper(*p);
  }

  return string;
}

static int removeDuplicates(char **array, int length) {
  int i, j, k, originalLength = length;

  for (i = 0; i < length; i++) {
    for (j = i + 1; j < length; j++) {
      if (strcmp(array[i], array[j]) == 0) {
        for (k = j; k < length - 1; k++) {
          array[k] = array[k + 1];
        }
        length--;
        j--;
      }
    }
  }

  if ((originalLength - length) > 0) {
    for (i = length; i < originalLength; i++) {
      array[i] = NULL;
    }
  }

  return length;
}

static void sort(char **array, int length) {
  qsort(array, length, sizeof(const char *), compareStrings);
}

static int compareStrings(const void *left, const void *right) {
  return strcmp(*(const char **)left, *(const char **)right);
}

static void strArrayWalk(char **array, int length, char *(*callback)(char *)) {
  for (int i = 0; i < length; i++) {
    array[i] = (*callback)(array[i]);
  }
}
