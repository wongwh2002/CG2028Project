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

extern void asm_func(int* arg1, int* arg2, int* arg3, int* arg4);
extern void initialise_monitor_handles(void);



int main(void)
{
	initialise_monitor_handles();
	int building[F][S] = {{8,8},{8,8},{8,8}}; //initial state
	int entry[5] = {1,2,3,4,5};
	int exit[F][S] = {{1,2},{2,3},{3,4}};
	int result[F][S] = {{F,S},{0,0},{0,0}};
	asm_func((int*)building, (int*)entry, (int*)exit, (int*)result); //call asm function
	int i,j;
	// print result[][]
	printf("RESULT\n");
    for (i=0; i<F; i++)
    {
		for (j=0; j<S; j++)
		{
			building[i][j] = result[i][j];
			printf("%d\t", building[i][j]);
		}
    }
	printf("\n");


	int building1[F][S] = {{1,2},{3,4},{5,6}}; //initial state
	int entry1[5] = {1,1,1,1,1};
	int exit1[F][S] = {{1,0},{0,0},{0,0}};
	int result1[F][S] = {{F,S},{0,0},{0,0}};
	asm_func((int*)building1, (int*)entry1, (int*)exit1, (int*)result1); //call asm function
	printf("RESULT1\n");
    for (i=0; i<F; i++)
    {
		for (j=0; j<S; j++)
		{
			building1[i][j] = result1[i][j];
			printf("%d\t", building1[i][j]);
		}
    }
	printf("\n");


	int building2[F][S] = {{12,12},{10,5},{3,7}};
	int entry2[5] = {1,1,1,1,5};
	int exit2[F][S] = {{1,2},{3,4}, {3,6}};
	int result2[F][S] = {{F,S},{0,0},{0,0}};
	asm_func((int*)building2, (int*)entry2, (int*)exit2, (int*)result2); //call asm function
	printf("RESULT\n");
    for (i=0; i<F; i++)
    {
		for (j=0; j<S; j++)
		{
			printf("%d\t", result2[i][j]);
		}
    }
	printf("\n");


	int building3[F][S] = {{12,12},{12,12},{12,12}};
	int entry3[5] = {0,0,0,0,0};
	int exit3[F][S] = {{2,2},{3,3},{4,4}};
	int result3[F][S] = {{F,S},{0,0},{0,0}};
	asm_func((int*)building3, (int*)entry3, (int*)exit3, (int*)result3); //call asm function
	printf("RESULT\n");
    for (i=0; i<F; i++)
    {
		for (j=0; j<S; j++)
		{
			printf("%d\t", result3[i][j]);
		}
    }
	printf("\n");


	int building4[F][S] = {{9,10},{7,8},{4,4}};
	int entry4[5] = {2,4,6,8,10};
	int exit4[F][S] = {{1,1},{1,1},{1,1}};
	int result4[F][S] = {{F,S},{0,0},{0,0}};
	asm_func((int*)building4, (int*)entry4, (int*)exit4, (int*)result4); //call asm function
	printf("RESULT\n");
    for (i=0; i<F; i++)
    {
		for (j=0; j<S; j++)
		{
			printf("%d\t", result4[i][j]);
		}
    }
	printf("\n");
}

//void print(int building, int result)
//{
//	int i,j;
//	// print result[][]
//	printf("RESULT\n");
//	for (i=0; i<F; i++)
//	{
//		for (j=0; j<S; j++)
//		{
//			building[i][j] = result[i][j];
//			printf("%d\t", building[i][j]);
//		}
//	printf("\n");
//}


