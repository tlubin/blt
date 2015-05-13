

#include "/home/tslilyai/blt/blt_args.hpp"
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <string>

unsigned intCnt = 0;
int ints [] = { 7, 0, 13, INT_MAX, 16, 0, 30, 0, INT_MIN, 28, 0, 0, INT_MIN, -32, INT_MAX, 18, 0, 7, 0, 16, 0, 0, INT_MAX, INT_MIN, INT_MIN, 0, -14, 0, 0, 0, INT_MIN, 0, INT_MIN, INT_MIN, INT_MIN, -10, -50, -40, INT_MIN, 7, 22, INT_MAX, 39, 0, -35, 0, INT_MAX, 25, INT_MIN, 0, -11, 31, INT_MIN, 25, 8, 18, INT_MAX, INT_MAX, 38, 0, INT_MAX, INT_MAX, INT_MIN, 28, -6, -22, INT_MIN, 0, 0, INT_MAX, 0, INT_MIN, -16, INT_MIN, INT_MAX, 0, INT_MAX, INT_MAX, INT_MIN, 0, INT_MIN, -4, 32, -36, INT_MAX, 6, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 0, INT_MIN, 0, 50, INT_MIN, INT_MAX, 0, -31, 0, 0, -28, INT_MAX, 16, 43, INT_MIN, INT_MAX, INT_MIN, -18, -26, 0, -3, 0, 0, -46, INT_MAX, INT_MIN, INT_MAX, INT_MAX, 3, 43, INT_MAX, 0, 0, -40, 0, INT_MAX, INT_MIN, 0, -18, INT_MAX, INT_MIN, INT_MIN, 0, 0, 0, 50, INT_MIN, 0, 0, 0, 0, INT_MAX, -9, -43, -39, INT_MIN, INT_MIN, INT_MIN, -18, INT_MIN, -29, -17, INT_MIN, -15, INT_MIN, 0, 46, 18, INT_MIN, INT_MAX, 0, -22, 33, INT_MIN, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, 0, INT_MAX, INT_MAX, 0, 36, 43, -42, 0, -18, 35, 46, INT_MIN, 48, -45, INT_MAX, 19, INT_MIN, INT_MIN, -44, INT_MIN, 0, INT_MAX, -4, INT_MAX, -23, 0, 2, -11, INT_MIN, 0, -12, -16, 13, 0, INT_MIN, 41, 0, INT_MAX, INT_MIN, 22, 0, 6, -14, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 30, -50, INT_MAX, 0, INT_MIN, -35, INT_MIN, 19, -12, INT_MIN, 21, -41, INT_MAX, -49, 35, INT_MIN, INT_MIN, 7, 46, 47, 0, -49, 0, 0, INT_MAX, 0, 24, -39, -13, 22, 6, INT_MIN, INT_MIN, INT_MAX, INT_MAX, -50, 14, INT_MAX, INT_MIN, INT_MIN, 34, 0, INT_MAX, 0, -34, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 31, -12, -7, INT_MIN, INT_MAX, 0, INT_MIN, INT_MIN, 0, 0, 31, INT_MAX, INT_MIN, -26, INT_MIN, INT_MAX, INT_MAX, 12, 0, 0, -1, -36, INT_MAX, 31, INT_MAX, INT_MAX, -41, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, 0, INT_MAX, -26, 24, INT_MIN, INT_MIN, 22, 0, 0, -25, 49, 46, 0, -33, INT_MAX, -5, INT_MIN, -12, 50, 0, -16, INT_MAX, -10, 0, -35, -5, INT_MIN, 17, 39, INT_MIN, 0, -17, -42, 15, INT_MAX, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 50, 0, -38, INT_MAX, 0, INT_MAX, INT_MAX, -23, INT_MIN, 0, 0, INT_MAX, 0, 0, 36, INT_MIN, INT_MIN, 38, INT_MAX, INT_MAX, INT_MIN, -49, 42, -5, INT_MIN, INT_MIN, -11, INT_MAX, 0, -23, INT_MIN, INT_MIN, 0, INT_MAX, 0, 0, INT_MIN, 0, 0, 29, INT_MIN, -3, 37, 7, 18, 19, 14, 0, -39, INT_MIN, 24, INT_MAX, INT_MAX, INT_MIN, 31, INT_MIN, 7, INT_MAX, INT_MIN, -30, INT_MIN, INT_MIN, 0, 40, INT_MIN, INT_MAX, INT_MAX, -44, 0, 6, 0, 0, 47, 0, INT_MAX, 12, INT_MAX, -40, -6, -23, -39, INT_MAX, -5, INT_MIN, INT_MAX, 49, INT_MAX, 12, 25, INT_MAX, -12, 0, INT_MAX, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, -33, 0, 39, INT_MIN, 0, INT_MIN, -6, 31, 0, INT_MIN, 0, 0, INT_MIN, 23, 0, 0, INT_MAX, 0, 0, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, 0, INT_MIN, 36, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 0, 0, -41, INT_MAX, 9, -45, INT_MAX, INT_MIN, 14, INT_MAX, -48, 0, 26, INT_MAX, INT_MAX, INT_MAX, -25, INT_MAX, INT_MIN, INT_MAX, 18, 0, INT_MIN, 0, INT_MIN, -21, -21, 19, INT_MAX, INT_MAX, -14, 0, INT_MIN, INT_MAX, INT_MIN, 23, 26, 31, 37, 39, INT_MIN, 45, 0, 0, INT_MIN, 13, 43, 2, 0, -46, INT_MIN, 43, 5, 33, INT_MIN, -49, 0, 34, INT_MIN, INT_MAX, -35, -50, 0, INT_MAX, 40, -49, INT_MAX, 0, INT_MIN, 0, 0, 15, 25, -43, -15, 43, 18, INT_MIN, INT_MIN, -10, 12, 8, 0, INT_MIN, -42, INT_MAX, -38, INT_MIN, 0, 35, -20, INT_MIN, INT_MAX, -35, 40, -48, 17, INT_MAX, INT_MAX, 0, 0, 7, INT_MAX, INT_MIN, 0, INT_MIN, INT_MAX, -11, 0, INT_MAX, 9, INT_MAX, -14, INT_MAX, INT_MIN, 0, INT_MAX, INT_MAX, 50, INT_MIN, 0, 0, -32, INT_MIN, INT_MAX, INT_MIN, 0, -18, -7, 36, INT_MAX, 6, INT_MAX, INT_MAX, 0, INT_MIN, -8, 30, 36, 0, INT_MAX, INT_MAX, -25, 0, 22, INT_MIN, -25, INT_MAX, -40, 0, 0, 0, INT_MAX, INT_MAX, 19, INT_MAX, -18, 45, INT_MAX, INT_MIN, 14, 0, -31, INT_MIN, 0, INT_MIN, INT_MIN, 16, INT_MIN, INT_MAX, INT_MIN, INT_MIN, -41, INT_MIN, 24, -36, INT_MAX, 0, 13, INT_MAX, 0, -47, INT_MAX, INT_MIN, -23, 0, 0, INT_MAX, -31, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, INT_MAX, -36, 0, -7, 21, INT_MIN, 0, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 50, INT_MAX, 11, 30, INT_MIN, INT_MAX, -16, INT_MAX, INT_MIN, INT_MIN, -47, INT_MIN, INT_MIN, 36, 0, 38, 0, 0, -35, -29, 0, -1, INT_MIN, -31, -49, INT_MIN, 9, -7, 0, 20, INT_MIN, 40, 0, 38, INT_MIN, 0, INT_MAX, -39, 0, INT_MIN, INT_MIN, INT_MIN, 22, 0, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 0, INT_MAX, -37, -4, -45, INT_MAX, 0, -30, 0, -23, INT_MIN, 37, -40, -39, -49, 3, 43, 0, 13, -41, 22, INT_MAX, INT_MIN, 11, INT_MIN, -40, 6, INT_MAX, -41, -15, 0, 0, -45, 0, -30, 0, 23, -37, INT_MAX, 0, 17, 0, 38, INT_MAX, 0, INT_MAX, 0, 0, INT_MIN, 20, INT_MIN, 0, -28, 23, INT_MAX, -35, INT_MAX, -1, 42, INT_MAX, -37, INT_MAX, INT_MIN, -40, INT_MIN, 35, INT_MAX, INT_MAX, INT_MAX, INT_MIN, 8, INT_MIN, 0, INT_MIN, INT_MIN, 21, 0, 0, INT_MAX, 17, -43, INT_MAX, 0, 22, 0, 5, 0, 0, -14, INT_MIN, INT_MAX, INT_MIN, 0, -37, -21, -37, 37, 0, INT_MAX, INT_MIN, 27, -24, INT_MAX, INT_MAX, -37, 49, INT_MIN, 48, INT_MAX, 9, INT_MIN, 28, -10, INT_MAX, 47, -32, INT_MAX, -40, INT_MIN, INT_MIN, -46, INT_MIN, 0, -14, INT_MIN, INT_MIN, -39, 10, -11, 0, 0, INT_MAX, 0, -33, 13, 7, INT_MIN, 20, 18, 17, INT_MAX, -6, 9, INT_MAX, 0, INT_MIN, 0, 0, 32, -15, 0, -48, 4, 25, INT_MIN, 23, 23, 40, INT_MIN, -40, 0, -40, 0, INT_MAX, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 31, 0, INT_MIN, -28, 20, -2, 7, INT_MIN, -45, INT_MIN, INT_MIN, 0, 0, INT_MIN, 0, 16, INT_MAX, 0, 0, -24, INT_MAX, -23, 0, -25, INT_MIN, INT_MAX, INT_MAX, 43, -15, INT_MAX, INT_MIN, -30, INT_MIN, INT_MAX, INT_MAX, -2, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MIN, 17, 47, -36, 0, INT_MIN, INT_MIN, 0, 22, INT_MIN, INT_MAX, INT_MIN, 0, 0, INT_MIN, 23, 18, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 26, 0, INT_MIN, -12, -23, INT_MAX, INT_MAX, 7, INT_MAX, 0, INT_MAX, 0, INT_MAX, -23, 0, INT_MIN, 0, INT_MAX, 0, -39, 2, INT_MAX, INT_MIN, INT_MIN, 21, INT_MAX, 0, 0, INT_MIN, -23, INT_MIN, 0, 0, 13, INT_MAX, INT_MAX, 39, -46, -44, 45, -43, INT_MIN, 0, 0, -2, INT_MIN, INT_MIN, -17, 0, 36, 43, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MIN, INT_MIN, -19, INT_MAX, 26, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MIN, -33, -10, INT_MAX, INT_MAX, 39, 0, INT_MAX, INT_MAX, INT_MAX, -39, -19, INT_MIN, INT_MAX, 0, -13, 35, 33, INT_MAX, -37, INT_MAX, INT_MIN, -39, INT_MAX, INT_MIN, 16, 27, INT_MIN, 13, INT_MIN, 0, 26, INT_MIN, -32, INT_MAX, 31, INT_MAX, 0, INT_MIN, 0, 33, 17, INT_MAX, -46, INT_MIN, 0, 0, -26, 5, 0, 6, INT_MIN, 0, 0, -31, 41, INT_MAX, INT_MAX, 8, -22, 39, INT_MAX, 22, 0, INT_MAX, INT_MIN, -12, INT_MIN, INT_MAX, -45, INT_MAX, 0, 0, INT_MAX, 30, 0, INT_MAX, 33, INT_MAX, -23, 6, -24, 0, INT_MIN, 0, 45, 47, INT_MIN, 0, 34, 37, INT_MIN, 0, INT_MAX, INT_MAX, INT_MAX, 12, 0, 0, 0, 6, INT_MAX, 0, 40, INT_MIN, 9, 0, INT_MAX, 23, -26, 0, 0, INT_MIN, -14, INT_MIN, INT_MIN, INT_MIN, -26, INT_MAX, INT_MAX, INT_MIN, 0, INT_MAX, INT_MAX, INT_MAX, 29, INT_MIN, 0, 0, INT_MAX, INT_MAX, 0, 22, 0, INT_MIN, INT_MIN, -27, INT_MAX, INT_MAX, INT_MIN, 0, INT_MAX, 0, 0, INT_MAX, -2, 23, INT_MAX, 20, INT_MAX, 24, INT_MAX, 0, 0, 0, INT_MIN, -5, INT_MAX, INT_MIN, -16, INT_MIN, INT_MIN, -29, -14, INT_MAX, INT_MAX, -21, -19, -6, 50, 46, INT_MAX, -29, 0, 16, INT_MAX, 0, 12, 38, INT_MAX, 0, INT_MAX, INT_MIN, INT_MIN, 0, 0, 0, 10, INT_MIN, 33, -21, 20, INT_MAX, 19, INT_MIN, INT_MAX, 46, 0, 37, INT_MIN, INT_MAX, INT_MAX, 0, INT_MAX, 38, INT_MIN, 0, -41, INT_MAX, INT_MIN, 21, 0, INT_MAX, -40, -12, INT_MAX, 0, INT_MAX, -40, INT_MIN, 0, INT_MAX, 0, 29, 1, 0, -50, -32, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MIN, -17, -36, -43, 0, 13, 49, -29, 0, INT_MIN, -36, INT_MIN, -7, 0, 5, 4, 0, -35, 15, 5, INT_MAX, 0, 5, INT_MIN, 24, 0, -19, INT_MIN, INT_MAX, 0, 0, 0, INT_MIN, 11, INT_MAX, 1, 0, -31, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 39, INT_MIN, 0, 0, 0, INT_MIN, -41, INT_MIN, INT_MAX, -15, INT_MIN, 0, INT_MIN, -6, -38, -22, -3, -38, INT_MAX, 0, -29, 22, INT_MAX, 9, 0, INT_MIN, 38, 0, -40, -49, -16, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MAX, -11, INT_MAX, INT_MAX, 22, INT_MAX, INT_MAX, 0, 0, 0, INT_MIN, 1, 0, INT_MAX, 0, INT_MAX, 0, 0, INT_MAX, 42, INT_MAX, INT_MIN, 37, 31, 0, 0, 19, INT_MIN, INT_MAX, -48, INT_MIN, INT_MAX, 0, -45, INT_MIN, -48, -18, 0, -32, -37, INT_MIN, 15, INT_MAX, 0, 0, -19, INT_MAX, 3, INT_MAX, INT_MAX, 0, INT_MAX, 0, INT_MAX, INT_MIN, 0, INT_MIN, INT_MIN, 42, 5, INT_MIN, -47, INT_MIN, 0, -25, -27, 0, 0, INT_MAX, INT_MAX, -2, -28, 0, 0, -25, INT_MAX, INT_MIN, -45, -15, 0, INT_MIN, -19, INT_MIN, -26, INT_MIN, -39, 0, INT_MIN, INT_MAX, INT_MAX, INT_MAX, -8, INT_MIN, INT_MAX, INT_MIN, 0, INT_MIN, INT_MAX, 16, INT_MAX, 9, 0, 0, INT_MAX, INT_MIN, 0, 0, INT_MAX, INT_MIN, 14, -7, -46, INT_MAX, -24, 0, INT_MAX, INT_MAX, 0, -9, -46, INT_MAX, -26, 0, 0, -40, INT_MIN, 0, 0, 0, INT_MIN, INT_MIN, 0, INT_MIN, -18, INT_MAX, -40, 12, -9, 0, 8, 19, 0, INT_MAX, 8, 0, 2, 45, -25, -42, 0, 17, 0, INT_MAX, -43, 0, 41, 24, INT_MAX, INT_MIN, -16, INT_MIN, INT_MIN, 0, 49, INT_MAX, INT_MAX, -5, INT_MIN, INT_MIN, -13, 0, 0, 15, 0, -11, 0, 15, INT_MIN, INT_MAX, 0, 0, INT_MIN, 0, INT_MIN, INT_MAX, 0, 20, -11, 0, INT_MIN, 45, 0, INT_MIN, 0, INT_MIN, 0, INT_MAX, 48, -45, INT_MIN, 0, INT_MIN, INT_MAX, 6, 40, -43, 0, INT_MIN, INT_MIN, 44, -14, -48, INT_MAX, 0, INT_MAX, INT_MAX, 41, INT_MAX, INT_MAX, 0, -26, 0, 0, INT_MAX, 0, -39, 37, 7, INT_MAX, 0, INT_MAX, -31, INT_MIN, 0, INT_MIN, INT_MAX, 50, -22, INT_MAX, -39, 0, INT_MAX, 29, INT_MIN, -15, 0, INT_MIN, -21, 0, 0, INT_MAX, -9, 0, INT_MIN, -47, INT_MIN, INT_MIN, 30, -12, INT_MAX, 0, 0, INT_MAX, INT_MIN, INT_MIN, 0, -14, 36, INT_MAX, INT_MIN, 0, 0, -15, 0, 0, 0, 43, -39, INT_MIN, 35, INT_MAX, -27, 48, INT_MIN, 0, 0, INT_MIN, INT_MAX, 41, 30, INT_MAX, 0, INT_MIN, 0, 0, -19, INT_MAX, INT_MIN, INT_MAX, 41, 36, INT_MIN, INT_MIN, INT_MAX, -6, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MAX, 45, INT_MAX, -41, INT_MAX, 0, INT_MIN, INT_MAX, INT_MIN, 0, 0, 0, INT_MIN, INT_MAX, 25, INT_MIN, INT_MIN, 49, 6, 0, INT_MIN, INT_MAX, -27, INT_MIN, 0, INT_MAX, INT_MAX, -13, 0, -19, INT_MAX, -37, INT_MIN, INT_MIN, 0, INT_MAX, 0, INT_MIN, 0, 0, INT_MAX, 20, -32, -21, -22, 29, INT_MAX, 0, -4, INT_MAX, -36, 0, 4, INT_MAX, -34, INT_MAX, 44, -36, INT_MAX, -20, -8, 46, INT_MIN, 0, 0, -21, 32, 0, INT_MIN, -6, 0, INT_MIN, -6, -34, 0, 0, INT_MIN, 23, INT_MAX, -46, INT_MIN, -36, -25, 0, -35, -3, INT_MAX, INT_MIN, -36, INT_MIN, INT_MIN, 0, 0, 20, 2, INT_MIN, INT_MIN, 17, 13, 0, -35, INT_MAX, 24, -47, -34, 0, INT_MIN, 0, 0, -43, 0, 41, -44, 0, 0, -32, INT_MIN, -40, 0, 33, INT_MAX, 49, INT_MAX, -42, INT_MAX, 0, 0, -21, -5, INT_MIN, INT_MIN, -18, 21, 32, INT_MAX, 1, 41, 0, 0, 0, 0, INT_MIN, INT_MAX, INT_MAX, -42, 0, INT_MAX, INT_MIN, INT_MAX, 38, 0, -43, -32, 38, INT_MAX, INT_MIN, 6, -39, INT_MAX, 46, -46, INT_MIN, INT_MAX, 38, 9, INT_MAX, 0, 47, INT_MAX, 47, -11, -13, 3, -47, 0, INT_MIN, 0, 0, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, 22, 0, INT_MIN, INT_MAX, -47, 34, INT_MIN, 50, INT_MAX, -9, 0, -43, INT_MIN, 0, INT_MIN, INT_MIN, -6, 28, -8, -13, 48, INT_MIN, -39, 0, INT_MIN, 0, 26, 43, INT_MIN, 12, 0, INT_MIN, INT_MAX, 41, -19, -3, 0, 0, -34, 0, 41, INT_MAX, 0, INT_MIN, 23, -30, INT_MAX, 45, 31, INT_MAX, -36, 39, INT_MAX, INT_MIN, INT_MIN, 7, 42, INT_MIN, INT_MIN, 0, -10, INT_MIN, INT_MAX, INT_MIN, INT_MIN, -42, 0, -14, -31, 0, 0, INT_MAX, 36, INT_MIN, -16, INT_MIN, -40, INT_MAX, INT_MIN, 0, 0, 0, -5, -10, INT_MAX, 29, 0, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0, 7, 0, 36, INT_MAX, INT_MAX, 0, -23, INT_MIN, 0, -2, -36, INT_MAX, -31, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MIN, 14, -37, INT_MAX, -33, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 0, 15, INT_MAX, 0, 31, INT_MAX, -44, 0, 50, 0, 20, 14, 0, INT_MIN, 0, -49, 0, INT_MAX, -15, 0, INT_MAX, -16, INT_MAX, 0, INT_MAX, -28, INT_MIN, INT_MIN, 4, INT_MIN, -42, -7, 47, INT_MAX, 0, 26, 13, 0, INT_MIN, INT_MAX, INT_MAX, 0, 15, INT_MIN, -21, 36, INT_MAX, INT_MAX, INT_MAX, 16, -47, INT_MIN, INT_MIN, 0, INT_MAX, 0, INT_MIN, 10, 0, INT_MAX, INT_MIN, INT_MIN, -43, 19, 35, 0, 0, INT_MAX, INT_MAX, -3, 0, 0, INT_MIN, INT_MIN, -18, 48, -45, 0, INT_MIN, INT_MAX, 0, INT_MIN, -44, 28, INT_MIN, -15, -44, 37, -19, -2, 0, 0, 34, 0, INT_MAX, 47, INT_MAX, 7, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, -23, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 13, INT_MAX, -48, 0, INT_MAX, INT_MIN, INT_MIN, 0, INT_MIN, INT_MIN, INT_MAX, 44, INT_MAX, INT_MIN, 0, 0, 28, INT_MAX, 6, 0, 0, 0, 0, INT_MAX, 0, INT_MIN, INT_MIN, 15, INT_MIN, 40, INT_MIN, 40, -26, INT_MIN, INT_MAX, -34, -40, 0, INT_MAX, 0, -10, 32, INT_MIN, -27, INT_MAX, INT_MIN, -42, INT_MAX, INT_MAX, INT_MIN, 44, 45, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MAX, -10, 0, INT_MAX, 0, -19, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 0, -42, 0, 5, INT_MAX, 31, 33, 11, INT_MIN, 37, -49, 41, 0, -8, INT_MAX, INT_MIN, INT_MAX, 38, 0, INT_MIN, INT_MIN, 40, INT_MAX, 33, -11, 15, 0, INT_MAX, -11, 0, INT_MAX, 0, 37, 0, -12, INT_MAX, 0, 8, -17, 24, INT_MAX, INT_MAX, 0, -23, 0, 30, 45, -43, INT_MIN, -43, -35, 0, INT_MAX, 0, 9, 43, -11, -15, INT_MAX, -18, 20, -1, INT_MAX, 11, 26, INT_MAX, 1, 3, 0, -24, -7, INT_MIN, INT_MAX, INT_MAX, INT_MIN, -15, 0, 3, INT_MIN, 16, 0, INT_MAX, INT_MIN, 42, 0, INT_MAX, INT_MAX, INT_MAX, -30, 2, INT_MAX, INT_MAX, INT_MAX, 0, -45, 46, 47, 0, 8, INT_MAX, INT_MAX, INT_MIN, 0, INT_MAX, INT_MAX, 8, 22, -36, INT_MAX, -11, 3, INT_MIN, -35, INT_MAX, 46, INT_MAX, 0, -23, -25, 0, 0, 33, INT_MAX, INT_MAX, -8, INT_MAX, -30, INT_MAX, 43, INT_MIN, INT_MAX, -4, 0, INT_MIN, 0, INT_MAX, INT_MIN, 27, 0, INT_MIN, 0, INT_MAX, INT_MIN, INT_MIN, -20, INT_MIN, 6, INT_MIN, -21, 0, INT_MIN, 0, INT_MAX, INT_MAX, INT_MAX, 11, INT_MAX, INT_MIN, INT_MAX, 35, INT_MAX, 38, INT_MAX, INT_MIN, 0, 41, INT_MAX, 0, 30, 0, -9, 2, INT_MAX, INT_MIN, 0, INT_MAX, 0, INT_MIN, -4, 0, -35, INT_MAX, -9, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 0, 0, INT_MIN, INT_MAX, -2, 0, 47, 8, 22, 0, 35, 15, INT_MIN, INT_MIN, -39, 0, -24, INT_MIN, 0, 0, -40, 0, INT_MAX, 36, INT_MAX, 0, INT_MIN, 0, -19, INT_MAX, 0, 0, -19, 0, 13, 0, 29, INT_MAX, INT_MIN, 40, -49, INT_MIN, -11, INT_MAX, INT_MIN, -7, 35, INT_MAX, 48, 0, 17, INT_MIN, 0, INT_MAX, -43, 3, 0, INT_MIN, 20, INT_MAX, 0, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 5, 0, 0, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, 0, 0, INT_MAX, 0, 0, 22, 0, 0, INT_MAX, INT_MIN, -44, INT_MAX, 0, -50, -36, INT_MIN, INT_MAX, 2, INT_MIN, INT_MIN, 20, -3, 0, -25, INT_MAX, 0, 5, 0, -20, -47, 0, 0, -37, 49, -10, -41, INT_MAX, 15, INT_MIN, INT_MIN, INT_MAX, 13, INT_MIN, 49, INT_MIN, 0, INT_MIN, INT_MAX, INT_MIN, INT_MIN, -31, 0, INT_MAX, INT_MIN, 32, -11, 3, INT_MAX, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 3, 50, 0, INT_MAX, 49, 0, INT_MIN, INT_MAX, 30, INT_MAX, 0, -5, -46, -31, 10, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 37, INT_MIN, INT_MIN, 31, 19, 12, INT_MIN, -36, INT_MIN, INT_MIN, -8, INT_MAX, INT_MAX, 0, -41, 0, 0, INT_MIN, 0, 0, INT_MAX, 0, 0, -44, INT_MAX, -7, -26, -41, 0, INT_MAX, -49, INT_MIN, 0, INT_MAX, 0, INT_MIN, INT_MIN, 0, 31, INT_MIN, 0, -46, -11, 27, -11, 0, INT_MAX, 0, 29, -41, -2, INT_MAX, 0, INT_MAX, INT_MIN, 0, -31, 0, 35, 4, 0, -49, 0, INT_MAX, INT_MIN, 49, INT_MIN, INT_MAX, -40, INT_MIN, 27, 40, INT_MIN, -38, 0, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 34, INT_MIN, 3, -40, 0, INT_MAX, INT_MAX, 10, -23, INT_MAX, INT_MIN, 0, -43, INT_MAX, -33, 0, 47, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 0, 0, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 0, 0, 0, INT_MIN, INT_MAX, -31, 0, 0, -28, 0, INT_MAX, 0, 20, -45, -5, INT_MAX, INT_MAX, -22, 0, 0, -29, 15, INT_MAX, 0, 31, 0, INT_MAX, 0, INT_MAX, INT_MAX, -19, 26, INT_MAX, 0, -2, INT_MAX, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, 9, 0, -39, -12, INT_MIN, -15, 14, 7, 0, 9, 0, INT_MIN, -40, 35, INT_MAX, -44, 0, 0, 0, 1, 12, -9, 14, 0, -47, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 0, 0, 0, 0, -40, INT_MIN, 0, 5, -9, 0, 0, -38, 0, -20, 0, INT_MIN, 0, 0, INT_MIN, 17, INT_MIN, INT_MAX, -17, -32, 0, -9, -37, INT_MIN, -22, INT_MIN, INT_MIN, 0, 0, 0, INT_MIN, 0, INT_MAX, 11, 0, INT_MIN, 25, INT_MAX, INT_MAX, 15, INT_MIN, -13, -35, -26, INT_MAX, INT_MIN, 0, 0, INT_MIN, 13, INT_MIN, INT_MIN, INT_MIN, 40, INT_MAX, INT_MIN, -24, INT_MIN, 0, -1, INT_MAX, -27, 14, 48, 8, -1, 27, -11, 7, -35, 0, 45, 11, INT_MAX, 0, 0, -25, INT_MAX, 0, -29, 0, INT_MIN, INT_MIN, -4, INT_MIN, -24, INT_MAX, INT_MAX, -22, INT_MIN, -44, -47, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, -41, 0, 7, INT_MIN, -23, INT_MAX, INT_MIN, 1, 45, 0, 42, INT_MAX, INT_MAX, 0, INT_MIN, INT_MIN, 50, 0, INT_MIN, -39, INT_MAX, 28, -15, 0, -30, -7, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 0, -12, -38, -13, INT_MAX, INT_MIN, 40, 0, 48, 6, INT_MIN, INT_MAX, 8, INT_MAX, 0, 0, 48, -34, -33, 0, 42, -22, -38, 0, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 21, -13, -19, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MAX, 0, -4, INT_MAX, INT_MIN, -7, 0, INT_MIN, 43, 23, 43, -42, 0, INT_MIN, INT_MAX, INT_MAX, 22, INT_MIN, 0, INT_MIN, 0, 0, INT_MAX, 8, INT_MAX, INT_MAX, -40, INT_MAX, INT_MAX, 30, -36, INT_MAX, INT_MIN, -35, INT_MAX, 0, 0, INT_MAX, INT_MIN, 0, INT_MIN, -9, INT_MAX, INT_MIN, 36, INT_MAX, 0, -4, -44, INT_MAX, INT_MIN, -42, INT_MAX, -29, INT_MAX, -40, -28, -16, INT_MAX, INT_MAX, 0, -37, INT_MAX, 0, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MIN, -49, 39, -18, 0, INT_MAX, -50, INT_MIN, 3, 22, INT_MIN, INT_MAX, 38, 42, INT_MIN, -35, 0, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MAX, -35, INT_MAX, INT_MAX, INT_MAX, 0, 0, 0, -26, 0, -21, INT_MIN, 8, -49, -6, 0, INT_MIN, INT_MIN, -17, 0, INT_MIN, -38, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MIN, -30, -34, 0, INT_MAX, -33, 0, -32, 0, INT_MIN, 41, 0, -45, INT_MIN, 8, 3, INT_MIN, 0, -42, 0, INT_MAX, INT_MAX, INT_MIN, 0, 0, -45, INT_MIN, 6, 19, -26, INT_MAX, -13, INT_MAX, INT_MAX, -2, 16, INT_MIN, INT_MIN, 0, -38, 24, INT_MIN, 16, INT_MIN, INT_MIN, 29, -9, 19, INT_MIN, INT_MAX, 6, 0, 0, 0, INT_MAX, INT_MIN, INT_MAX, INT_MAX, -17, -1, 18, 19, 13, INT_MAX, 0, -44, INT_MIN, INT_MIN, -20, -26, 39, INT_MAX, 0, 15, 0, 44, INT_MIN, 27, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 10, 0, INT_MIN, INT_MAX, 19, INT_MIN, 0, INT_MIN, 19, INT_MAX, 15, -30, -36, INT_MAX, 0, 18, INT_MAX, 0, 0, 50, 0, INT_MAX, INT_MIN, 42, INT_MAX, INT_MIN, -38, INT_MAX, 0, 10, INT_MAX, 22, -32, -48, -20, 17, -34, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 0, 13, 46, INT_MAX, -42, INT_MIN, INT_MIN, INT_MAX, 35, INT_MIN, INT_MIN, -25, INT_MAX, INT_MIN, 0, INT_MAX, -46, 0, INT_MAX, -40, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 0, INT_MIN, 26, 38, -35, 0, INT_MIN, INT_MAX, 26, 0, INT_MAX, 34, INT_MAX, 0, INT_MIN, INT_MIN, INT_MAX, -16, -9, INT_MAX, INT_MAX, -44, -11, 0, 0, -16, 46, INT_MIN, -6, INT_MAX, 0, 0, 8, INT_MAX, 50, 0, 0, 0, INT_MAX, INT_MAX, INT_MAX, 19, 17, INT_MIN, -50, INT_MIN, 12, 35, -20, -38, INT_MAX, 0, 8, INT_MIN, 29, -42, 0, -26, -17, 0, INT_MIN, -41, 33, 0, 4, INT_MIN, INT_MIN, -37, -42, INT_MAX, INT_MIN, 0, 0, -3, INT_MAX, INT_MAX, 0, 37, -3, 6, INT_MAX, 34, INT_MIN, 30, -15, -1, -14, INT_MIN, 28, 0, 23, 40, INT_MAX, 2, INT_MAX, 45, 28, INT_MAX, 0, INT_MIN, INT_MAX, 43, INT_MIN, 0, 0, INT_MIN, 39, -46, INT_MIN, 0, -29, INT_MIN, INT_MAX, 34, INT_MIN, INT_MAX, 0, 0, 8, 0, 0, INT_MAX, INT_MIN, INT_MAX, INT_MAX, 32, -38, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 0, INT_MAX, INT_MAX, INT_MIN, INT_MAX, -25, INT_MAX, 26, INT_MIN, 0, INT_MAX, INT_MAX, 0, INT_MAX, -49, INT_MIN, INT_MAX, 35, INT_MIN, INT_MIN, INT_MAX, 33, -6, -34, 35, 0, INT_MAX, 46, INT_MIN, 32, INT_MIN, 0, INT_MAX, 0, 33, 0, -25, INT_MAX, INT_MAX, INT_MIN, INT_MAX, -32, -33, INT_MIN, 21, -50, INT_MIN, 32, INT_MIN, 0, 0, -40, INT_MAX, INT_MIN, INT_MIN, 0, 0, -4, INT_MIN, 0, INT_MAX, INT_MIN, -9, INT_MIN, INT_MAX, -16, 43, INT_MAX, -8, -1, -41, 0, 8, 5, INT_MAX, INT_MAX, -8, 21, -40, -28, -42, 0, INT_MIN, -5, INT_MIN, INT_MAX, 4, 29, INT_MAX, 0, -43, 38, 4, INT_MAX, -12, 4, INT_MAX, INT_MAX, 36, 19, -21, 0, INT_MAX, -4, INT_MIN, -14, INT_MAX, INT_MAX, -15, INT_MIN, 0, -11, 0, 0, 9, INT_MAX, 0, INT_MIN, -48, INT_MAX, 0, INT_MAX, INT_MAX, -27, -1, 31, -10, 32, INT_MIN, -29, INT_MAX, -44, 0, -22, INT_MAX, INT_MIN, 12, INT_MAX, 0, -44, INT_MIN, 8, INT_MIN, 8, -7, INT_MAX, 0, 0, INT_MIN, 0, -37, 36, -43, 0, -12, -14, INT_MAX, INT_MAX, -17, 9, INT_MIN, INT_MIN, 0, 0, 36, 2, 0, -20, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 0, -7, 0, -48, -38, INT_MAX, INT_MIN, INT_MAX, INT_MAX, 5, -2, INT_MAX, 45, INT_MIN, INT_MIN, 33, INT_MIN, 0, -13, 0, INT_MAX, 47, INT_MIN, INT_MAX, 7, 0, INT_MIN, INT_MAX, 0, INT_MAX, INT_MAX, -35, INT_MIN, 0, INT_MIN, 30, INT_MIN, INT_MAX, INT_MIN, -18, 10, 41, -6, 26, INT_MIN, 0, 0, 0, 0, -31, INT_MAX, 0, INT_MIN, INT_MAX, 3, INT_MAX, INT_MIN, 0, INT_MIN, 0, INT_MIN, -35, INT_MIN, 0, 0, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MAX, -36, 0, INT_MAX, INT_MAX, INT_MAX, INT_MIN, -47, INT_MIN, 0, INT_MAX, 47, INT_MAX, INT_MIN, 46, INT_MAX, 25, 0, -20, INT_MIN, INT_MIN, INT_MIN, -43, INT_MAX, -15, 0, INT_MIN, 24, 0, INT_MIN, INT_MAX, INT_MIN, -42, -3, 40, 0, INT_MIN, INT_MIN, -46, -10, 0, 0, INT_MAX, INT_MIN, -3, 3, 0, INT_MAX, 41, 0, 0, 0, 28, 30, INT_MIN, 0, -27, -14, INT_MIN, -14, 0, INT_MAX, -27, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 34, -3, 36, -23, INT_MIN, 0, -45, 0, INT_MAX, INT_MAX, 21, -12, -15, 8, INT_MAX, INT_MIN, 32, INT_MIN, INT_MAX, 0, INT_MIN, INT_MIN, 0, INT_MAX, INT_MAX, INT_MAX, 2, INT_MIN, INT_MIN, 6, 47, INT_MIN, 0, INT_MAX, INT_MIN, INT_MIN, 0, -47, 5, INT_MIN, 0, 25, -21, INT_MIN, 2, INT_MIN, INT_MAX, 0, INT_MAX, INT_MAX, -30, 42, INT_MIN, -39, INT_MIN, 0, INT_MAX, INT_MIN, 0, 0, INT_MIN, 0, -30, 16, 34, 0, INT_MAX, 0, INT_MIN, INT_MAX, INT_MIN, 14, INT_MAX, INT_MAX, INT_MAX, 34, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MIN, -49, -24, 0, INT_MAX, INT_MAX, 0, INT_MAX, -16, INT_MAX, 0, INT_MIN, INT_MAX, INT_MIN, 34, 9, INT_MAX, 0, -31, 6, 0, INT_MAX, 0, -37, INT_MIN, INT_MAX, 0, -36, INT_MIN, -8, -8, 0, -3, -4, INT_MAX, INT_MIN, INT_MAX, 0, 50, 37, -36, -45, 0, 5, INT_MAX, 5, INT_MIN, INT_MAX, -27, INT_MAX, 26, -34, -4, 0, 1, -45, -30, INT_MAX, -11, INT_MIN, -24, -22, -48, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, INT_MIN, -39, INT_MIN, INT_MIN, -4, INT_MIN, 46, -31, -11, 14, 15, 15, INT_MAX, 0, INT_MAX, 0, -40, 0, 5, -46, INT_MIN, INT_MAX, 31, -3, INT_MIN, INT_MAX, INT_MIN, INT_MIN, 0, 47, -20, 0, -50, -17, -4, INT_MAX, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 0, -38, 23, 15, 0, INT_MAX, -21, INT_MAX, INT_MIN, 0, 22, 0, -19, -2, 20, 0, INT_MAX, INT_MIN, INT_MAX, 28, INT_MIN, INT_MIN, INT_MIN, -15, INT_MAX, -15, INT_MIN, INT_MIN, INT_MIN, INT_MIN, -46, INT_MAX, INT_MAX, INT_MIN, 0, 0, 39, -13, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 24, 9, -33, 43, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 32, INT_MAX, -50, -9, 0, 0, 0, INT_MAX, -38, 26, INT_MAX, 36, INT_MIN, -11, INT_MIN, 0, -18, INT_MAX, INT_MIN, 0, -39, -43, INT_MIN, 10, INT_MAX, INT_MAX, -50, 0, -23, -42, 4, 0, 24, INT_MAX, INT_MAX, INT_MAX, -31, 32, -46, INT_MAX, 4, 32, INT_MAX, -5, 0, 0, INT_MAX, INT_MAX, INT_MIN, 26, INT_MAX, -26, -32, 0, 0, INT_MIN, 13, INT_MAX, -1, INT_MAX, -4, 0, -2, 47, INT_MIN, 49, INT_MIN, 48, 0, 4, INT_MAX, INT_MIN, INT_MAX, 0, INT_MAX, INT_MIN, 0, 0, INT_MIN, 1, 48, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, INT_MAX, INT_MIN, 41, 10, 0, INT_MIN, INT_MIN, 0, INT_MIN, -13, INT_MIN, 39, INT_MIN, 0, INT_MIN, -36, -8, -40, 0, 0, INT_MAX, 25, 35, INT_MAX, INT_MAX, INT_MIN, 31, INT_MIN, 0, 14, INT_MAX, 5, -32, INT_MIN, 0, -1, -43, INT_MIN, 0, 0, 0, -41, -17, 46, 0, 0, INT_MIN, INT_MIN, -5, INT_MIN, 47, INT_MIN, 36, 0, 0, -29, 19, -35, INT_MIN, 50, INT_MAX, 42, 0, INT_MIN, -47, 0, -14, -38, INT_MIN, -25, 12, -42, INT_MAX, -29, 0, 0, -4, 0, INT_MIN, 0, INT_MIN, INT_MAX, 50, 42, INT_MAX, 45, 2, INT_MAX, -29, 19, INT_MIN, 0, -35, INT_MIN, INT_MAX, INT_MAX, 41, INT_MAX, 0, INT_MAX, 0, INT_MAX, INT_MIN, INT_MIN, 14, INT_MIN, 16, -48, -35, INT_MIN, 0, 38, INT_MAX, INT_MIN, 0, 0, 0, INT_MIN, 35, -33, -43, INT_MAX, 9, INT_MIN, INT_MAX, 0, -47, INT_MIN, -12, INT_MAX, INT_MIN, 0, -11, INT_MAX, -21, 2, -21, INT_MAX, -20, INT_MAX, INT_MAX, INT_MAX, 10, 42, INT_MAX, INT_MIN, INT_MIN, -9, 4, INT_MIN, INT_MAX, 0, -12, -47, INT_MAX, -20, INT_MIN, INT_MAX, INT_MAX, 26, -24, INT_MIN, 0, 0, INT_MAX, 27, -16, 0, INT_MIN, 0, -33, INT_MIN, -23, INT_MAX, -20, -41, -16, INT_MIN, 27, -23, INT_MAX, -45, -47, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, 47, -6, INT_MAX, INT_MIN, INT_MAX, -11, -13, 1, INT_MAX, 0, 21, 0, INT_MIN, INT_MIN, 0, INT_MAX, INT_MIN, 0, 21, 46, 15, -35, -28, INT_MAX, 0, 0, INT_MIN, -7, 0, INT_MIN, -33, INT_MIN, INT_MAX, -33, 30, 0, 46, 32, -18, 0, 0, 26, INT_MIN, INT_MAX, -25, INT_MAX, 45, INT_MAX, 0, 1, INT_MIN, 18, -20, INT_MAX, INT_MAX, 0, 20, INT_MIN, 10, 37, 0, 0, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MIN, 6, INT_MAX, -13, -17, 0, INT_MIN, 0, INT_MAX, -47, 9, 0, INT_MAX, INT_MIN, INT_MIN, -2, INT_MAX, 0, INT_MIN, -11, INT_MAX, -26, 46, -8, INT_MIN, 0, INT_MIN, INT_MIN, 8, INT_MAX, 0, 26, INT_MIN, INT_MIN, -28, INT_MIN, INT_MIN, INT_MAX, -21, INT_MAX, INT_MAX, 0, 0, -31, 26, INT_MIN, INT_MAX, 28, 0, -15, 34, INT_MAX, INT_MIN, 0, 0, 1, 24, 0, 0, 0, INT_MIN, 20, 0, 0, 8, INT_MAX, 27, INT_MIN, INT_MIN, 38, INT_MAX, 44, -27, INT_MAX, -24, -41, 31, 32, INT_MIN, INT_MIN, -41, 27, -41, INT_MAX, -4, -24, 0, INT_MIN, INT_MAX, 1, 12, 8, 0, INT_MIN, INT_MAX, 0, -14, 5, INT_MIN, -17, 43, INT_MIN, -12, INT_MIN, INT_MIN, INT_MAX, 0, 49, -7, INT_MIN, INT_MAX, -46, 0, -35, -9, -6, INT_MIN, 48, INT_MAX, 6, INT_MAX, INT_MIN, 22, INT_MIN, 0, INT_MIN, -45, INT_MIN, INT_MAX, INT_MAX, 0, -10, INT_MIN, INT_MIN, INT_MAX, -10, -27, 0, INT_MIN, 0, INT_MAX, 0, 0, -28, 11, INT_MAX, INT_MAX, 32, INT_MAX, 0, 26, -17, 1, INT_MIN, INT_MAX, 0, 0, 3, INT_MAX, 2, 23, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 0, INT_MIN, INT_MAX, 3, 0, 0, 0, -18, 0, INT_MAX, -19, 38, 0, 0, 0, 0, 0, 0, 0, 49, 22, INT_MAX, 44, INT_MAX, -19, -5, INT_MIN, -32, -14, -23, 19, -15, 45, INT_MAX, 0, 31, 0, 0, 0, 0, INT_MIN, 0, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, -10, INT_MAX, 0, 20, 29, 0, 0, INT_MIN, 0, 25, 18, -32, -13, -19, -35, 0, INT_MAX, 0, -49, 0, INT_MIN, -46, 0, -17, INT_MIN, 0, INT_MAX, 23, -4, INT_MIN, 0, 44, INT_MAX, 50, INT_MIN, 0, -1, 44, 17, INT_MAX, -8, INT_MIN, -48, 0, INT_MAX, INT_MIN, INT_MAX, -42, INT_MIN, 0, INT_MIN, 42, 0, 41, INT_MIN, 0, -30, INT_MAX, INT_MAX, INT_MIN, INT_MAX, 0, 0, -34, -40, INT_MIN, 0, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 0, 0, -28, -39, -20, 19, 34, -10, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, 0, INT_MAX, 49, 0, INT_MAX, INT_MAX, -10, -14, 0, 9, INT_MAX, 15, 50, INT_MIN, INT_MIN, INT_MAX, -1, INT_MAX, 0, 17, 32, 0, 21, -29, INT_MIN, -30, INT_MIN, 0, 11, INT_MAX, 48, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, -16, INT_MIN, 0, INT_MIN, INT_MIN, -11, -5, INT_MIN, 0, -41, INT_MIN, 0, INT_MIN, -9, INT_MAX, INT_MAX, 0, INT_MIN, INT_MIN, INT_MAX, -30, -22, 14, 5, 28, INT_MIN, -1, INT_MAX, 0, 23, INT_MIN, INT_MAX, 0, INT_MIN, 0, 6, 0, INT_MIN, 35, -28, INT_MAX, INT_MAX, INT_MIN, INT_MAX, -19, -1, -11, INT_MAX, 0, -43, -44, INT_MAX, 6, INT_MAX, 0, -44, INT_MAX, INT_MAX, 0, 6, INT_MAX, 32, 0, -15, 0, 37, INT_MIN, INT_MIN, 0, 49, -36, -7, 0, 0, 0, -8, 38, 42, -27, 21, INT_MIN, INT_MAX, -24, -45, INT_MIN, 25, INT_MAX, 0, -13, -13, INT_MIN, 38, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0, INT_MIN, INT_MAX, 49, INT_MIN, -31, -17, 37, 0, 30, INT_MAX, -24, INT_MAX, -45, 0, 28, INT_MAX, INT_MIN, 24, INT_MIN, -4, INT_MIN, 0, INT_MIN, INT_MAX, -26, INT_MIN, 37, 0, INT_MIN, -4, -39, INT_MIN, INT_MIN, 0, INT_MIN, 0, INT_MIN, INT_MAX, 1, 0, INT_MAX, INT_MIN, -20, -27, 35, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, 23, INT_MIN, INT_MIN, INT_MIN, -8, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MIN, -40, 42, -43, -27, 8, 34, INT_MAX, INT_MAX, INT_MIN, 0, INT_MAX, 22, 0, INT_MIN, -22, INT_MAX, 0, 43, INT_MIN, 0, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 0, INT_MIN, -17, 6, INT_MAX, INT_MAX, -36, INT_MIN, -23, 0, 0, INT_MIN, 13, 0, -41, INT_MAX, 0, INT_MAX, 28, INT_MAX, -28, INT_MAX, INT_MIN, 0, INT_MIN, -18, 6, 0, 0, INT_MAX, -39, 0, 32, INT_MIN, -39, -31, INT_MAX, 11, 0, 48, -25, INT_MAX, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 0, INT_MIN, 30, INT_MIN, INT_MAX, -18, INT_MAX, 0, 0, INT_MAX, INT_MAX, -9, INT_MIN, INT_MIN, 0, INT_MAX, 19, INT_MIN, -40, INT_MIN, 0, 0, INT_MIN, 0, INT_MAX, -14, 46, INT_MIN, INT_MIN, INT_MIN, INT_MIN, -3, -33, INT_MIN, -2, -24, INT_MAX, 29, 0, 0, 19, 40, INT_MIN, 48, INT_MAX, -9, -4, INT_MIN, INT_MAX, INT_MAX, -47, -4, -22, -27, 35, 13, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, INT_MIN, -10, INT_MIN, INT_MAX, 0, -41, 3, INT_MAX, -14, INT_MAX, 0, 0, 0, INT_MAX, 47, INT_MIN, 24, 23, 36, 0, INT_MAX, 40, INT_MAX, -17, INT_MAX, -43, INT_MIN, -18, INT_MAX, 0, INT_MAX, 0, 0, 1, INT_MIN, INT_MIN, 23, INT_MAX, 0, -33, 0, 25, 21, 14, INT_MIN, 0, INT_MAX, -23, 31, -29, 11, 0, INT_MAX, INT_MIN, 3, INT_MIN, INT_MAX, INT_MIN, 0, 22, INT_MAX, INT_MIN, 0, -17, 0, -45, 0, INT_MAX, 5, INT_MIN, INT_MIN, -48, 31, INT_MAX, INT_MAX, 0, INT_MAX, 0, -13, INT_MAX, INT_MAX, 0, INT_MAX, 46, INT_MAX, 0, 38, INT_MIN, 16, 0, -21, -33, INT_MIN, 0, INT_MAX, INT_MAX, 0, INT_MIN, 0, INT_MAX, -35, INT_MIN, 0, 40, INT_MIN, 37, INT_MAX, 0, INT_MIN, -10, 32, 47, INT_MIN, INT_MAX, INT_MIN, INT_MAX, -12, 3, -20, INT_MIN, INT_MAX, 0, 0, -15, 47, 0, 0, INT_MIN, INT_MIN, 42, 10, 0, -49, INT_MIN, -26, 0, 0, 0, 19, INT_MAX, 28, INT_MIN, 0, -3, -33, INT_MIN, 0, -1, INT_MAX, INT_MAX, 30, INT_MAX, INT_MIN, 45, INT_MAX, -23, INT_MAX, INT_MIN, 13, INT_MAX, INT_MIN, -19, INT_MAX, INT_MAX, INT_MIN, 0, 0, INT_MIN, 25, 0, -30, INT_MIN, 18, INT_MAX, 2, -35, INT_MAX, -26, INT_MIN, -4, -28, -10, 0, 0, 28, -28, 0, 0, -49, 0, INT_MIN, INT_MIN, INT_MAX, -44, 0, -38, INT_MAX, 0, 6, INT_MIN, INT_MAX, INT_MIN, 18, 0, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MAX, 29, INT_MAX, INT_MAX, 0, INT_MAX, 0, -49, INT_MIN, -48, INT_MAX, INT_MAX, 16, 27, INT_MIN, -27, 0, INT_MAX, 8, 0, 0, 0, -35, 0, 0, INT_MIN, INT_MIN, -48, INT_MIN, INT_MAX, -22, 31, INT_MIN, 0, INT_MIN, INT_MAX, INT_MAX, 20, 0, INT_MIN, INT_MIN, -34, INT_MAX, 0, INT_MAX, 0, 43, -34, -44, -28, 13, 19, -26, -20, 0, INT_MIN, INT_MIN, INT_MIN, INT_MAX, -1, -16, 0, -31, INT_MAX, INT_MAX, INT_MAX, 0, -48, 4, INT_MIN, INT_MIN, 50, 15, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, -40, INT_MIN, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MAX, INT_MIN, -42, 0, INT_MAX, 0, 30, 7, INT_MAX, -17, 29, 0, 0, 0, 0, -33, INT_MAX, -1, 35, INT_MIN, 0, -7, -6, INT_MAX, INT_MAX, -16, 47, 13, -31, -17, INT_MAX, 5, INT_MAX, INT_MAX, -13, 20, -7, -18, 34, -17, -29, 0, 0, 0, -23, 18, INT_MAX, INT_MIN, 22, 0, -41, INT_MIN, -14, 0, INT_MAX, 34, 29, -1, -39, 26, 0, INT_MAX, INT_MIN, INT_MAX, -22, INT_MAX, -49, INT_MAX, 31, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 0, INT_MIN, 13, 0, -5, 0, INT_MAX, -24, 0, 32, -10, 0, INT_MAX, -44, INT_MIN, -14, INT_MAX, 23, 0, -2, INT_MIN, 0, -21, -19, INT_MIN, 33, 15, INT_MAX, 31, 0, 36, INT_MAX, -50, 0, 0, -31, INT_MIN, INT_MIN, INT_MIN, -2, 0, -21, 12, -5, 32, -1, 33, INT_MAX, INT_MIN, INT_MIN, 0, -35, INT_MAX, 0, 0, 0, 10, INT_MIN, INT_MAX, -18, INT_MAX, 0, INT_MIN, INT_MAX, 0, 0, 9, 0, 0, INT_MAX, -9, INT_MIN, 0, 0, INT_MAX, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, 0, 40, 0, 1, 0, 0, -5, INT_MAX, 9, -35, 39, INT_MIN, 0, INT_MAX, INT_MAX, INT_MIN, -7, -13, -31, -7, -7, INT_MIN, INT_MAX, INT_MIN, -45, 0, INT_MAX, INT_MIN, INT_MAX, 0, INT_MIN, 30, INT_MIN, -21, INT_MIN, 0, -1, INT_MIN, 0, -8, 20, INT_MIN, 40, 4, INT_MAX, INT_MIN, 0, 27, INT_MIN, -49, INT_MIN, -8, -3, -50, INT_MIN, 38, INT_MAX, 0, -19, -32, 0, 0, 15, INT_MAX, INT_MAX, INT_MIN, INT_MAX, 0, INT_MAX, INT_MAX, -39, INT_MIN, 0, -2, INT_MIN, 25, INT_MAX, INT_MIN, 0, 0, 49, 0, 17, INT_MIN, 0, 0, -31, -29, 14, -26, 0, INT_MIN, INT_MAX, 0, 38, 50, -3, 21, INT_MAX, 2, INT_MAX, INT_MIN, 24, 23, INT_MIN, -6, INT_MIN, INT_MAX, -6, INT_MAX, 13, INT_MAX, 24, -7, 49, INT_MAX, 0, -27, INT_MIN, INT_MAX, -30, INT_MAX, -9, INT_MIN, -2, INT_MIN, 0, INT_MIN, INT_MAX, -47, INT_MIN, 0, INT_MAX, INT_MIN, 0, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 43, 36, INT_MAX, 0, 24, 21, 0, 22, 0, -39, 0, 49, INT_MAX, 0, INT_MAX, 45, INT_MAX, -8, 0, INT_MAX, INT_MAX, 37, 28, -45, 0, 0, -41, 14, 23, INT_MIN, 38, INT_MIN, INT_MAX, INT_MAX, -41, -32, -31, INT_MAX, INT_MIN, 0, INT_MIN, INT_MIN, INT_MIN, 42, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 0, -32, 21, 0, -50, -13, 0, 0, INT_MAX, 0, 30, INT_MAX, 48, 0, 0, -22, 30, INT_MAX, 0, -1, 37, INT_MIN, -30, INT_MAX, INT_MIN, 18, INT_MAX, 0, 46, 0, -50, -27, 0, INT_MIN, INT_MIN, 0, 11, 0, INT_MIN, 34, INT_MAX, -16, 43, 10, INT_MAX, 47, INT_MIN, INT_MIN, INT_MAX, 7, 0, -30, INT_MAX, 5, 0, 3, INT_MIN, 0, -22, 0, 0, INT_MIN, 46, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 37, -18, -41, 26, -3, INT_MIN, 4, -29, -34, INT_MIN, -32, -18, 43, -12, INT_MAX, -47, 0, INT_MAX, 0, 44, INT_MIN, 0, INT_MAX, INT_MIN, -16, INT_MAX, 0, 0, INT_MIN, 27, 4, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 16, INT_MIN, INT_MIN, 38, 44, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, -9, INT_MAX, INT_MIN, -45, INT_MIN, 35 };


static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";  

static char genRandom() { return alphanum[rand() % (sizeof(alphanum) - 1)]; }

static string_code hashit (std::string const& inString) {
    if (inString == "int" || inString == "long") return eint;
    if (inString == "unsigned") return euint;
    if (inString == "long long") return ellong;
    if (inString == "float") return efloat;
    if (inString == "char") return echar;
    if (inString == "char*") return estring;
}

void* blt_args::get_arg(std::string const& arg_type) {
  switch (hashit(arg_type)) {
    case eint:
      return (void*) &ints[intCnt++];
    default:
      printf("Error: Argument generator required\n");
      exit(1);
  }
}

/*
void* blt_args::get_arg(std::string const& arg_type) {
  void* ret;
  switch (hashit(arg_type)) {
    case eint: {
      int ints[5];
        ints[0] = rand() % 50;
        ints[1] = -1*(rand() % 50);
        ints[2] = INT_MAX;
	// TL Note: For now so when -2147483648 is put in replay file
	// the compiler doesn't yell
        ints[3] = INT_MIN+1;
        ints[4] = 0;
      int* ret = new int[1];
      // TL for now
      ret[0] = ints[2];
      //      ret[0] = ints[rand() / (RAND_MAX/5)];

      return (void*)ret;
    }
    case euint: {
      unsigned uints[3];
        uints[0] = rand() % UINT_MAX;
        uints[1] = UINT_MAX;
        uints[2] = 0;
      unsigned* ret = new unsigned[1];
      ret[0] = uints[rand() / (RAND_MAX/3)];
      return (void*) ret;
    }
    case ellong: {
      long long llongs[5];
        llongs[0] = rand() % LLONG_MAX;
        llongs[1] = -1*(rand() % LLONG_MAX);
        llongs[2] = LLONG_MAX;
        llongs[3] = LLONG_MIN;
        llongs[4] = 0;
      long long* ret = new long long[1];
      ret[0] = llongs[rand() / (RAND_MAX/5)];
      return (void*) ret;
    }
    case efloat: {
      float floats[5];
        floats[0] = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(FLT_MAX)));
        floats[1] = FLT_MIN + static_cast <float> (rand()) * FLT_MAX;
        floats[2] = FLT_MAX;
        floats[3] = FLT_MIN; 
        floats[4] = 0;
      float* ret = new float[1];
      ret[0] = floats[rand() / (RAND_MAX/5)];
      return (void*) ret;
    }
    case echar: {
      char chars[5];
        chars[0] = rand() % CHAR_MAX;
        chars[1] = -1*(rand() % CHAR_MAX);
        chars[2] = ' ';
        chars[3] = CHAR_MAX;
        chars[4] = CHAR_MIN;
      char* ret = new char[1];
      ret[0] = chars[rand() / (RAND_MAX/5)];
      return (void*) ret; 
    }
    case estring: {
      char* strings[3];
        strings[0] = NULL;
        strings[1] = (char*)"";
        unsigned r = rand() % CHAR_MAX;
        strings[2] = (char*) malloc(sizeof(char) * r);
        for(unsigned i = 0; i < r; ++i)
            strings[2][i] = genRandom();
        strings[2][r] = 0;
      char** ret = new char*[1];
      ret[0] = strings[rand() / (RAND_MAX/3)];
      return (void*) ret; 
    }
    default:
      printf("Error: Argument generator required\n");
      exit(1);
  }
}
*/
