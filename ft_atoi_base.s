			global		_ft_atoi_base
			extern		_ft_is_whitespace
			extern		_ft_is_in_base
			section		.text
_ft_atoi_base:
			push		rsi
			push		rdi
			mov			r9, 1 ;len base
			mov			r10, 1 ; sign
			mov			r11, 0 ; nb
.check_base:
			cmp			byte[rsi], 0
			je			.conv
			mov			r8, rsi
			inc			r8
			cmp			byte[r8], 0
			je			.conv
			mov			rdi, rsi
			call		_ft_is_whitespace
			cmp			rax, 1
			je			.error
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
			pop			rdi
			pop			rsi
.whitespace:
			push		rdi
			call		_ft_is_whitespace
			pop			rdi
			cmp			rax, 1
			je			.skip
.sign:
			cmp			byte[rdi], 43
			je			.plus
			cmp			byte[rdi], 45
			je			.minus
.number:
			push		rdi
			push 		rsi
			call		_ft_is_in_base
			pop			rsi
			pop			rdi
			cmp			rax, -1
			je			.exit
			imul		r11, r9
			add			r11, rax
			inc			rdi
			cmp			byte[rdi], 0
			jne			.number
.exit:
			imul		r11, r10
			mov			rax, r11
			ret
.error:
			pop			rdi
			pop			rsi
.error2:
			mov			rax, 0
			ret
.skip:
			inc			rdi
			jmp			.whitespace
.plus:
			inc			rdi
			jmp			.sign
.minus:
			inc			rdi
			imul		r10, -1
			jmp			.sign
