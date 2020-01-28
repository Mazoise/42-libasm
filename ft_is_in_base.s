			global		_ft_is_in_base
			section		.text
_ft_is_in_base:
			mov			rax, 0
			mov			r12, 0
			mov			r12b, [rdi]
			cmp			r12b, 0
			je			.error
.while:
			cmp			byte[rsi], r12b
			je			.exit
			cmp			byte[rsi], 0
			jne			.skip
.error:
			mov			rax, -1
			ret
.skip:
			inc			rsi
			inc			rax
			jmp			.while
.exit:
			ret
