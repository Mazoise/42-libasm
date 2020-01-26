			global		_ft_strcpy
			section		.text
_ft_strcpy:
			mov		rax, rdi
.while:
			cmp		byte [rsi], 0
			je		.exit
			mov		dl, byte [rsi]
			mov		byte [rdi], dl
			inc		rsi
			inc		rdi
			jmp		.while
.exit:
			mov		byte [rdi], 0
			ret
