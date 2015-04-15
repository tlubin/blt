#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MULT '*'
#define PLUS '+'
#define SIZE 10

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
  res.buff = malloc(SIZE); 
  ops.buff = malloc(SIZE);
  res.cur = 0; ops.cur = 0;
  res.sz = SIZE; ops.sz = SIZE;
  if (!res.buff || !ops.buff)
    printf("Malloc failed\n");
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

int eval_pressed() {
  init_pressed();
  int i = 0, num = 0, opflag = 0;
  if (!input.cur || input.buff[0] == PLUS || input.buff[0] == MULT || input.buff[input.cur-1] == PLUS || input.buff[input.cur-1] == MULT)
    goto error;
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
  
  while (res.cur > 1) apply_op();
  if (ops.cur != 0 || res.cur != 1)
    goto error;
    
  return res.buff[0];
  input.cur = 0; res.cur = 0; ops.cur = 0;

error:
  input.cur = 0; res.cur = 0; ops.cur = 0;
  return -1;
}

// fyi this function is not totally memory safe...
void do_test(char* expr, unsigned len, char *expected, int (*eval)()) {
  printf("--------------------------------\n");
  printf("Testing: %s\n", expr);
  if (input.buff)
    free(input.buff);
  input.buff = malloc(len);
  memcpy(input.buff, expr, len);
  input.cur = len;
  int res = eval();
  printf("Got: %d ", res);
  printf("Expected: %s\n", expected);
  assert(res == atoi(expected));
  free(input.buff);
  input.buff = NULL;
  input.cur = 0;
}

void test(int (*eval)()) {
  do_test("", 0, "-1", eval);
  do_test("+11+101", 7, "-1", eval);
  do_test("11+101+", 7, "-1", eval);
  do_test("11+*101", 7, "-1", eval);

  // no ops
  do_test("0", 1, "0", eval);
  do_test("1", 1, "1", eval);
  do_test("01101", 5, "13", eval);

  // basic addition and multiplication
  do_test("1+0", 3, "1", eval);
  do_test("0+1", 3, "1", eval);
  do_test("11*0", 4, "0", eval);
  do_test("0*11", 4, "0", eval);
  do_test("11*1", 4, "3", eval);
  do_test("1*11", 4, "3", eval);
  do_test("11+101", 6, "8", eval); 
  do_test("11*101", 6, "15", eval); 

  // more complex expressions
  do_test("11+111+10", 9, "12", eval);
  do_test("11*111*10", 9, "42", eval);
  do_test("11*111+10", 9, "23", eval);
  do_test("11+111*10", 9, "17", eval);
  do_test("11+111*10+101", 13, "22", eval);
  do_test("11*111+10*101", 13, "31", eval);
}

int main() {
  printf("----------TESTING-------\n");
  test(&eval_pressed);
  return 0;

