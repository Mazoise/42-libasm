			global		_ft_strdup
			extern		_malloc
			extern		_ft_strcpy
			extern		_ft_strlen
			extern		_ft_strdup
			section		.text
_ft_strdup:	
			push		rdi
			call		_ft_strlen
			mov			rdi, rax
			call		_malloc
			jb			.error
			pop			rsi
			mov			rdi, rax
			call		_ft_strcpy
			jmp			.exit
.error
			mov			rax, 0
.exit
			ret
