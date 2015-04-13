#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// assumes:
//  input.buff != NULL 
//  input.cur <= input.sz 
void eval_pressed() {
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

  printf("%u\n", sum + n * mul);
  input.cur = 0;
  return;

  parsing_error:
  printf("E\n");
  input.cur = 0;
}

void init_pressed() {
  input.buff = malloc(10);
  input.cur = 0;
  input.sz = 10;
}

// fyi this function is not totally memory safe...
void test(char* expr, unsigned len, char* expected) {
  printf("--------------------------------\n");
  printf("Testing: %s\n", expr);
  if (input.buff)
    free(input.buff);
  input.buff = malloc(len);
  memcpy(input.buff, expr, len);
  input.cur = len;
  printf("Got: ");
  eval_pressed();
  printf("Expected: %s\n", expected);
  free(input.buff);
  input.buff = NULL;
  input.cur = 0;
}

int main() {
  // parse errors
  test("", 0, "E");
  test("+11+101", 7, "E");
  test("11+101+", 7, "E");
  test("11+*101", 7, "E");
  test("11+1a01", 7, "E");

  // no ops
  test("0", 1, "0");
  test("1", 1, "1");
  test("01101", 5, "13");

  // basic addition and multiplication
  test("1+0", 3, "1");
  test("0+1", 3, "1");
  test("11*0", 4, "0");
  test("0*11", 4, "0");
  test("11*1", 4, "3");
  test("1*11", 4, "3");
  test("11+101", 6, "8"); 
  test("11*101", 6, "15"); 

  // more complex expressions
  test("11+111+10", 9, "12");
  test("11*111*10", 9, "42");
  test("11*111+10", 9, "23");
  test("11+111*10", 9, "17");
  test("11+111*10+101", 13, "22");
  test("11*111+10*101", 13, "31");

  return 0;
}
