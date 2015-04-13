#include <stdio.h>
#include <stdlib.h>

/*
Changes from calc.c:
- Store chars instead of unsigneds
- eval_pressed does multiplication instead of repeated addition
     - BUG: forgets to clear cur

 */

struct input {
  char *buff;
  unsigned cur;
  unsigned sz;
} input;

/* Helpers */
void add_char(char c) {
  if (input.cur >= input.sz) {
    input.buff = realloc(input.buff, input.sz * 2);
    input.sz *= 2;
  }
  input.buff[input.cur++] = c;
}


/* Callbacks */

void zero_pressed() {
  add_char('0');
}

void one_pressed() {
  add_char('1');
}

void plus_pressed() {
  add_char('+');
}

void mult_pressed() {
  add_char('*');
}

void eval_pressed() {
  printf("%s\n", input.buff);
  
}

void init_pressed() {
  input.buff = malloc(10);
  input.cur = 0;
  input.sz = 10;
}

int main() {
  init_pressed();
  zero_pressed();
  plus_pressed();
  one_pressed();
  eval_pressed();
}
