.data
arr:
  .dword 6, 3, 2, 4, 1, 5

.text
.global main

main:
    la a0, arr #a0, arr
    li a1, 6 #n
    li s3, 0 #i

outer:
    addi t5, a1, -1
    bge s3, t5, outerExit
    li t4, 0 #j

    inner:
        sub t5, t5, s3 # n-1-i,
        bge t4, t5, innerExit # j, n-1-i,
        slli t1, t4, 3 #t6 = j*8
        add t1, a0, t1
        ld t0, 0(t1)
        ld t2, 8(t1)
        blt t0, t2, innerEnd
        sd t2, 0(t1)
        sd t0, 8(t1)

    innerEnd:
        addi t4, t4, 1
        j inner

    innerExit:
        addi s3,s3, 1
        j outer

outerExit:
    li a7, 10 # Exit program
    ecall