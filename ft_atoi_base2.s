			global		_ft_atoi_base
			; extern		_ft_is_whitespace
			; extern		_ft_is_in_base
			section		.text
_ft_atoi_base:
			; push		rsi
			; push		rdi
			mov			r9, 1 ;len base
.check_base:
			cmp			byte[rsi], 0
			je			.conv
			mov			r8, rsi
			inc			r8
			cmp			byte[r8], 0
			je			.conv
			; mov			rdi, rsi
			mov			rax, 0
			; call		_ft_is_whitespace
			; cmp			rax, 1
			jmp			.exit
			; je			.error
			cmp			byte[rsi], 43
			je			.error
			cmp			byte[rsi], 45
			je			.error
.while:
			mov			r13, 0
			mov			r13b, [rsi]
			cmp			byte [r8], r13b
			je			.error
			inc			r8
			cmp			byte[r8], 0
			jne			.while
			inc			rsi
			inc			r9
			jmp			.check_base
.conv:
			cmp			r9, 2
			jl			.error
			; pop			rdi
			; pop			rsi

			mov rax, -1
			; mov			rax, r9
			ret
.error:
			; pop			rdi
			; pop			rsi
.error2:
			mov			rax, 0
			ret

.exit:
			ret;
