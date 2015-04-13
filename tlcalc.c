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
  input.buff[input.cur++] = n;
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

unsigned do_eval(unsigned *buff, unsigned sz) {
  int mult = -1;
  int plus = -1;
  for (int i = 0; i < sz; i++) {
    if (buff[i] == MULT) {
      mult = i;
      break;
    }
    if (buff[i] == PLUS && plus == -1)
      plus = i;
  }

  if (plus != -1) {
    return do_eval(buff, plus) + do_eval(&buff[plus+1], sz - plus - 1);
  }

  if (mult != -1) {
    return do_eval(buff, mult)*do_eval(&buff[mult+1], sz - mult - 1);
  }

  unsigned res = 0;
  for (int i = 0; i < sz; i++) {
    res += buff[sz-i-1] << i;
  }
  return res;
}

unsigned eval_pressed() {
  for (int i = 0; i < input.cur; i++) {
    if (input.buff[i] == PLUS)
      printf("+");
    else if (input.buff[i] == MULT)
      printf("*");
    else
      printf("%u", input.buff[i]);
  }
  printf("\n");
  return do_eval(input.buff, input.cur);
}

void init_pressed() {
  input.buff = malloc(10*sizeof(unsigned));
  input.cur = 0;
  input.sz = 10;
}

int main() {
  init_pressed();
  one_pressed();
  zero_pressed();
  one_pressed();
  plus_pressed();
  one_pressed();
  mult_pressed();
  one_pressed();
  one_pressed();
  plus_pressed();
  zero_pressed();
  one_pressed();
  printf("RES: %u\n", eval_pressed());
}
