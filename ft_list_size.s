			global		_ft_list_size
			extern		_malloc
			section		.text
_ft_list_size:
			mov			rax, 0
			cmp			rdi, 0
			je			.exit
.while:
			inc			rax
			add			rdi, 8
			cmp			byte [rdi], 0
			je			.exit
			mov			rdi, [rdi]
			jmp			.while
.exit:
			ret
