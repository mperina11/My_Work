// BY: MARTIN PERINA

.section .data

prompt:     .asciz "Enter an integer between %d and %d: "
scan:       .asciz "%d"
invalid:    .asciz "Invalid value!\n"

value:      .word 0

min_out:    .asciz "\nThe min is %d\n"
max_out:    .asciz "The max is %d\n"

.section .text
.global main

// function definitions
error_code:
	ldr r0, =invalid
	bl printf
//--------------------------------------------------------
get_integer:
	push {r11,lr}

	sub r11, sp, #4
	sub sp, r11, #4

	ldr r0, =prompt
	mov r1, #1
	mov r2, #50
	bl printf

	ldr r0, =scan
	mov r1, r11
//	ldr r1, =value
	bl scanf
//	ldr r1, [r1]

//	cmp r1, #1
//	blt error_code
//	cmp r1, #1
//	blt get_integer
//	cmp r1, #50
//	bgt error_code
//	cmp r1, #50
//	bgt get_integer

	ldr r0, [r11]
	add sp, r11, #4

	pop {r11,pc}
//----------------------------------------------------------
min_three:
	push {lr}

	cmp r0, r1
	movhi r0, r1

	cmp r0, r2
	movhi r0, r2

	pop {pc}
//----------------------------------------------------------
max_three:
	push {lr}

	cmp r0, r1
	movls r0, r1

	cmp r0, r2
	movls r0, r2

	pop {pc}
//----------------------------------------------------------
// start of main
main:
	push {lr}

	bl get_integer  // get 1st int
	mov r4, r0

	bl get_integer // get 2nd int
	mov r5, r0

	bl get_integer // get 3rd int
	mov r6, r0

	mov r0, r4
	mov r1, r5
	mov r2, r6
	bl min_three   // call min_three
	mov r3, r0

	ldr r0, =min_out
	mov r1, r3
	bl printf      // output min

	mov r0, r4
	mov r1, r5
	mov r2, r6
	bl max_three    // call max_three
	mov r3, r0

	ldr r0, =max_out
	mov r1, r3
	bl printf       // output max

	mov r0, #0     // close out
	pop {pc}
