	.file	"template_model_test.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN4testIdE5printEd,"axG",@progbits,_ZN4testIdE5printEd,comdat
	.align 2
	.weak	_ZN4testIdE5printEd
	.type	_ZN4testIdE5printEd, @function
_ZN4testIdE5printEd:
.LFB1022:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEd
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1022:
	.size	_ZN4testIdE5printEd, .-_ZN4testIdE5printEd
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1029:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L2
	cmpl	$65535, -8(%rbp)
	jne	.L2
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L2:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1029:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_template_model_test.cpp, @function
_GLOBAL__sub_I_template_model_test.cpp:
.LFB1030:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1030:
	.size	_GLOBAL__sub_I_template_model_test.cpp, .-_GLOBAL__sub_I_template_model_test.cpp
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_template_model_test.cpp
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 4.9.0"
	.section	.note.GNU-stack,"",@progbits
