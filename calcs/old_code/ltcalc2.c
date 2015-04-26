#include <stdio.h>
#include <stdlib.h>
#define MULT '*'
#define PLUS '+'
#define SIZE 10

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
  input.buff = malloc(SIZE);
  res.buff = malloc(SIZE); 
  ops.buff = malloc(SIZE);
  input.cur = 0; res.cur = 0; ops.cur = 0;
  input.sz = SIZE; res.sz = SIZE; ops.sz = SIZE;
  if (!input.buff || !res.buff || !ops.buff)
    printf("Out of memory");
}

void add_char(char c) {
  if (input.cur >= input.sz) {
    input.buff = realloc(input.buff, input.sz*sizeof(unsigned)*2);
    input.sz *= 2;
  }
  input.buff[input.cur++] = c;
}

void add_op(char c) {
  if (ops.cur >= input.sz) {
    ops.buff = realloc(ops.buff, ops.sz*sizeof(unsigned)*2);
    ops.sz *= 2;
  }
  ops.buff[ops.cur++] = c;
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
  if (input.buff[0] == PLUS || input.buff[0] == MULT)
    printf("Illegal calculation");
  else if (input.buff[input.cur-1] == PLUS || input.buff[input.cur-1] == MULT)
    printf("Illegal calculation");
  
  int i = 0, num = 0;
  for (; i < input.cur; i++) {
    if (input.buff[i] != PLUS && input.buff[i] != MULT) { 
      num <<= 1;
      if (input.buff[i] == '1')
        num^=1;
    }
    else {
      add_res(num);
      num = 0;  
      if (input.buff[i] == PLUS) {
        while (ops.cur && ops.buff[ops.cur-1] == MULT){
          apply_op();}
        add_op(PLUS);
      }
      else add_op(MULT);
    }
  }
  add_res(num);

  while (res.cur > 1)  
    apply_op();
    
  printf("%s = %d\n", input.buff, res.buff[0]);    
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
