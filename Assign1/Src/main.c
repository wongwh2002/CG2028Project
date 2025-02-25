/**
 ******************************************************************************
 * @project        : CG/[T]EE2028 Assignment 1 Program Template
 * @file           : main.c
 * @author         : Hou Linxin, ECE, NUS
 * @brief          : Main program body
 ******************************************************************************
 *
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "stdio.h"

#define F 3
#define S 2
#define F2 4
#define S2 3
#define ENTRY_SIZE 5

extern void asm_func(int* arg1, int* arg2, int* arg3, int* arg4);
extern void initialise_monitor_handles(void);

void printMatrix(int matrix[F][S]) {
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < S; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void printMatrix2(int matrix[F2][S2]) {
    for (int i = 0; i < F2; i++) {
        for (int j = 0; j < S2; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void printMatrix0(int matrix[F2][S2]) {
    for (int i = 0; i < F2; i++) {
        for (int j = 0; j < S2; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
	initialise_monitor_handles();
	int buildings[5][F][S] = {
	    {{8,8}, {8,8}, {8,8}},
	    {{1,2}, {3,4}, {5,6}},
	    {{12,12}, {10,5}, {3,7}},
	    {{12,12}, {12,12}, {12,12}},
	    {{9,10}, {7,8}, {4,4}}
	};

	int entries[5][ENTRY_SIZE] = {
		{1,2,3,4,5},
	    {1,1,1,1,1},
	    {1,1,1,1,5},
	    {0,0,0,0,0},
		{2,4,6,8,10}
	};

	int exits[5][F][S] = {
	    {{1,2}, {2,3}, {3,4}},
	    {{1,0}, {0,0}, {0,0}},
	    {{1,2}, {3,4}, {3,6}},
	    {{2,2}, {3,3}, {4,4}},
	    {{1,1}, {1,1}, {1,1}}
	};
	for (int t = 0; t < 5; t++) {
		int result[F][S] = {{F,S},{0,0},{0,0}};
	    printf("RESULT %d:\n", t+1);
	    asm_func((int*)buildings[t], (int*)entries[t], (int*)exits[t], (int*)result);
	    printMatrix(result);
	    printf("\n");
	}

	int building2[F2][S2] = {{12, 12, 12},{10,5, 5},{3,7, 7}, {8, 8, 8}};
	int entry2[5] = {12,12,12,12,12};
	int exit2[F2][S2] = {{1, 2, 3},{3, 4, 1}, {3,6, 1}, {1, 2, 1}};
	int result2[F2][S2] = {{F2, S2, 0}, {0, 0, 0}, {0,0, 0} , {0, 0, 0}};
	asm_func((int*)building2, (int*)entry2, (int*)exit2, (int*)result2); //call asm function
	printf("RESULT6\n");
	printMatrix2(result2);
	printf("RESULT7\n");

	int building1[1][1] = {{1}};
	int entry1[5] = {12,12,12,12,12};
	int exit1[1][1] = {{1}};
	int result1[1][2] = {{1, 1}};
	asm_func((int*)building1, (int*)entry1, (int*)exit1, (int*)result1); //call asm function
	printf("HARROOOO %d\t\n", result1[0][0]);


	int building0[0][0] = {};
	int entry0[5] = {12,12,12,12,12};
	int exit0[0][0] = {};
	int result0[1][2] = {{0, 0}};
	asm_func((int*)building0, (int*)entry0, (int*)exit0, (int*)result0); //call asm function
	printf("hrufieabgus");



//	int result[F][S] = {{F,S},{0,0},{0,0}};
//	asm_func((int*)buildings[0], (int*)entries[0], (int*)exits[0], (int*)result); //call asm function
//	printf("RESULT\n");
//    printMatrix(result);
//
//
//	int building1[F][S] = {{1,2},{3,4},{5,6}}; //initial state
//	int entry1[5] = {1,1,1,1,1};
//	int exit1[F][S] = {{1,0},{0,0},{0,0}};
//	int result1[F][S] = {{F,S},{0,0},{0,0}};
//	asm_func((int*)building1, (int*)entry1, (int*)exit1, (int*)result); //call asm function
//	printf("RESULT1\n");
//    printMatrix(result);
//
//	int building2[F][S] = {{12,12},{10,5},{3,7}};
//	int entry2[5] = {1,1,1,1,5};
//	int exit2[F][S] = {{1,2},{3,4}, {3,6}};
//	int result2[F][S] = {{F,S},{0,0},{0,0}};
//	asm_func((int*)building2, (int*)entry2, (int*)exit2, (int*)result2); //call asm function
//	printf("RESULT2\n");
//    printMatrix(result2);
//
//
//	int building3[F][S] = {{12,12},{12,12},{12,12}};
//	int entry3[5] = {0,0,0,0,0};
//	int exit3[F][S] = {{2,2},{3,3},{4,4}};
//	int result3[F][S] = {{F,S},{0,0},{0,0}};
//	asm_func((int*)building3, (int*)entry3, (int*)exit3, (int*)result3); //call asm function
//	printf("RESULT3\n");
//    printMatrix(result3);
//
//
//	int building4[F][S] = {{9,10},{7,8},{4,4}};
//	int entry4[5] = {2,4,6,8,10};
//	int exit4[F][S] = {{1,1},{1,1},{1,1}};
//	int result4[F][S] = {{F,S},{0,0},{0,0}};
//	asm_func((int*)building4, (int*)entry4, (int*)exit4, (int*)result4); //call asm function
//	printf("RESULT4\n");
//    printMatrix(result4);
}



