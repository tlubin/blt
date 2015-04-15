#include "old_calc.h" 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define MULT '*'
#define PLUS '+'
#define SIZE 10

static struct input {
  char *buff;
  unsigned cur;
  unsigned sz;
} input;

static struct ops{
  unsigned *buff;
  unsigned cur;
  unsigned sz;
} ops;

static struct res{
  unsigned *buff;
  unsigned cur;
  unsigned sz;
} res;

/* Helpers */

void old_calc::init_pressed() {
  input.buff = (char*) malloc(SIZE*sizeof(unsigned));
  res.buff = (unsigned*) malloc(SIZE*sizeof(unsigned)); 
  ops.buff = (unsigned*) malloc(SIZE*sizeof(unsigned));
  input.cur = 0; res.cur = 0; ops.cur = 0;
  input.sz = SIZE; res.sz = SIZE; ops.sz = SIZE;
  if (!input.buff || !res.buff || !ops.buff)
    printf("Out of memory");
}

static void add_char(char c) {
  if (input.cur >= input.sz) {
    input.buff = (char*) realloc(input.buff, input.sz*sizeof(unsigned)*2);
    input.sz *= 2;
  }
  input.buff[input.cur++] = c;
}

static void add_op(char c) {
  if (ops.cur >= input.sz) {
    ops.buff = (unsigned*) realloc(ops.buff, ops.sz*sizeof(unsigned)*2);
    ops.sz *= 2;
  }
  ops.buff[ops.cur++] = c;
}

static void add_res(unsigned n) {
  if (res.cur >= res.sz) {
    res.buff = (unsigned*) realloc(res.buff, res.sz*sizeof(unsigned)*2);
    res.sz *= 2;
  }
  res.buff[res.cur++] = n;
}

static void apply_op() {
  if (ops.buff[ops.cur-1] == MULT)
    res.buff[res.cur-2] = res.buff[res.cur-1] * res.buff[res.cur-2];
  else
    res.buff[res.cur-2] = res.buff[res.cur-1] + res.buff[res.cur-2];
  res.cur--;
  ops.cur--;
}

/* Callbacks */

void old_calc::zero_pressed() {
  add_char('0');
}

void old_calc::one_pressed() {
  add_char('1');
}

void old_calc::plus_pressed() {
  add_char('+');
}

void old_calc::mult_pressed() {
  add_char('*');
}

int old_calc::eval_pressed() {
  int i = 0, num = 0, opflag = 0;
  if (!input.cur || input.buff[0] == PLUS || input.buff[0] == MULT || input.buff[input.cur-1] == PLUS || input.buff[input.cur-1] == MULT) {
    goto error;}
  for (; i < input.cur; i++) {
    if (input.buff[i] != PLUS && input.buff[i] != MULT) { 
      opflag = 0;
      num <<= 1;
      if (input.buff[i] == '1')
        num^=1;
    }
    else {
      if (opflag) goto error;
      add_res(num);
      num = 0;  
      if (input.buff[i] == PLUS) {
        while (ops.cur && ops.buff[ops.cur-1] == MULT)
          apply_op();
        add_op(PLUS);
      }
      else add_op(MULT);
      opflag = 1;
    }
  }
  add_res(num);
  
  while (res.cur > 1 && ops.cur) apply_op();
  if (ops.cur != 0 || res.cur != 1){
    goto error;
    }
  
  input.cur = 0; res.cur = 0; ops.cur = 0;
  return res.buff[0];

error:
  input.cur = 0; res.cur = 0; ops.cur = 0;
  return -1;
}

/*
int main()
{
  old_calc::init_pressed();
  old_calc::one_pressed();
  old_calc::eval_pressed();
  old_calc::zero_pressed();
 printf("%d\n", old_calc::eval_pressed());
}*/
