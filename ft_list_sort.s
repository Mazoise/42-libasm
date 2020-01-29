			global		_ft_list_sort
			section		.text
_ft_list_sort:
			cmp			rdi, 0
			je			.exit
			mov			rdi, [rdi]
			mov			r8, rdi ;beg
			mov			r9, rsi ;fonction
.while:
			mov			r10, rdi
			add			rdi, 8
			mov			rdi, [rdi]
			cmp			rdi, 0
			je			.exit
			mov			r11, rdi
			push		rdi
			mov			rdi, [r11]
			mov			rsi, [r10]
			call		r9
			pop			rdi
			cmp			rax, 0
			jl			.swap
			jmp			.while
.exit:
			mov			rax, r13
			ret
.swap:
			mov			r12, [r10]
			mov			r13, [r11]
			mov			[r10], r13
			mov			[r11], r12
			mov			rdi, r8
			jmp			.while