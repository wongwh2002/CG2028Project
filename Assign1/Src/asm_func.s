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

@ Write Student 1’s Name here:
@ Write Student 2’s Name here:

@ Look-up table for registers:

@ R0 ...
@ R1 ...
@ ...

@ write your program from here:

asm_func:
 	PUSH {R14}

	BL SUBROUTINE

 	POP {R14}

	BX LRx
	//cannot go back to main anymore if comment push and pop in (i), but program works in (ii)
	//c to asm_func, LR changed, to store return value back to C
	//asm -> subroutine, LR updated again, enable program to go back from subroutine to asm_func
	//asm -> c LR1 is lost bc of that, therefore need to push and pop LR to save the value of them

SUBROUTINE:

	BX LR
