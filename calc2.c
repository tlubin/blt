#include <stdio.h>
  #include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

int lt_eval_pressed() {
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

int do_eval(char *buff, unsigned sz) {
  int mult = -1;
  int plus = -1;
  if (sz == 0)
    return -1;

  for (int i = 0; i < sz; i++) {
    if (buff[i] == '*')
      mult = i;
    else if (buff[i] == '+' && plus == -1)
      plus = i;
  }

  if (plus != -1) {
    int left = do_eval(buff, plus);
    int right = do_eval(&buff[plus+1], sz - plus - 1);

    if (left == -1 || right == -1)
      goto error;
    return left + right;
  }

  if (mult != -1) {
    int left = do_eval(buff, mult);
    int right = do_eval(&buff[mult+1], sz - mult - 1);
    if (left == -1 || right == -1)
      goto error;
    return left * right;
  }

  unsigned res = 0;
  for (int i = 0; i < sz; i++)
    res += (buff[sz-i-1] - '0') << i;
  input.cur = 0;
  return res;

error:
  input.cur = 0;
  return -1;
}

int tl_eval_pressed() {
  return do_eval(input.buff, input.cur);
}

int ab_eval_pressed() {
  unsigned sum = 0;  // stores running sum
  unsigned mul = 1;  // temp store for multiplication
  unsigned n = 0;  // temp value of operand currently being parsed
  int need_operand = 1;  // are we in the middle of an operation?

  char* p;
  for (p = input.buff; p != &input.buff[input.cur]; ++p) {
    switch (*p) { 
      case '0':
        need_operand = 0;
        n *= 2;
        break;

      case '1':
        need_operand = 0;
        n = n * 2 + 1;
        break;

      case '+':
        if (need_operand) goto parsing_error;
        need_operand = 1;
        sum += n * mul;
        mul = 1;
        n = 0;
        break;

      case '*':
        if (need_operand) goto parsing_error;
        need_operand = 1;
        mul *= n;
        n = 0;
        break;

      default:
        goto parsing_error;
    }
  }

  if (need_operand) goto parsing_error;

  input.cur = 0;
  return sum + n * mul;

  parsing_error:
  input.cur = 0;
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
  //  do_test("11+1a01", 7, "-1", eval);

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
  int t1 = clock();
  printf("----------TESTING TODD-------\n");
  test(&tl_eval_pressed);
  t1 = clock()-t1;
  
  int t2 = clock();
  printf("----------TESTING LILY-------\n");
  test(&lt_eval_pressed);
  t2 = clock()-t2;
  
  int t3 = clock();
  printf("----------TESTING AARON-------\n");
  test(&ab_eval_pressed);
  t3 = clock()-t3;
  printf("Todd Time: %d\n", t1);
  printf("Lily Time: %d\n", t2);
  printf("Aaron Time: %d\n", t3);
  return 0;
}
