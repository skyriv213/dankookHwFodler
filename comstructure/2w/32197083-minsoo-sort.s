	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 3	sdk_version 13, 3
	.globl	_swap                           ; -- Begin function swap
	.p2align	2
_swap:                                  ; @swap
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	str	w1, [sp, #20]
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #20]
	ldr	x8, [x8, x9, lsl #3]
	str	x8, [sp, #8]
	ldr	x8, [sp, #24]
	ldr	w9, [sp, #20]
	add	w9, w9, #1
	ldr	x8, [x8, w9, sxtw #3]
	ldr	x9, [sp, #24]
	ldrsw	x10, [sp, #20]
	str	x8, [x9, x10, lsl #3]
	ldr	x8, [sp, #8]
	ldr	x9, [sp, #24]
	ldr	w10, [sp, #20]
	add	w10, w10, #1
	str	x8, [x9, w10, sxtw #3]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_sort                           ; -- Begin function sort
	.p2align	2
_sort:                                  ; @sort
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	mov	w8, #1
	str	w8, [sp, #16]
	ldr	w8, [sp, #16]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	cset	w8, lt
	tbnz	w8, #0, LBB1_2
	b	LBB1_1
LBB1_1:
	b	LBB1_14
LBB1_2:
	b	LBB1_3
LBB1_3:                                 ; =>This Loop Header: Depth=1
                                        ;     Child Loop BB1_7 Depth 2
	ldr	w8, [sp, #16]
	subs	w8, w8, #1
	str	w8, [sp, #12]
	ldr	w8, [sp, #12]
	subs	w8, w8, #0
	cset	w8, lt
	tbnz	w8, #0, LBB1_5
	b	LBB1_4
LBB1_4:                                 ;   in Loop: Header=BB1_3 Depth=1
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #12]
	ldr	x8, [x8, x9, lsl #3]
	ldur	x9, [x29, #-8]
	ldr	w10, [sp, #12]
	add	w10, w10, #1
	ldr	x9, [x9, w10, sxtw #3]
	subs	x8, x8, x9
	cset	w8, gt
	tbnz	w8, #0, LBB1_6
	b	LBB1_5
LBB1_5:                                 ;   in Loop: Header=BB1_3 Depth=1
	b	LBB1_11
LBB1_6:                                 ;   in Loop: Header=BB1_3 Depth=1
	b	LBB1_7
LBB1_7:                                 ;   Parent Loop BB1_3 Depth=1
                                        ; =>  This Inner Loop Header: Depth=2
	ldur	x0, [x29, #-8]
	ldr	w1, [sp, #12]
	bl	_swap
	ldr	w8, [sp, #12]
	subs	w8, w8, #1
	str	w8, [sp, #12]
	ldr	w8, [sp, #12]
	subs	w8, w8, #0
	cset	w8, lt
	tbnz	w8, #0, LBB1_10
	b	LBB1_8
LBB1_8:                                 ;   in Loop: Header=BB1_7 Depth=2
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #12]
	ldr	x8, [x8, x9, lsl #3]
	ldur	x9, [x29, #-8]
	ldr	w10, [sp, #12]
	add	w10, w10, #1
	ldr	x9, [x9, w10, sxtw #3]
	subs	x8, x8, x9
	cset	w8, le
	tbnz	w8, #0, LBB1_10
	b	LBB1_9
LBB1_9:                                 ;   in Loop: Header=BB1_7 Depth=2
	b	LBB1_7
LBB1_10:                                ;   in Loop: Header=BB1_3 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB1_11
LBB1_11:                                ;   in Loop: Header=BB1_3 Depth=1
	ldr	w8, [sp, #16]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_13
	b	LBB1_12
LBB1_12:                                ;   in Loop: Header=BB1_3 Depth=1
	b	LBB1_3
LBB1_13:
	b	LBB1_14
LBB1_14:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #112
	.cfi_def_cfa_offset 112
	stp	x29, x30, [sp, #96]             ; 16-byte Folded Spill
	add	x29, sp, #96
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	mov	w1, #0
	str	wzr, [sp, #36]
	add	x0, sp, #40
	str	x0, [sp, #16]                   ; 8-byte Folded Spill
	mov	x2, #48
	bl	_memset
	ldr	x0, [sp, #16]                   ; 8-byte Folded Reload
	mov	x8, #6
	str	x8, [sp, #40]
	mov	x8, #3
	str	x8, [sp, #48]
	mov	x8, #2
	str	x8, [sp, #56]
	mov	x8, #4
	str	x8, [sp, #64]
	mov	x8, #1
	str	x8, [sp, #72]
	mov	x8, #5
	str	x8, [sp, #80]
	mov	w8, #6
	str	w8, [sp, #32]
	ldr	w1, [sp, #32]
	bl	_sort
	str	wzr, [sp, #28]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #28]
	ldr	w9, [sp, #32]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB2_4
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldrsw	x9, [sp, #28]
	add	x8, sp, #40
	ldr	x8, [x8, x9, lsl #3]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	b	LBB2_3
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #28]
	add	w8, w8, #1
	str	w8, [sp, #28]
	b	LBB2_1
LBB2_4:
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB2_6
	b	LBB2_5
LBB2_5:
	bl	___stack_chk_fail
LBB2_6:
	mov	w0, #0
	ldp	x29, x30, [sp, #96]             ; 16-byte Folded Reload
	add	sp, sp, #112
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%lld "

.subsections_via_symbols
