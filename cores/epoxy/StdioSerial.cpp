/*
 * Copyright (c) 2019 Brian T. Park
 * MIT License
 */

#include <stdio.h>
#include <unistd.h>
#include "StdioSerial.h"

size_t StdioSerial::write(uint8_t c) {
  int result = putchar(c);
  fflush(stdout);
  return (result == EOF) ? 0 : 1;
}

void StdioSerial::flush() {
  fflush(stdout);
}

int StdioSerial::read() {
  int res;
  if (bufch == -1) ::read(STDIN_FILENO, &bufch, 1);
  res = bufch;
  bufch = -1;
  return res;
}

int StdioSerial::peek() {
  if (bufch == -1) ::read(STDIN_FILENO, &bufch, 1);
  return bufch;
}

int StdioSerial::available() {
  if (bufch == -1) ::read(STDIN_FILENO, &bufch, 1);
  return (bufch != -1);
}

StdioSerial Serial;
