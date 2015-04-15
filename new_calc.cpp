#include "new_calc.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SIZE 10

struct input {
  char *buff;
  unsigned cur;
  unsigned sz;
} input;

/* Helpers */

void init_pressed() {
  input.buff = malloc(SIZE); 
  input.cur = 0;
  input.sz = SIZE;
  if (!input.buff)
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
