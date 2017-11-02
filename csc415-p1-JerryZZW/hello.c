#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MY_NAME "Zhewei Zhang"

int main() {
  /* code */
  char buf[128];

  sprintf(buf, "CSC415, This program written by %s \n", MY_NAME);
  write(1, buf, strlen(buf));

  return 0;
}
