

#include "/home/tslilyai/blt/blt_args.hpp"
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <string>

unsigned intCnt = 0;
int ints [] = { INT_MAX, INT_MAX, 0, -43, INT_MAX, 0, INT_MIN, INT_MAX, -46, INT_MIN, INT_MAX, -44, INT_MAX, 8, 0, INT_MIN, INT_MIN, INT_MAX, 0, -42, INT_MAX, 25, 0, 20, INT_MAX, 40, 0, INT_MAX, -41, 0, INT_MIN, 39, 0, 0, 0, 37, -8, 42, 2, -5, INT_MAX, INT_MAX, 0, INT_MAX, 0, INT_MIN, 0, INT_MIN, 0, 0, 0, INT_MIN, INT_MIN, 9, -48, -31, -49, -43, 0, -32, INT_MIN, 21, 18, -48, 26, -15, 14, 0, 0, 44, -39, 0, 32, INT_MAX, INT_MIN, 0, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 0, 1, INT_MIN, 0, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 0, INT_MAX, -19, 0, 0, 0, 19, INT_MAX, -36, INT_MIN, -21, 0, 0, INT_MIN, 31, INT_MAX, -8, 0, 0, 47, 0, INT_MIN, 0, 0, -4, 0, INT_MAX, -6, INT_MAX, -45, -33, -12, INT_MAX, INT_MAX, INT_MAX, 0, INT_MIN, INT_MIN, INT_MAX, INT_MAX, -32, -42, INT_MIN, INT_MAX, 48, -4, -50, INT_MAX, INT_MAX, 27, 45, INT_MIN, INT_MIN, -19, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MAX, -17, -20, 8, 0, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 44, -1, INT_MIN, INT_MIN, 44, INT_MAX, -11, INT_MIN, -34, 0, 14, -33, 0, INT_MIN, 0, INT_MIN, 0, INT_MAX, 9, -29, -18, INT_MIN, -15, INT_MAX, 0, 0, -20, -38, 0, -32, 13, 49, INT_MAX, -3, 12, 31, 0, -37, INT_MAX, INT_MIN, 47, 26, 8, 41, -46, INT_MIN, INT_MIN, 0, INT_MIN, 0, 41, INT_MAX, 0, 0, 0, 0, INT_MIN, INT_MAX, 39, INT_MAX, 21, INT_MAX, INT_MIN, -50, 7, 0, -45, 0, -7, 28, INT_MIN, INT_MAX, INT_MAX, -43, -13, 0, 48, 0, 0, INT_MAX, INT_MIN, INT_MAX, -8, INT_MIN, -28, 44, -40, -43, INT_MIN, 0, -36, 0, INT_MAX, INT_MIN, INT_MIN, INT_MIN, -20, -14, INT_MIN, -32, INT_MAX, -17, INT_MAX, 0, 26, INT_MAX, -35, -37, INT_MAX, -31, INT_MAX, INT_MIN, -46, INT_MIN, 7, INT_MIN, 0, 10, INT_MIN, INT_MIN, INT_MIN, 20, INT_MIN, 0, -6, 0, 0, 0, 0, INT_MAX, -18, INT_MAX, 32, -22, -16, INT_MIN, 0, INT_MIN, 0, 0, 9, 49, 8, 0, 0, INT_MAX, 8, -40, 49, INT_MIN, -47, 32, 0, INT_MAX, INT_MIN, 0, INT_MIN, INT_MIN, INT_MAX, -9, 40, 20, 0, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 0, 37, 13, 0, INT_MAX, INT_MIN, 5, 2, 17, INT_MIN, 23, INT_MAX, 0, 0, INT_MAX, INT_MIN, 0, -41, INT_MAX, INT_MIN, 42, INT_MIN, -28, INT_MIN, 22, INT_MAX, 5, -49, 0, -40, INT_MAX, 22, -6, INT_MIN, 0, 1, 0, -25, INT_MIN, 5, -5, 33, INT_MAX, 0, INT_MIN, 15, 0, 7, -18, -46, 2, 36, 0, INT_MAX, 21, INT_MAX, -40, -15, INT_MIN, 17, 25, 0, INT_MAX, 1, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 0, 0, -28, -4, 0, 18, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, INT_MIN, 45, 0, INT_MIN, 0, 26, 9, -39, 0, INT_MAX, 44, INT_MIN, 0, 0, INT_MAX, -43, -46, INT_MIN, -15, 45, 0, INT_MIN, 0, INT_MIN, INT_MIN, 24, -43, 15, -10, 5, INT_MIN, INT_MIN, 2, 35, -47, 48, INT_MAX, INT_MIN, -44, 10, -15, 0, -7, INT_MAX, 0, 0, 41, 0, 0, -25, 26, 0, 0, 19, INT_MIN, INT_MAX, -19, 0, 0, -12, -2, -45, -7, -10, -5, 29, INT_MIN, INT_MAX, 0, 18, -46, 49, INT_MAX, INT_MIN, INT_MIN, -47, -50, 38, INT_MAX, INT_MIN, 0, 29, INT_MAX, 28, INT_MAX, INT_MIN, 36, 47, INT_MIN, -24, INT_MIN, INT_MAX, 22, 44, 0, INT_MAX, 14, -20, -45, INT_MAX, INT_MAX, 0, 0, INT_MAX, INT_MAX, 44, 0, 44, 24, 0, 0, 0, -20, INT_MIN, 50, -29, 17, 0, 34, INT_MIN, INT_MAX, INT_MAX, -21, INT_MIN, INT_MAX, INT_MIN, 0, INT_MAX, 0, INT_MAX, -38, INT_MAX, INT_MAX, 32, INT_MAX, INT_MAX, INT_MAX, 10, 18, 0, INT_MIN, -36, 0, INT_MIN, -24, INT_MIN, 15, INT_MAX, 0, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 33, INT_MAX, 0, 48, 7, INT_MAX, -17, INT_MIN, INT_MIN, 0, -33, INT_MAX, 39, -18, 10, INT_MAX, 0, INT_MIN, INT_MIN, -44, INT_MIN, 6, 26, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 0, 16, INT_MIN, -14, 2, 0, 0, 1, INT_MAX, -3, INT_MIN, 34, -17, 28, -24, INT_MAX, 25, INT_MIN, 25, INT_MAX, 42, -32, INT_MAX, -44, INT_MIN, 34, 47, INT_MIN, 29, 24, INT_MIN, 0, -38, -1, -28, -13, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 3, -50, INT_MIN, INT_MIN, -50, INT_MIN, INT_MAX, 0, INT_MIN, 0, 35, INT_MAX, 24, 0, INT_MIN, INT_MAX, 0, 3, INT_MAX, 0, 0, INT_MIN, -8, INT_MAX, INT_MIN, INT_MAX, -45, 0, 25, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 0, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 0, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 13, INT_MAX, 0, 28, 0, -20, -28, INT_MIN, 8, 23, INT_MAX, 15, INT_MIN, INT_MIN, 0, 26, -17, 48, 45, -46, 0, INT_MAX, -37, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 36, 49, INT_MAX, 17, 0, INT_MAX, INT_MIN, 6, 22, INT_MAX, 0, INT_MIN, 47, INT_MIN, INT_MIN, INT_MIN, 0, INT_MIN, 47, -38, -30, INT_MIN, 31, 0, 2, INT_MAX, -49, 0, -3, -2, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, 0, 36, 0, INT_MAX, -20, 13, INT_MAX, 0, INT_MAX, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, INT_MAX, INT_MIN, 20, 0, -30, -36, 41, 0, 40, 35, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, -13, INT_MAX, INT_MAX, -8, INT_MIN, 39, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 15, 29, INT_MAX, INT_MIN, INT_MAX, -24, INT_MIN, INT_MIN, 14, -22, -10, INT_MAX, 0, 49, INT_MIN, INT_MIN, 38, INT_MIN, 0, INT_MAX, -10, 13, 0, 0, -24, -19, -25, 0, INT_MIN, INT_MAX, -17, INT_MAX, INT_MAX, 39, 47, 41, 1, 44, -21, 0, -38, -36, INT_MAX, INT_MAX, -39, 13, -34, INT_MAX, 13, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 3, INT_MAX, INT_MIN, 0, 0, INT_MIN, -4, INT_MAX, 0, -28, 30, INT_MIN, INT_MIN, 0, -47, 0, INT_MAX, INT_MIN, INT_MIN, -8, 48, INT_MIN, INT_MIN, INT_MAX, INT_MIN, 4, 31, 0, INT_MAX, 42, 0, -28, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 44, 0, 20, INT_MIN, INT_MIN, 0, 30, INT_MIN, 29, -24, INT_MAX, INT_MAX, INT_MAX, -3, 10, 18, 17, 0, -6, -6, 0, INT_MAX, INT_MIN, INT_MAX, 13, INT_MAX, 0, INT_MAX, 15, 0, INT_MIN, INT_MAX, INT_MAX, 0, INT_MIN, INT_MAX, -43, -24, INT_MIN, INT_MIN, 0, INT_MAX, -24, -20, 0, 5, 49, 33, -25, INT_MAX, 0, INT_MIN, -46, INT_MAX, 19, INT_MIN, 0, 12, INT_MAX, 31, INT_MIN, INT_MIN, INT_MAX, INT_MAX, -46, -14, 0, 31, 13, INT_MAX, 38, 0, INT_MIN, -5, -25, -10, 0, 0, 0, INT_MAX, -11, INT_MAX, 5, INT_MIN, INT_MIN, INT_MAX, -19, -21, INT_MAX, -34, 17, 41, 0, -35, 5, -19, INT_MAX, INT_MIN, INT_MAX, 12, 0, INT_MIN, 0, -44, 0, 45, INT_MIN, 2, INT_MAX, 0, -30, 0, 0, 21, INT_MAX, -46, INT_MIN, INT_MAX, INT_MAX, 49, -26, INT_MAX, INT_MAX, 16, INT_MAX, INT_MAX, INT_MIN, INT_MAX, 0, INT_MAX, -50, INT_MIN, 0, 0, 0, INT_MAX, INT_MIN, -23, 37, INT_MIN, 0, INT_MAX, -21, INT_MIN, 0, 0, 2, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 9, 0, 0, 33, 0, -3, INT_MIN, INT_MIN, INT_MIN, -45, 31, INT_MIN, INT_MAX, 27, 31, -2, 0, -1, 13, 0, 3, INT_MAX, 0, INT_MAX, 6, INT_MIN, -17, -17, 17, 7, INT_MIN, 0, INT_MAX, 40, INT_MIN, INT_MIN, -47, INT_MIN, 0, 0, 9, INT_MIN, INT_MAX, INT_MIN, -34, INT_MAX, INT_MIN, -36, INT_MIN, -31, INT_MAX, -29, INT_MAX, 44, 21, 0, INT_MIN, INT_MIN, 19, 28, INT_MAX, 0, INT_MIN, 15, 0, -42, INT_MAX, 43, -37, 36, 39, -10, 1, 0, INT_MIN, -30, INT_MIN, -30, INT_MIN, INT_MIN, 2, -49, -7, INT_MIN, INT_MAX, 0, INT_MIN, -49, INT_MIN, 37, INT_MIN, -19, INT_MAX, INT_MIN, INT_MIN, 0, 44, -44, -14, -7, -20, 0, INT_MIN, INT_MAX, -20, 50, 18, INT_MAX, INT_MAX, 47, 0, INT_MIN, INT_MAX, 20, INT_MAX, 0, -38, -41, 50, INT_MIN, 45, 0, 0, 14, 31, 0, INT_MAX, INT_MAX, 0, 0, -2, 0, INT_MIN, INT_MAX, INT_MAX, 0, INT_MIN, 3, INT_MAX, 0, 31, INT_MIN, -48, INT_MIN, 38, INT_MIN, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, -50, INT_MIN, 0, 24, -50, -37, -9, 0, 0, 0, 0, 0, -27, -25, 6, 34, 0, INT_MIN, INT_MIN, 0, 47, INT_MIN, INT_MIN, 25, 0, 0, 0, 0, INT_MIN, INT_MIN, 0, 0, INT_MIN, 1, 5, INT_MIN, -17, 0, INT_MIN, INT_MAX, -2, -8, INT_MAX, 45, -50, 0, 50, -47, -41, 4, 0, 41, INT_MIN, 0, INT_MIN, INT_MAX, INT_MAX, 0, -5, -41, INT_MAX, -28, 0, INT_MIN, 0, INT_MIN, INT_MAX, 31, 45, INT_MIN, 0, -3, 0, 0, 0, INT_MIN, -44, 8, -16, INT_MAX, -35, -18, INT_MAX, 0, INT_MIN, 0, 0, 29, -8, INT_MAX, 31, -40, 0, 27, INT_MIN, -9, 28, 5, INT_MIN, INT_MAX, -18, 0, INT_MIN, -33, -20, INT_MIN, 49, -29, 0, -6, INT_MIN, -23, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MAX, -17, INT_MAX, INT_MIN, 39, 0, 0, -43, 0, 0, 0, 0, 0, 21, 0, INT_MIN, 23, 18, INT_MIN, -31, INT_MIN, INT_MIN, 0, 4, -26, -6, 34, 0, INT_MAX, INT_MIN, INT_MAX, -41, 0, 0, INT_MAX, INT_MAX, 0, INT_MAX, 0, 0, INT_MAX, INT_MAX, -36, 15, INT_MIN, 0, INT_MAX, 19, -13, INT_MAX, INT_MAX, 11, INT_MAX, INT_MIN, 24, INT_MAX, 0, 0, -23, 10, 20, -16, INT_MAX, INT_MAX, 11, 0, -36, INT_MIN, INT_MAX, 36, 0, -32, -48, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 47, INT_MIN, 0, 7, INT_MAX, INT_MIN, INT_MAX, INT_MIN, -14, -19, INT_MIN, -47, 0, 0, INT_MAX, INT_MIN, 0, INT_MAX, 0, 27, 0, -41, 34, 0, 0, INT_MIN, INT_MAX, INT_MAX, INT_MAX, -5, INT_MAX, 0, INT_MAX, 0, 7, -49, INT_MAX, INT_MIN, INT_MIN, INT_MIN, -44, INT_MAX, 25, 48, INT_MIN, INT_MIN, INT_MAX, INT_MAX, -29, INT_MIN, -33, 2, -37, 0, 29, INT_MIN, -48, -15, INT_MIN, -30, 5, 0, -16, INT_MIN, INT_MAX, 36, 8, -49, 44, 24, -34, 0, INT_MAX, 0, INT_MIN, 12, 22, 0, -16, 18, INT_MIN, 0, 30, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, INT_MAX, INT_MIN, -4, INT_MIN, -23, 31, 0, 0, 0, INT_MAX, 37, -19, INT_MAX, 35, -3, 45, 44, 0, 0, INT_MIN, INT_MAX, 33, INT_MAX, 16, -41, INT_MIN, -29, 0, 21, 0, -4, INT_MIN, -50, -42, 2, INT_MIN, 0, INT_MAX, INT_MIN, 17, INT_MAX, 20, 0, -28, 22, 0, INT_MIN, 35, INT_MIN, 24, INT_MIN, 50, -37, 45, INT_MIN, INT_MAX, INT_MIN, -45, 0, 0, -34, INT_MIN, INT_MIN, 0, -37, 0, 0, 0, 44, 48, INT_MAX, INT_MAX, 0, INT_MIN, 19, 43, INT_MIN, INT_MIN, -42, INT_MAX, INT_MIN, INT_MIN, -29, 28, 11, 0, INT_MIN, INT_MIN, INT_MAX, INT_MIN, -14, INT_MIN, 0, INT_MIN, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MIN, 0, -7, 0, INT_MAX, 0, INT_MIN, INT_MAX, 36, INT_MAX, 0, INT_MIN, 0, 0, INT_MIN, -33, INT_MIN, INT_MAX, 0, -19, INT_MIN, -22, 17, 0, INT_MIN, -50, INT_MAX, -10, INT_MAX, INT_MAX, -42, 0, 43, 34, -26, INT_MIN, INT_MIN, INT_MAX, 0, 2, INT_MAX, 0, 46, 48, INT_MAX, -22, -4, INT_MAX, -23, 6, INT_MIN, INT_MIN, 0, 15, 0, -48, INT_MIN, -7, INT_MIN, INT_MAX, 0, INT_MIN, INT_MIN, 0, INT_MIN, -31, 0, INT_MAX, INT_MAX, 30, -9, INT_MIN, INT_MAX, 47, -30, INT_MIN, -6, 8, INT_MAX, 0, 8, -28, 0, INT_MIN, 0, INT_MIN, 0, -3, 18, -38, INT_MAX, INT_MIN, 41, 0, INT_MIN, 0, -21, INT_MIN, 0, INT_MIN, 28, 33, INT_MAX, 0, 2, INT_MAX, -31, -37, 0, INT_MIN, 0, INT_MIN, INT_MAX, -47, 0, INT_MIN, -50, -20, INT_MIN, 23, INT_MAX, -34, -20, INT_MIN, 0, INT_MAX, INT_MAX, -24, INT_MAX, INT_MIN, 0, 0, INT_MAX, -14, -42, 0, INT_MAX, 0, 29, 25, 18, INT_MIN, INT_MIN, 0, 0, INT_MIN, -35, INT_MIN, -4, -1, INT_MAX, 0, INT_MAX, 30, 42, INT_MIN, -7, 0, 38, INT_MAX, INT_MAX, 0, INT_MIN, INT_MAX, INT_MIN, 41, -37, 31, 0, 11, INT_MIN, INT_MIN, 45, 0, 0, -42, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 30, INT_MIN, -41, -7, -16, 47, -16, -47, INT_MAX, INT_MIN, INT_MAX, INT_MAX, 42, INT_MAX, INT_MIN, 0, INT_MAX, -34, 3, 0, -41, 35, 49, -28, -24, -40, 0, INT_MIN, 50, -30, -31, INT_MAX, 16, INT_MAX, -27, INT_MAX, 0, 0, INT_MAX, 14, INT_MAX, INT_MAX, -8, INT_MIN, INT_MIN, 0, 0, 0, INT_MAX, 0, 0, INT_MIN, 0, INT_MAX, 43, 32, INT_MAX, 0, INT_MIN, INT_MIN, 42, INT_MIN, INT_MIN, INT_MIN, 27, -6, 0, INT_MAX, 43, 43, INT_MIN, 0, INT_MAX, 0, INT_MAX, 23, INT_MIN, 26, -27, INT_MAX, 38, 47, INT_MIN, 0, -50, INT_MAX, 47, INT_MIN, INT_MIN, -45, 42, -3, INT_MIN, -40, 37, INT_MIN, -29, -48, INT_MIN, 0, INT_MIN, 0, INT_MAX, -28, 0, -46, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MIN, 0, INT_MAX, -16, 14, -1, -26, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 19, -38, -33, INT_MAX, INT_MIN, INT_MAX, -42, INT_MIN, -33, INT_MIN, INT_MIN, INT_MIN, INT_MIN, -1, -48, INT_MIN, INT_MIN, INT_MIN, 47, INT_MIN, INT_MIN, INT_MAX, INT_MIN, -19, 32, -28, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 37, INT_MIN, 0, INT_MIN, INT_MAX, 0, INT_MIN, -44, INT_MAX, -6, 28, INT_MIN, 0, INT_MAX, INT_MIN, 15, INT_MAX, 6, 20, 49, 27, INT_MAX, INT_MIN, 0, 28, -6, 14, 0, INT_MAX, 0, 41, 0, 0, INT_MAX, INT_MAX, INT_MAX, 40, 30, 0, 0, INT_MAX, 0, -48, -4, -42, 10, 0, 33, 44, -9, 23, 0, INT_MIN, INT_MIN, 0, 0, -7, INT_MIN, -34, -28, -17, INT_MIN, INT_MIN, INT_MAX, -2, 0, 0, INT_MAX, 16, INT_MAX, 0, INT_MIN, 0, 48, 0, 0, INT_MAX, INT_MIN, INT_MAX, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 46, 28, INT_MIN, INT_MIN, 0, INT_MIN, INT_MAX, -44, INT_MIN, INT_MIN, -43, -33, INT_MAX, 42, 12, -14, INT_MAX, 0, -26, INT_MAX, -28, 30, -2, INT_MAX, INT_MIN, -30, 6, 0, 29, -27, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 33, INT_MIN, -15, INT_MAX, 30, -25, INT_MAX, INT_MAX, INT_MIN, 24, INT_MIN, INT_MAX, INT_MIN, 48, 0, -44, 0, INT_MIN, -21, 0, 33, 2, INT_MAX, INT_MIN, 50, 0, INT_MAX, -36, INT_MAX, -27, -17, INT_MAX, 0, -6, 9, INT_MIN, -39, -20, 31, INT_MAX, -32, -27, INT_MIN, 0, 0, INT_MAX, 0, -32, 4, 0, INT_MIN, 0, -9, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0, INT_MAX, 28, INT_MIN, INT_MAX, -49, INT_MIN, 0, -35, 4, INT_MIN, -45, 3, INT_MAX, -21, INT_MIN, INT_MIN, 0, INT_MIN, INT_MAX, INT_MAX, -10, -36, -37, INT_MAX, INT_MAX, 49, 0, -15, 35, 33, -23, INT_MIN, -43, 11, INT_MIN, -19, 0, 48, INT_MAX, 48, 19, 19, INT_MIN, INT_MAX, INT_MAX, INT_MIN, 35, INT_MAX, 0, -32, 25, INT_MIN, 3, -10, INT_MIN, 0, 16, -4, INT_MAX, INT_MIN, 0, INT_MAX, -7, INT_MAX, 0, -10, INT_MAX, INT_MIN, 8, INT_MAX, -50, 1, 0, INT_MAX, 0, 47, 0, INT_MIN, -8, INT_MAX, -33, INT_MAX, -6, -23, -23, INT_MIN, -16, 37, -31, -33, -7, 0, INT_MAX, INT_MAX, INT_MAX, 0, 0, 34, INT_MAX, 21, 0, INT_MAX, 48, INT_MIN, -22, INT_MIN, -39, INT_MAX, 0, 0, 0, INT_MAX, INT_MAX, 0, 45, -7, 6, 0, 47, INT_MIN, INT_MIN, INT_MIN, 17, INT_MAX, 16, -43, INT_MIN, -19, INT_MIN, 43, 10, 0, -18, INT_MIN, 0, INT_MIN, -27, 0, -28, 21, INT_MIN, 30, INT_MIN, INT_MAX, INT_MAX, -9, 23, INT_MIN, 0, INT_MIN, INT_MAX, INT_MIN, 11, 0, 27, INT_MIN, INT_MAX, 29, 17, INT_MIN, INT_MIN, INT_MIN, -15, INT_MAX, 0, -2, INT_MIN, INT_MIN, 0, -15, INT_MAX, -17, 0, 20, INT_MAX, INT_MAX, -47, -20, INT_MAX, INT_MIN, -50, -14, 1, -34, 0, 40, INT_MAX, 34, 0, 0, INT_MIN, 0, INT_MAX, 22, INT_MIN, 0, 21, INT_MAX, -37, 0, INT_MIN, 0, -13, 0, INT_MAX, INT_MAX, -5, 24, -41, -43, INT_MAX, INT_MAX, -11, 34, 0, 8, INT_MAX, 26, 0, 19, INT_MAX, 6, -47, 0, INT_MAX, INT_MAX, 7, -9, INT_MIN, INT_MIN, -36, INT_MIN, INT_MIN, INT_MAX, 49, 1, INT_MAX, 7, INT_MIN, 5, 33, 45, 12, 44, 0, -12, INT_MIN, INT_MAX, -23, -6, INT_MAX, INT_MAX, INT_MAX, 49, INT_MIN, 0, INT_MIN, 18, 0, INT_MAX, -1, 0, INT_MAX, INT_MAX, INT_MIN, 33, 0, -34, INT_MAX, 0, INT_MIN, 38, INT_MIN, 47, 0, 0, 39, INT_MIN, -5, -20, 0, -45, 26, 0, INT_MAX, INT_MIN, -26, 0, -25, INT_MIN, 0, INT_MAX, INT_MIN, 1, -40, INT_MAX, INT_MIN, INT_MAX, 39, INT_MIN, INT_MAX, -38, INT_MIN, 0, INT_MAX, INT_MAX, 28, INT_MIN, INT_MAX, 0, 35, 0, -37, -26, -21, -49, INT_MIN, INT_MIN, INT_MAX, 39, 26, 40, 0, -16, 0, -48, INT_MAX, 28, INT_MIN, -4, -26, INT_MIN, INT_MIN, 0, 15, 38, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, INT_MAX, 0, 6, INT_MAX, 0, INT_MAX, 0, 0, INT_MIN, INT_MIN, -1, 14, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, 0, 0, 17, INT_MAX, -16, -38, INT_MAX, 0, INT_MAX, -15, 0, -31, 0, INT_MAX, INT_MAX, 49, INT_MIN, 0, INT_MIN, INT_MAX, 0, 24, INT_MAX, INT_MIN, 0, INT_MIN, 0, 0, -42, 0, 7, 0, 42, 0, 0, -12, 0, 0, INT_MIN, INT_MIN, 28, 19, -7, INT_MIN, 0, 0, 43, 31, 49, INT_MIN, -16, INT_MAX, INT_MIN, INT_MAX, 45, -43, 0, -15, 11, -43, INT_MIN, -47, -13, 0, -17, 5, 0, INT_MAX, -14, 0, INT_MIN, 0, 0, -42, 0, INT_MAX, INT_MAX, 0, -35, INT_MIN, -18, -22, -27, INT_MIN, -46, 0, INT_MAX, INT_MIN, 17, 9, INT_MAX, 0, INT_MAX, 6, INT_MAX, 25, INT_MAX, INT_MIN, 0, -6, 0, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MAX, INT_MIN, 41, -19, 0, 0, INT_MAX, INT_MAX, -26, 0, 20, INT_MAX, -6, 49, -29, 0, -33, 34, INT_MIN, INT_MIN, INT_MIN, 36, -9, INT_MAX, INT_MAX, 32, 0, 0, -5, INT_MAX, -49, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0, 0, 28, 0, INT_MIN, INT_MAX, 0, -45, 21, INT_MIN, -41, 0, 0, 0, INT_MAX, -26, 48, 10, INT_MIN, 21, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 35, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, -15, 6, 0, -46, INT_MIN, 35, INT_MAX, -1, INT_MIN, -4, INT_MAX, 18, -18, INT_MIN, 0, 28, 0, INT_MAX, INT_MAX, INT_MIN, -39, INT_MAX, INT_MIN, INT_MIN, 20, INT_MAX, -40, INT_MIN, INT_MAX, INT_MIN, -39, 25, INT_MAX, 1, 0, -3, -50, INT_MAX, INT_MIN, -39, -47, 25, 39, INT_MAX, 0, -25, INT_MIN, 0, 37, -28, INT_MAX, -37, -4, INT_MAX, INT_MIN, -8, 0, 49, 0, 20, 14, INT_MIN, 7, INT_MIN, -28, -14, INT_MIN, 16, 0, INT_MIN, 47, 0, INT_MAX, 6, -13, INT_MIN, INT_MIN, INT_MIN, -45, INT_MAX, 0, -11, 24, 47, INT_MAX, INT_MIN, INT_MIN, -12, -8, -8, 0, 35, INT_MAX, 0, -24, 2, 11, -27, INT_MAX, INT_MAX, -25, -31, 0, INT_MIN, 11, INT_MIN, 0, -34, 9, -22, 0, -36, INT_MAX, 23, -37, INT_MIN, INT_MIN, -36, -20, INT_MIN, INT_MIN, INT_MIN, 38, INT_MAX, -24, 11, 46, -27, 15, 0, 0, -49, 0, 32, 37, 28, -44, INT_MIN, 19, INT_MIN, 0, -27, 0, -38, -32, 0, 0, INT_MAX, INT_MAX, -37, 0, 19, 5, INT_MAX, 0, -25, INT_MAX, -38, 0, 3, -2, -17, -19, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 12, 16, -22, -26, INT_MIN, INT_MIN, 0, 0, INT_MIN, INT_MIN, 0, INT_MAX, -34, INT_MAX, INT_MIN, -40, INT_MIN, INT_MIN, -50, INT_MIN, 42, 0, -19, 40, -35, 37, -3, INT_MIN, 5, INT_MIN, 0, INT_MIN, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, -33, 0, 0, -32, 1, 0, -4, INT_MIN, -14, 0, -29, -38, -40, 0, -34, INT_MAX, -35, 0, 33, -21, 0, 28, 0, INT_MAX, -18, 19, 0, 42, -9, 1, 34, 0, -17, INT_MAX, 20, 0, 0, INT_MAX, 12, INT_MIN, -39, -35, INT_MAX, 22, INT_MAX, -4, -24, 29, -41, INT_MIN, 44, -18, 40, INT_MAX, 21, 16, 10, 44, INT_MIN, 0, -19, INT_MAX, 0, INT_MIN, 0, 0, INT_MIN, 8, INT_MAX, 9, INT_MIN, 0, -32, -36, INT_MAX, INT_MIN, -30, INT_MIN, INT_MIN, -27, 30, 40, -35, -3, -38, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MAX, -34, -17, INT_MIN, -20, INT_MAX, INT_MAX, 0, 0, INT_MIN, 24, 0, INT_MIN, INT_MAX, INT_MAX, 0, -4, -1, 0, 25, -7, 0, 0, INT_MAX, -27, INT_MAX, -15, 7, 0, INT_MAX, INT_MAX, -6, 28, 36, INT_MIN, -26, -10, 11, INT_MAX, INT_MAX, -39, INT_MAX, 0, -38, 28, INT_MIN, INT_MAX, INT_MAX, INT_MIN, -41, 39, -43, INT_MIN, 0, INT_MIN, -45, 0, 28, 35, INT_MAX, -40, INT_MAX, 9, 0, -43, INT_MIN, INT_MAX, -28, -47, 26, 0, INT_MIN, INT_MAX, INT_MIN, -35, 0, 42, 41, -43, 0, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 0, -24, -15, INT_MIN, 0, 0, INT_MIN, -16, INT_MIN, 0, -19, INT_MIN, 32, 32, INT_MAX, -15, INT_MAX, INT_MIN, 0, 2, INT_MAX, 8, INT_MIN, 44, INT_MIN, 9, INT_MAX, INT_MIN, -3, -13, INT_MAX, 0, -43, INT_MAX, INT_MAX, -49, 24, INT_MIN, -15, 1, 16, INT_MAX, INT_MAX, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MAX, -22, -32, -21, INT_MAX, INT_MAX, 0, 0, -19, INT_MAX, -11, -48, 0, -6, 9, 0, INT_MAX, 0, 33, -7, INT_MIN, 0, INT_MAX, INT_MIN, 0, 29, INT_MAX, INT_MAX, INT_MAX, INT_MIN, -25, INT_MAX, 0, INT_MIN, -27, 40, -42, 0, INT_MAX, 0, 24, INT_MIN, -19, 0, 0, -46, 19, 0, INT_MIN, -2, INT_MAX, -26, INT_MIN, 40, 9, INT_MAX, 0, 4, 0, INT_MIN, INT_MIN, -12, -39, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MAX, -1, -21, 0, -25, -16, INT_MIN, INT_MIN, -31, -35, 0, 7, INT_MAX, -24, INT_MAX, 0, 0, INT_MIN, 0, INT_MAX, -13, -28, 0, INT_MIN, -17, 45, 0, 18, INT_MIN, 38, 19, 0, 47, INT_MIN, INT_MAX, -4, INT_MAX, 10, 40, INT_MIN, 0, 0, INT_MIN, INT_MAX, 0, -26, INT_MIN, INT_MAX, INT_MIN, -42, INT_MAX, 41, INT_MIN, 0, 0, 0, INT_MAX, INT_MAX, -27, 0, INT_MAX, 0, 0, -39, 0, -4, INT_MAX, 29, 0, INT_MIN, -41, -37, 0, 12, INT_MIN, 0, 0, -33, -19, 29, 20, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 48, INT_MIN, -25, -29, 25, -34, INT_MIN, INT_MIN, INT_MAX, 0, INT_MIN, 43, INT_MAX, INT_MIN, -34, INT_MAX, -41, -46, INT_MAX, 36, 14, -50, 6, -30, 0, 0, INT_MAX, INT_MAX, 0, 0, 0, -30, INT_MAX, INT_MAX, 27, INT_MAX, INT_MAX, -31, 0, 36, 0, INT_MIN, -31, 36, 9, 31, 0, -28, INT_MIN, 0, INT_MAX, 0, 0, 0, 34, -15, INT_MAX, 0, 0, 3, 2, 0, INT_MAX, INT_MAX, -31, 21, 4, INT_MIN, -22, 0, INT_MAX, 0, INT_MAX, -43, 0, INT_MIN, 0, 6, -36, 0, -22, INT_MIN, 14, 0, 21, INT_MAX, 22, INT_MIN, INT_MAX, 45, INT_MAX, 0, -39, 8, 0, -27, -26, INT_MAX, 0, 0, 0, INT_MAX, 42, -33, INT_MAX, INT_MAX, -13, INT_MAX, INT_MAX, INT_MAX, INT_MIN, 40, INT_MAX, INT_MIN, INT_MIN, -25, 0, 31, -26, 0, INT_MIN, -1, -47, 35, 16, INT_MIN, 14, INT_MAX, -31, INT_MIN, INT_MIN, -36, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 30, 0, INT_MIN, INT_MAX, INT_MIN, -8, INT_MIN, 0, 47, INT_MAX, -14, 33, -1, -35, 0, INT_MIN, -13, 5, INT_MAX, 0, 0, INT_MIN, 29, 0, -47, 0, INT_MAX, 0, INT_MIN, 0, -19, 0, 5, 0, -49, INT_MAX, INT_MAX, 2, INT_MAX, 0, 0, 22, INT_MAX, -28, 0, INT_MAX, -6, INT_MIN, INT_MIN, INT_MAX, 0, INT_MAX, -7, 0, -39, 0, 26, 0, 0, -12, INT_MAX, -12, -43, 17, 50, 1, -13, INT_MIN, 0, 0, INT_MAX, INT_MAX, -2, INT_MIN, 0, 0, 41, INT_MAX, INT_MAX, INT_MIN, 0, -33, 49, INT_MAX, INT_MAX, INT_MAX, INT_MIN, 0, 0, INT_MAX, INT_MIN, INT_MIN, -30, INT_MAX, 0, 0, 38, INT_MAX, 29, 0, INT_MAX, 31, 0, 23, 5, INT_MIN, INT_MAX, INT_MIN, 0, -26, 0, 0, -32, 0, INT_MIN, 0, INT_MAX, 0, INT_MIN, 0, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 0, 0, INT_MIN, -45, -1, -13, INT_MAX, 0, INT_MAX, 0, 0, INT_MIN, 0, INT_MAX, -10, INT_MAX, INT_MIN, 13, INT_MAX, -41, 0, -8, 28, 0, -23, 1, INT_MAX, INT_MAX, -7, 0, 13, -47, 38, INT_MAX, 0, INT_MIN, INT_MIN, 0, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, INT_MAX, 1, INT_MIN, 0, INT_MAX, -42, -7, 14, INT_MAX, 30, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 41, INT_MAX, INT_MAX, INT_MAX, 0, 0, -47, INT_MAX, INT_MIN, -1, INT_MAX, 0, -12, INT_MIN, INT_MIN, INT_MAX, -10, INT_MIN, 0, 0, 14, 0, 0, INT_MIN, 0, -38, -37, -9, 0, 24, 10, INT_MIN, 0, 0, -38, INT_MAX, 8, INT_MAX, -6, INT_MAX, -32, 41, INT_MIN, 0, -32, 0, -31, 44, INT_MAX, -18, INT_MAX, INT_MAX, 0, -43, INT_MIN, -38, -43, INT_MIN, -32, INT_MAX, 4, INT_MIN, 34, 0, 39, -27, INT_MIN, INT_MAX, INT_MAX, INT_MIN, -13, INT_MAX, 3, 42, 0, -49, 0, 48, INT_MAX, INT_MIN, 42, INT_MAX, -34, 0, 13, INT_MAX, -26, INT_MAX, INT_MAX, INT_MAX, 0, 23, 0, -37, -2, 0, 37, 31, INT_MIN, 0, 0, INT_MIN, INT_MAX, INT_MAX, INT_MIN, -29, -12, INT_MAX, 0, 31, 46, INT_MAX, 16, -33, INT_MAX, INT_MIN, INT_MAX, INT_MAX, -50, 3, -4, -48, -47, 50, 24, 0, INT_MIN, -41, 0, 0, 0, INT_MAX, INT_MAX, -28, 0, INT_MAX, INT_MIN, 0, INT_MIN, 40, INT_MIN, INT_MIN, -48, INT_MIN, -17, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MAX, -19, 0, INT_MAX, 47, INT_MAX, 0, 0, -36, 0, 0, INT_MAX, INT_MAX, 42, 1, INT_MAX, 0, INT_MIN, -22, 0, INT_MAX, 33, INT_MAX, INT_MAX, 0, INT_MIN, INT_MAX, 0, -47, 5, INT_MAX, 50, INT_MAX, INT_MIN, INT_MAX, -44, 0, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 0, 0, INT_MAX, 40, -33, -19, -48, 0, 32, 35, INT_MAX, INT_MIN, -36, INT_MAX, 47, INT_MIN, INT_MIN, 22, INT_MIN, INT_MAX, 39, INT_MAX, INT_MIN, 50, 0, -41, -5, INT_MIN, -11, -1, INT_MAX, 15, INT_MIN, 0, 31, 0, INT_MIN, -38, INT_MAX, INT_MIN, INT_MIN, 27, -20, -45, 0, INT_MIN, 0, 36, INT_MIN, 7, 9, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 0, 0, INT_MIN, INT_MIN, 0, INT_MIN, INT_MAX, -16, -13, INT_MAX, 36, -16, -30, 0, -30, -41, INT_MAX, INT_MIN, -9, -11, INT_MAX, 0, -13, -6, INT_MIN, INT_MAX, INT_MAX, -33, INT_MAX, INT_MIN, -16, -24, -21, INT_MAX, INT_MAX, 0, 0, INT_MIN, 0, INT_MAX, INT_MAX, INT_MAX, 44, INT_MAX, INT_MIN, INT_MIN, -27, 0, INT_MAX, 0, 0, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 11, INT_MAX, INT_MIN, 0, INT_MIN, 35, -2, 0, INT_MAX, 0, INT_MAX, 0, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 0, 14, -45, -9, 33, INT_MAX, INT_MIN, -6, 0, INT_MIN, INT_MAX, 0, INT_MIN, INT_MIN, 0, INT_MIN, INT_MAX, 0, -30, INT_MIN, 23, INT_MIN, INT_MAX, 10, INT_MAX, INT_MAX, -1, INT_MIN, 0, INT_MAX, 28, 0, INT_MAX, 49, INT_MIN, INT_MIN, 15, INT_MIN, 15, INT_MAX, 0, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 0, INT_MAX, 0, 0, INT_MIN, INT_MIN, INT_MAX, 45, INT_MAX, 0, INT_MIN, -1, INT_MAX, -43, 15, INT_MAX, INT_MIN, -26, -33, -26, INT_MAX, -24, INT_MAX, 36, 0, -37, 3, 8, 49, -10, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 49, INT_MIN, 17, 49, 36, 35, INT_MIN, INT_MIN, INT_MAX, 12, INT_MAX, 14, -27, INT_MAX, 0, 31, 4, 0, -50, INT_MAX, -18, 28, INT_MIN, 43, INT_MAX, INT_MIN, INT_MAX, 0, 0, INT_MIN, 0, 0, 0, -13, INT_MIN, INT_MIN, INT_MIN, 0, -42, INT_MIN, 0, -31, -15, INT_MIN, 13, 0, 3, -16, -11, 0, 0, 38, -9, 4, INT_MAX, 36, 0, 49, -10, -35, INT_MAX, -47, -45, INT_MIN, 0, INT_MAX, 30, INT_MIN, 0, INT_MIN, INT_MAX, 0, -45, 0, -22, 0, -31, INT_MAX, INT_MAX, 0, 0, -47, INT_MAX, -33, INT_MIN, 13, 38, INT_MAX, 8, 32, 0, INT_MAX, INT_MAX, INT_MIN, -37, 0, 41, 18, INT_MIN, INT_MIN, INT_MIN, INT_MAX, -48, 0, -19, -10, 9, 41, INT_MAX, INT_MAX, 3, 41, INT_MAX, INT_MAX, 14, -35, -8, INT_MIN, 0, 0, 11, INT_MAX, 0, INT_MIN, 32, 25, -46, INT_MAX, 0, 43, 12, INT_MIN, -20, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 0, 26, INT_MAX, 30, 25, INT_MIN, INT_MIN, INT_MAX, INT_MIN, 0, -21, 18, INT_MAX, 0, INT_MIN, 46, INT_MAX, 24, 43, 0, INT_MIN, INT_MAX, 32, 29, 37, INT_MAX, INT_MAX, INT_MIN, 0, 0, -29, INT_MIN, INT_MAX, -20, -3, INT_MAX, -3, -2, INT_MAX, -15, -26, 0, INT_MIN, -43, INT_MAX, -50, 9, -25, 0, INT_MIN, 19, 5, 49, INT_MIN, INT_MIN, -50, 0, INT_MAX, 39, 0, -41, 0, INT_MAX, -10, 0, INT_MIN, 0, 0, 33, 0, -5, INT_MIN, 25, INT_MAX, INT_MIN, INT_MAX, -12, INT_MAX, INT_MIN, INT_MAX, 20, -47, INT_MAX, -27, 0, 0, 0, -19, 22, 6, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, -2, INT_MIN, 35, 0, INT_MIN, INT_MIN, -7, 0, 0, -48, INT_MAX, 0, -14, -6, 40, INT_MAX, -22, -37, INT_MAX, INT_MAX, 0, -49, 0, 0, INT_MIN, 0, 6, 0, INT_MIN, -13, INT_MAX, 0, INT_MIN, -31, INT_MIN, 0, -40, 8, -2, 45, -1, 25, -9, 0, -47, -42, INT_MAX, 0, 0, INT_MIN, 0, INT_MAX, INT_MAX, INT_MAX, -30, -31, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MIN, INT_MIN, 0, INT_MIN, INT_MIN, -1, INT_MIN, 23, -21, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 19, 10, INT_MIN, INT_MIN, INT_MAX, INT_MAX, -17, 0, 0, INT_MIN, 0, 14, 19, INT_MIN, INT_MIN, -31, 45, INT_MAX, 48, INT_MIN, 0, INT_MIN, 0, INT_MAX, 0, INT_MIN, INT_MIN, -22, INT_MAX, INT_MIN, -50, 0, 41, 0, -44, 0, 8, 16, 37, INT_MAX, INT_MIN, INT_MAX, INT_MIN, -9, 16, 0, 45, INT_MIN, INT_MAX, 34, INT_MAX, INT_MAX, INT_MIN, 43, 0, 30, 18, INT_MIN, 29, 45, 0, INT_MIN, INT_MAX, 0, 2, INT_MIN, 13, 0, -38, 18, 0, INT_MAX, INT_MIN, 32, INT_MAX, INT_MIN, 12, INT_MAX, -32, 30, INT_MAX, -44, 40, -13, -49, INT_MIN, INT_MAX, INT_MAX, INT_MAX, -23, -42, INT_MIN, -8, -7, INT_MIN, 0, INT_MAX, INT_MAX, 5, INT_MAX, 0, INT_MAX, INT_MAX, -33, 47, 0, 47, INT_MAX, INT_MAX, INT_MIN, INT_MAX, -24, INT_MAX, -31, 0, 0, 1, 0, -34, INT_MAX, 0, 0, 0, -3, 46, 38, -17, 5, INT_MIN, 0, -34, -40, 0, INT_MIN, INT_MAX, INT_MIN, INT_MIN, 45, 2, INT_MIN, 5, INT_MAX, INT_MIN, INT_MAX, 48, INT_MIN, INT_MIN, 0, INT_MIN, 0, INT_MAX, -28, 0, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 0, 28, INT_MAX, 22, INT_MAX, 18, INT_MAX, -23, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN, -7, INT_MIN, -13, INT_MAX, 31, 6, -30, INT_MAX, INT_MAX, 17, 0, 0, 0, 27, 25, 0, INT_MAX, INT_MIN, INT_MAX, INT_MAX, 42, -5, INT_MIN, 0, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 0, INT_MIN, 0, 0, INT_MIN, INT_MAX, 0, 43, -2, INT_MAX, INT_MIN, 15, -6, INT_MIN, INT_MIN, 0, 5, 37, INT_MIN, INT_MIN, -34, 7, INT_MIN, 36, 0, INT_MAX, -5, INT_MAX, INT_MIN, 0, INT_MIN, INT_MIN, 31, -30, -8, INT_MAX, -7, 23, 43, 40, INT_MIN, 38, 0, INT_MAX, 0, 0, INT_MIN, -24, INT_MIN, -37, -44, 2, 0, 12, 0, -49, 0, 49, -12, 36, INT_MIN, INT_MIN, 43, 0, -11, INT_MAX, 0, 49, 0, 3, 0, INT_MAX, 36, INT_MAX, -39, 46, INT_MIN, INT_MAX, INT_MAX, 0, 0, INT_MIN, 14, -50, INT_MIN, INT_MIN, -13, INT_MAX, INT_MAX, 10, INT_MIN, 0, 49, -10, 41, 0, INT_MAX, 42, INT_MAX, INT_MAX, -44, 47, INT_MIN, -26, INT_MAX, 1, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MIN, -22, 0, 0, 11, 6, 32, -18, 47, INT_MAX, INT_MAX, INT_MAX, 49, INT_MIN, 14, INT_MIN, 0, 40, INT_MAX, -1, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 45, INT_MAX, INT_MIN, -42, 0, -37, -25, -16, -27, -14, -5, INT_MIN, -30, 0, 28, INT_MIN, 0, -15, 20, 22, INT_MAX, -33, -24, -38, INT_MAX, 46, 0, -45, -47, INT_MAX, INT_MIN, 4, INT_MAX, INT_MIN, INT_MAX, 0, 0, INT_MIN, -22, 0, 3, 41, INT_MIN, 36, INT_MIN, INT_MIN, 8, INT_MIN, 0, 0, 0, 20, -48, INT_MIN, -30, INT_MAX, INT_MAX, -7, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, -30, INT_MIN, -13, 0, 0, 48, 11, INT_MAX, 12, -28, INT_MIN, INT_MIN, 0, -21, INT_MAX, INT_MAX, INT_MIN, 15, INT_MIN, -4, INT_MIN, INT_MIN, 11, INT_MIN, INT_MAX, -8, 0, INT_MAX, 0, 0, -6, INT_MIN, 0, INT_MIN, -9, INT_MAX, 36, 48, INT_MAX, INT_MAX, 0, -20, INT_MIN, INT_MAX, 0, INT_MAX, 0, INT_MIN, 12, INT_MAX, 33, INT_MIN, INT_MAX, 0, INT_MAX, INT_MAX, 18, 0, INT_MIN, 0, INT_MAX, -44, 33, 0, -9, 1, 0, INT_MAX, -29, INT_MIN, INT_MIN, 17, INT_MAX, INT_MIN, 0, 0, INT_MAX, 0, 2, INT_MIN, INT_MIN, -44, -14, 0, 0, 29, INT_MIN, INT_MAX, 0, 0, 0, -49, INT_MAX, INT_MIN, 0, 0, 32, INT_MIN, INT_MIN, INT_MAX, 16, -47, 16, 11, 0, 2, 6, -13, -39, 0, 0, INT_MAX, 12, INT_MIN, -45, -5, -50, 0, -41, 0, 0, -1, 0, INT_MIN, -28, 0, 11, -47, 40, INT_MIN, 0, INT_MAX, -39, INT_MIN, 0, INT_MIN, INT_MAX, INT_MIN, 0, INT_MIN, INT_MAX, 17, -10, 0, 6, INT_MAX, INT_MIN, 45, -40, 0, INT_MIN, INT_MIN, -25, 0, INT_MIN, INT_MIN, 0, 0, INT_MAX, INT_MIN, 8, INT_MAX, -39, INT_MAX, INT_MIN, -28, INT_MAX, 0, INT_MIN, INT_MIN, 31, INT_MIN, -27, INT_MAX, 18, INT_MIN, 0, INT_MIN, 0, INT_MAX, 49, 17, 12, INT_MIN, -5, INT_MIN, INT_MAX, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 0, -12, 0, -24, INT_MAX, INT_MAX, 42, INT_MAX, -46, INT_MIN, -3, INT_MAX, 0, INT_MIN, INT_MAX, INT_MIN, -5, 36, -41, 36, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 0, INT_MAX, -4, -12, INT_MAX, -42, INT_MIN, 0, 25, 0, INT_MAX, INT_MIN, INT_MAX, 31, INT_MIN, INT_MAX, INT_MIN, -23, 0, INT_MIN, 43, INT_MIN, 38, -4, -49, INT_MAX, 44, INT_MAX, 41, INT_MIN, -3, 0, INT_MAX, -39, INT_MAX, INT_MIN, -12, INT_MAX, 6, 15, 33, -38, 0, 25, 0, -12, 47, 0, INT_MIN, 20, -25, INT_MAX, 15, INT_MAX, INT_MAX, 0, -44, INT_MAX, INT_MAX, INT_MAX, INT_MIN, 0, 44, 29, INT_MAX, INT_MIN, INT_MIN, 0, INT_MIN, INT_MAX, 0, -39, 36, INT_MAX, -2, 0, INT_MAX, -12, -47, -8, 0, INT_MAX, INT_MAX, 48, INT_MAX, 0, INT_MAX, INT_MIN, 9, -10, 0, -36, -10, 15, -26, INT_MAX, INT_MAX, -15, INT_MAX, INT_MIN, INT_MIN, -46, 0, INT_MIN, -30, -42, 27, 19, INT_MAX, 11, 23, INT_MIN, INT_MAX, 0, 45, -30, INT_MAX, INT_MIN, INT_MAX, INT_MIN, 5, 0, 18, 7, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, -38, -49, 37, 0, INT_MIN, INT_MIN, 17, -49, INT_MIN, INT_MIN, 20, 0, -8, 18, -5, INT_MAX, 32, -6, INT_MAX, INT_MIN, INT_MAX, -48, 26, 6, INT_MAX, 0, -27, 7, 0, -48, INT_MIN, -49, -21, 0, 0, 0, 0, 5, 0, 0, -37, 14, INT_MAX, -39, INT_MAX, INT_MIN, 0, 46, INT_MIN, 0, INT_MIN, -37, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MIN, 15, 18, 0, INT_MAX, 23, INT_MAX, INT_MAX, INT_MAX, 33, 0, 28, -42, 0, 0, INT_MIN, 46, 0, 0, INT_MAX, -46, 0, 0, INT_MIN, 20, INT_MIN, INT_MIN, 0, -10, -42, 0, 0, -22, -33, INT_MAX, INT_MIN, INT_MIN, 0, -3, 0, 39, 31, INT_MIN, 6, INT_MAX, -19, 0, 42, 35, 29, INT_MIN, 4, INT_MIN, INT_MAX, INT_MAX, INT_MIN, -50, INT_MAX, 0, INT_MAX, INT_MIN, -46, INT_MIN, 7, 0, 8, 0, INT_MAX, 32, INT_MAX, INT_MIN, 44, 0, 0, -29, 6, -20, 42, -24, 0, 0, INT_MIN, INT_MIN, INT_MAX, 0, -39, 0, 0, INT_MAX, 10, 0, INT_MIN, -6, 46, INT_MAX, 41, -1, 46, 0, 9, -3, 18, 0, 43, INT_MAX, -20, 43, -20, INT_MAX, 12, INT_MIN, 0, -39, -25, 8, -7, 0, INT_MIN, INT_MIN, INT_MAX, INT_MAX, -2, INT_MIN, -10, 35, INT_MIN, INT_MIN, -35, 0, INT_MAX, INT_MAX, -38, INT_MAX, 44, 30, 42, 22, 0, INT_MIN, 0, 30, 0, 22, 0, 0, INT_MAX, INT_MAX, 0, -40, -18, 0, INT_MAX, 31, 0, 0, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, -23, 0, INT_MIN, 16, 0, 12, 44, -45, -42, INT_MAX, INT_MIN, -15, 28, -14, -38, 0, 22, 0, INT_MAX, INT_MIN, 0, INT_MAX, -16, 46, -44, 31, INT_MAX, -12, -44, INT_MIN, -6, -29, 3, -33, -4, INT_MAX, 34, 0, 0, INT_MAX, INT_MIN, 0, 22, 49, 11, 0, -37, INT_MIN, 19, 0, -49, 0, INT_MAX, 0, INT_MAX, 29, 0, INT_MAX, 0, 0, -39, 0, INT_MIN, INT_MIN, 0, 0, INT_MAX, INT_MAX, INT_MIN, -27, INT_MAX, 3, 40, -9, 0, INT_MIN, 27, 24, INT_MAX, 27, INT_MAX, INT_MIN, 21, INT_MIN, 0, INT_MAX, 45, -13, INT_MIN, 0, INT_MIN, INT_MIN, -50, 0, 0, 0, 10, INT_MAX, 47, INT_MAX, INT_MIN, INT_MAX, -18, INT_MAX, INT_MIN, INT_MAX, INT_MIN, -1, 0, INT_MIN, -40, 0, INT_MAX, 0, -35, INT_MIN, INT_MAX, INT_MIN, 47, 0, 31, 27, -36, -31, 31, INT_MAX, -47, 0, INT_MAX, 19, INT_MIN, 0, 33, INT_MAX, INT_MIN, 12, INT_MIN, -11, INT_MAX, -39, 17, 43, -32, 7, INT_MIN, INT_MIN, -9, INT_MAX, 0, 0, INT_MIN, 0, 47, -21, 44, 12, 0, 27, -45, -36, -46, 0, INT_MAX, INT_MIN, INT_MAX, 7, 20, 0, INT_MAX, INT_MIN, 32, INT_MIN, -10, -29, INT_MIN, 6, 0, INT_MIN, INT_MIN, INT_MIN, 0, INT_MAX, INT_MIN, -27, -43, -19, INT_MAX, INT_MAX, INT_MIN, -42, -4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 50, INT_MAX, 0, 0, 0, INT_MIN, 29, INT_MIN, INT_MAX, -26, 0, 6, 42, INT_MIN, 32, 30, INT_MAX, 0, INT_MIN, -8, -17, 0, INT_MAX, 0, 43, INT_MAX, -26, 27, INT_MAX, 40, INT_MIN, INT_MIN, 0, 0, 0, 0, 43, 0, INT_MAX, 0, 0, -50, INT_MAX, INT_MIN, INT_MIN, -43, INT_MIN, 0, INT_MIN, -10, 3, 35, 0, INT_MIN, 0, 8, 35, 40, -7, INT_MAX, -22, 18, INT_MAX, INT_MIN, 45, INT_MAX, 39, INT_MAX, 0, INT_MIN, INT_MAX, INT_MAX, 17, 0, 16, 0, 0, INT_MIN, 4, INT_MIN, INT_MAX, 3, 0, -13, 6, INT_MIN, -46, 48, INT_MAX, INT_MAX, 34, INT_MAX, INT_MAX, INT_MAX, INT_MAX, -28, INT_MIN, 0, 27, 9, INT_MAX, 0, INT_MAX, 24, -13, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 29, 0, 38, INT_MIN, INT_MIN, INT_MIN, -41, -42, 0, 0, -9, 0, INT_MAX, INT_MIN, INT_MIN, -23, 27, INT_MIN, 0, 0, INT_MIN, -37, -35, INT_MAX, INT_MAX, INT_MIN, 0, 6, INT_MIN, -25, INT_MIN, 0, -43, 16, INT_MIN };


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
