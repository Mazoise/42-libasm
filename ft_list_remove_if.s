			global		_ft_list_remove_if
			extern		_free
			section		.text
_ft_list_remove_if:
			cmp			rdi, 0
			je			.exit
			mov			r9, rdi ; beg
.while:
			mov			r11, [rdi]
			cmp			r11, 0
			je			.exit
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
			je			.exit
			jmp			.while
.del:
			push		rsi
			push		rdx
			push		rcx
			push		r9
			mov			r8, rdi
			mov			r8, [r8]
			add			r8, 8
			mov			r8, [r8]
			mov			r11, [rdi]
			mov			[rdi], r8
			mov			rdi, r11
			push		rdi
			mov			rdi, [rdi]
			call		rcx
			pop			rdi
			push		rdi
			call		_free
			pop			rdi
			pop			r9
			pop			rcx
			pop			rdx
			pop			rsi
			mov			rdi, r9
			jmp			.while
.exit:
			ret
