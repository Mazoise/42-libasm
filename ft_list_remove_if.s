			global		_ft_list_remove_if
			extern		_free
			section		.text
_ft_list_remove_if:
			cmp			rdi, 0
			je			.exit
			mov			r9, rdi ; beg
			; rdx, rcx
.while:
			push		rdi
			push		rsi
			push		rdx
			push		rcx
			push		r9
			mov			rdi, [rdi]
			mov			rdi, [rdi]
			call		rdx
			pop			r9
			pop			rcx
			pop			rdx
			pop			rsi
			pop			rdi
			cmp			rax, 0
			je			.del
			mov			rdi, [rdi]
			add			rdi, 8
			mov			r9, [rdi]
			cmp			r9, 0
			je			.exit
			jmp			.while
.del:
			push		rsi
			push		rdx
			push		rcx
			push		r9
			push		rdi
			mov			rdi, [rdi]
			mov			r8, rdi
			add			r8, 8
			mov			r8, [r8]
			mov			rdi, [rdi]
			push		r8
			call		rcx
			pop			r8
			pop			rdi
			push		rdi
			push		r8
			mov			rdi, [rdi]
			call		_free
			pop			r8
			pop			rdi
			pop			r9
			pop			rcx
			pop			rdx
			pop			rsi
			mov			[rdi], r8
			mov			rdi, r9
			jmp			.exit
.exit:
			ret
