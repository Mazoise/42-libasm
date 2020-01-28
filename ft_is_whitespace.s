			global		_ft_is_whitespace
			section		.text
_ft_is_whitespace:
			mov			rax, 0
			cmp			byte[rdi], 9
			je			.exit
			cmp			byte[rdi], 10
			je			.exit
			cmp			byte[rdi], 11
			je			.exit
			cmp			byte[rdi], 12
			je			.exit
			cmp			byte[rdi], 13
			je			.exit
			cmp			byte[rdi], 32
			je			.exit
			mov			rax, 0
			ret
.exit:
			mov			rax, 1
			ret
