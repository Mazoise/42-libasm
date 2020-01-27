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
			inc			rax
			call		_malloc
			cmp			rax, 0			
			je			.exit
			pop			rsi
			mov			rdi, rax
			call		_ft_strcpy
			jmp			.exit
.exit
			ret
