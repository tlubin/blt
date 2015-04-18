#include "old_calc.h" 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define SIZE 1000 

static struct input {
  char *buff;
  unsigned cur;
  unsigned sz;
} input;

/* Helpers */

void old_calc::init_pressed() {
  input.buff = (char*) malloc(SIZE); 
  input.cur = 0;
  input.sz = SIZE;
}

static void add_char(char c) {
  if (input.cur >= input.sz) {
    input.buff = (char*) realloc(input.buff, input.sz*sizeof(unsigned)*2);
    input.sz *= 2;
  }
  input.buff[input.cur++] = c;
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

