.section .data
.global testData
.type testData,%object
.size testData,4
testData:
    .word 3
    .align 2


.section .rodata
.global enter
.type enter,%object
.size enter,4
enter:
    .word 10
    .align 2


.section .text
.global matrixAdd
.type matrixAdd, %function
matrixAdd:
    push {r11, lr}
    sub sp, sp, #28
    add r11, sp, #0

    mov r1, #1
    str r1, [r11, #24]@ 1[0]
    mov r1, #2
    str r1, [r11, #20]@ 1[1]
    mov r1, #0
    str r1, [r11, #16]@ 2[0]
    mov r1, #1
    str r1, [r11, #12]@ 2[1]
    mov r1, #0
    str r1, [r11, #8]@ r[0]
    mov r1, #0
    str r1, [r11, #4]@ r[1]
    mov r1, r0
    str r1, [r11, #16]@ 2[0] = x
    mov r1, #0
    str r1, [r11, #0]@indexForX1 = 0
.Loop:
    ldr r1, [r11, #0]@ get current index
    cmp r1, #2
    beq .Stop
    mov r6, #4
    mul r3, r1, r6
    mov r6, #24
    sub r3, r6, r3
    ldr r4, [r11, r3]@ r4 = 1[r1]
    mov r6, #4
    mul r3, r1, r6
    mov r6, #16
    sub r3, r6, r3
    ldr r5, [r11, r3]@ r5 = 2[r1]
    mov r6, #4
    mul r3, r1, r6
    mov r6, #8
    sub r3, r6, r3
    ldr r2, [r11, r3]@ r2 = r[r1]
    add r2, r2, r4
    add r2, r2, r5
    str r2, [r11, r3]@ r[r1] = r2
    add r1, #1@ r1 += 1
    str r1, [r11, #0]
    b .Loop
.Stop:
    ldr r0, [r11, #8]
    ldr r1, [r11, #4]
    add r0, r1, r0

    add r11, r11, #28
    mov sp, r11
    pop {r11, pc}



.align 1
.global main
.type main,%function
main:
    push {r11,lr}
    sub sp, sp, #8
    add r11, sp, #0
    bl getint(PLT)@ get input, and put it into n's address
    str r0, [r11, #8]

    ldr r0, _bridge
    ldr r0, [r0]
    bl matrixAdd(PLT)
    str r0, [r11, #4]
    ldr r1, [r11, #8]
    sub r0, r0, r1
    str r0, [r11, #4]

    ldr r0, [r11, #4]@ result
    push {r0, r1}
    bl putint(PLT)
    ldr r0, _bridge+4
    ldr r0, [r0]
    bl putchar(PLT)
    b .endMain

.endMain:
    add r11, r11, #8
    sub sp, r11, #0
    pop {r11,pc}

_bridge:
.word testData
.word enter