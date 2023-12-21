.data
arr:
  .dword 6, 3, 2, 4, 1, 5

.text
.global main

main:
  la a0, arr
  li a1, 6
  li t3, 1 

  outer:
    bge t3, a1, outerExit 
    
    addi t4, t3, -1
    mv t5, zero 

    inner:
      blt t4, zero, innerExit 
      slli t0, t4, 3
      add t0, a0, t0
      ld t1, 0(t0) # v[j]
      ld t2, 8(t0) # v[j+1]
      ble t1, t2, innerExit 

     
      sd t2, 0(t0)
      sd t1, 8(t0)
	
      # Update j +(-1)
      addi t4, t4, -1
      j inner

    innerExit:
      addi t3, t3, 1 # Update i + 1
      j outer

  outerExit:
    li a7, 10 # Exit program
    ecall
