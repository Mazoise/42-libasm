			global		_ft_list_push_front
			extern		_malloc
			section		.text
_ft_list_push_front:
			push		rdi
			push		rsi
			mov			rdi, 16
			call		_malloc
			cmp			rax, 0
			je			.error
			pop			rsi
			pop			rdi
			mov			[rax], rsi
			mov			r8, [rdi]
			mov			[rdi], rax
			add			rax, 8
			mov			[rax], r8
			ret
.error:
			ret
