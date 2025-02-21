/*
 * asm_func.s
 *
 *  Created on: 7/2/2025
 *      Author: Hou Linxin
 */
   .syntax unified
	.cpu cortex-m4
	.fpu softvfp
	.thumb

		.global asm_func

@ Start of executable code
.section .text

@ CG/[T]EE2028 Assignment 1, Sem 2, AY 2024/25
@ (c) ECE NUS, 2025

@ Write Student 1’s Name here: Wong Weng Hong
@ Write Student 2’s Name here: Tng Wen Xi

@ Look-up table for registers:

@ R0 -  Building
@ R1 - Entry
@ R2 - Exit and
@      Reused to store #12 for SUB operation, after LOOP_SUM
@ R3 - Result
@ R4 - Size of building (number_of_loops_left index!)
@ R5 - Sum of entry cars
@ R6 - Size of entry (number_of_loops_left index!) and
@      Temp register used in LOOP_COUNT to load building[A][B]
@      and store back to result[A][B]
@ R7 - Temp register to load entry[A] and exit[A][B]
@ R8 - Temp register used to store available slots in each section


@ write your program from here:

asm_func:
	PUSH {R4-R8}


	.equ F, 2 //num floor
	.equ S, 3 //num section
	.equ E, 5 //size of entry
	.equ MAX_CAP, 12

	LDR R4, [R3]
	LDR R5, [R3, #4]

	MUL R4, R5 // this is ur index for the 1d arr /size

	MOV R5, #0
	MOV R6, #E
	LOOP_SUM:
		LDR R7, [R1], #4 //ldr entry arr into R6, R5 is sum
		ADD R5, R7
		SUBS R6, #1
		BGT LOOP_SUM

	MOV R1, #MAX_CAP
	//Over here, R5 = total sum, R6 & R7 useless, R4 is index
	LOOP_COUNT:
		LDR R6, [R0], #4 //store i in building to R6
		LDR R7, [R2], #4 //store i in exit to R7
		SUB R8, R1, R6 //R1 == 12
		//R8 IS AVAILABLE slots in section
		CMP R8, R5
		ITTEE LE //if available slot <= total sum
			SUBLE R5, R8
			MOVLE R6, R1
			ADDGT R6, R5
			MOVGT R5, #0

		//R6 is current updated i, now i want car to exit
		SUB R6, R7
		STR R6, [R3], #4


		SUBS R4, #1 // decrement number_of_loops_left index,
		            // exit loop when R4 == 1 at before this line
		            // R4 == 0 aft this line!
		BGT LOOP_COUNT




	//PUSH {R14}
	//BL SUBROUTINE

 	//POP {R14}
 	EXIT_LOOP: POP {R4-R8}

	BX LR
	//cannot go back to main anymore if comment push and pop in (i), but program works in (ii)
	//c to asm_func, LR changed, to store return value back to C
	//asm -> subroutine, LR updated again, enable program to go back from subroutine to asm_func
	//asm -> c LR1 is lost bc of that, therefore need to push and pop LR to save the value of them

SUBROUTINE:

	BX LR
