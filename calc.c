#include <stdio.h>
#include <stdlib.h>

#define PLUS 2
#define MULT 3

struct input {
  unsigned *buff;
  unsigned cur;
  unsigned sz;
} input;

/* Helpers */
void add_num(unsigned n) {
  if (input.cur >= input.sz) {
    input.buff = realloc(input.buff, input.sz*sizeof(unsigned)*2);
    input.sz *= 2;
  }
  input.buff[input.cur++] = c;
}


/* Callbacks */

void zero_pressed() {
  add_num(0);
}

void one_pressed() {
  add_num(1);
}

void plus_pressed() {
  add_num(PLUS);
}

void mult_pressed() {
  add_num(MULT);
}

int eval_pressed() {
  printf("%s\n", input.buff);
  
}

void init_pressed() {
  input.buff = malloc(10*sizeof(unsigned));
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
