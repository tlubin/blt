#include <stdio.h>
#include <stdlib.h>

#define PLUS 2
#define MULT 3
#define SIZE 10

struct input {
  unsigned *buff;
  unsigned cur;
  unsigned sz;
} input;

struct ops{
  unsigned *buff;
  unsigned cur;
  unsigned sz;
} ops;

struct res{
  unsigned *buff;
  unsigned cur;
  unsigned sz;
} res;


/* Helpers */

void init_pressed() {
  input.buff = malloc(SIZE*sizeof(unsigned));
  res.buff = malloc(SIZE*sizeof(unsigned)); 
  ops.buff = malloc(SIZE*sizeof(unsigned));
  input.cur = 0; res.cur = 0; ops.cur = 0;
  input.sz = SIZE; res.sz = SIZE; ops.sz = SIZE;
  if (!input.buff || !res.buff || !ops.buff)
    printf("Out of memory");
}

void add_num(unsigned n) {
  if (input.cur >= input.sz) {
    input.buff = realloc(input.buff, input.sz*sizeof(unsigned)*2);
    input.sz *= 2;
  }
  input.buff[input.cur++] = n;
}

void add_op(unsigned n) {
  if (ops.cur >= input.sz) {
    ops.buff = realloc(ops.buff, ops.sz*sizeof(unsigned)*2);
    ops.sz *= 2;
  }
  ops.buff[ops.cur++] = n;
}

void add_res(unsigned n) {
  if (res.cur >= res.sz) {
    res.buff = realloc(res.buff, res.sz*sizeof(unsigned)*2);
    res.sz *= 2;
  }
  res.buff[res.cur++] = n;
}

void apply_op() {
  if (ops.cur-1 < 0) {
    printf("Bad equation");
    exit(1);
  }
  if (ops.buff[ops.cur-1] == MULT)
    res.buff[res.cur-2] = res.buff[res.cur-1] * res.buff[res.cur-2];
  else
    res.buff[res.cur-2] = res.buff[res.cur-1] + res.buff[res.cur-2];
  res.cur--;
  ops.cur--;
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

void eval_pressed() {
  if (input.buff[0] == PLUS || input.buff[0] == MULT)
    printf("Illegal calculation");
  else if (input.buff[input.cur-1] == PLUS || input.buff[input.cur-1] == MULT)
    printf("Illegal calculation");
  
  int i = 0, num = 0;
  for (; i < input.cur; i++) {
    if (input.buff[i] != PLUS && input.buff[i] != MULT) { 
      num <<= 1;
      if (input.buff[i] == 1)
        num^=1;
    }
    else {
      add_res(num);
      num = 0;  
      if (input.buff[i] == PLUS) {
        while (ops.cur && ops.buff[ops.cur-1] == MULT)
          apply_op();
        add_op(PLUS);
      }
      else add_op(MULT);
    }
  }
  add_res(num);

  while (res.cur > 1)  
    apply_op();
  
  int j = 0;
  for (; j < input.cur; j++)
    printf("%d ", input.buff[j]);
  printf("= %d\n", res.buff[0]);    
  input.cur = 0;
  res.cur = 0;
  ops.cur = 0;
}

int main() {
  init_pressed();
  zero_pressed();
  mult_pressed();
  one_pressed();
  plus_pressed();
  one_pressed();
  plus_pressed();
  zero_pressed();
  mult_pressed();
  one_pressed();
  plus_pressed();
  zero_pressed();
  mult_pressed();
  one_pressed();  
  eval_pressed();
  return 0;
}
