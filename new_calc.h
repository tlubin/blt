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

/* Helpers */

void init_pressed() {
  res.buff = malloc(SIZE); 
  ops.buff = malloc(SIZE);
  res.cur = 0; ops.cur = 0;
  res.sz = SIZE; ops.sz = SIZE;
  if (!res.buff || !ops.buff)
    printf("Malloc failed\n");
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
}
