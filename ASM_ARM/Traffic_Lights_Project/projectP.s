// Created By; Martin Perina
// Traffic Lights with button to activate Crosswalk

.equ INPUT, 0
.equ OUTPUT, 1
.equ LOW, 0
.equ HIGH, 1
.equ PIN29, 29 //green
.equ PIN28, 28 //yellow
.equ PIN27, 27 //red
.equ PIN14, 14 //RED    [walk]
.equ PIN13, 13 //GREEN  [walk]
.equ PIN10, 10 //BUTTON [walk]

.data
no_walk:    .asciz "Wait to walk\n"
walk:       .asciz "You may now walk\n"
walk_blink: .asciz "Walk ending\n"
end:	    .asciz "\nEnd of program\n"

.text
.global main
main:
	push {lr}

//mod for each pin
MODE:
	bl wiringPiSetup

	mov r0, #PIN29//green
	mov r1, #OUTPUT
	bl pinMode

	mov r0, #PIN28//yellow
	mov r1, #OUTPUT
	bl pinMode

	mov r0, #PIN27//red
	mov r1, #OUTPUT
	bl pinMode

	mov r0, #PIN14//RED [walk]
	mov r1, #OUTPUT
	bl pinMode

	mov r0, #PIN13//GREEN [walk]
	mov r1, #OUTPUT
	bl pinMode

	mov r0, #PIN10//BUTTON [walk]
	mov r1, #INPUT
	bl pinMode

	b WALK_LIGHTS

WALK_LIGHTS:
//no_walk msg
	ldr r0, =no_walk
	bl printf

//RED [walk]:
	mov r0, #PIN14
	mov r1, #OUTPUT //on
	bl digitalWrite

	b LIGHTS
LIGHTS:
//green:
	mov r0, #PIN29 //on
	mov r1, #OUTPUT
	bl digitalWrite

	ldr r0, =#3000 //delay
	bl delay

	mov r0, #PIN29 //off
	mov r1, #LOW
	bl digitalWrite

//yellow:
	mov r0, #PIN28 //on
	mov r1, #OUTPUT
	bl digitalWrite

	ldr r0, =#3000 //delay
	bl delay

	mov r0, #PIN28 //off
	mov r1, #LOW
	bl digitalWrite

//red:
	mov r0, #PIN27 //on
	mov r1, #OUTPUT
	bl digitalWrite

	ldr r0, =#3000 //delay
	bl delay

//BUTTON [walk]:
	mov r0, #PIN10
	bl digitalRead
	cmp r0, #HIGH //check if button pressed
	bne WALK

//red:
	mov r0, #PIN27 //off
	mov r1, #LOW
	bl digitalWrite


	b WALK_LIGHTS
//	b END
CONT_LIGHTS:
//red
	mov r0, #PIN27 //off
	mov r1, #LOW
	bl digitalWrite

	b WALK_LIGHTS
WALK:
//RED [walk]:
	mov r0, #PIN14
	mov r1, #LOW //off
	bl digitalWrite

	ldr r0, =#1000 //delay
	bl delay

//GREEN [walk]:
	mov r0, #PIN13 //on
	mov r1, #OUTPUT
	bl digitalWrite

//walk msg
	ldr r0, =walk
	bl printf

	ldr r0, =#3000 //delay
	bl delay

//call blink
	b BLINK

BLINK:
//green
	mov r0, #PIN29 //on
	mov r1, #OUTPUT
	bl digitalWrite
//yellow
	mov r0, #PIN28 //on
	mov r1, #OUTPUT
	bl digitalWrite

//walk end msg
	ldr r0, =walk_blink
	bl printf

	ldr r0, =#500 //delay
	bl delay
//green
	mov r0, #PIN29//off
	mov r1, #LOW
	bl digitalWrite
//red
	mov r0, #PIN28//off
	mov r1, #LOW
	bl digitalWrite

	ldr r0, =#1000
	bl delay

//GREEN [walk]
	mov r0, #PIN13 //off
	mov r1, #LOW
	bl digitalWrite

	ldr r0, =#1000 //delay
	bl delay

	b CONT_LIGHTS

END:
//red
	bl wiringPiSetup
	mov r0, #PIN27 //off
	mov r1, #LOW
	bl digitalWrite
//RED [walk}
	mov r0, #PIN14 //off
	mov r1, #LOW
	bl digitalWrite

//end program msg
	ldr r0, =end
	bl printf

	mov r0, #0
	pop {pc}
