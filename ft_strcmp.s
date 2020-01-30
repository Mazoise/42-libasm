			global		_ft_strcmp
			section		.text
_ft_strcmp:	
			mov		rax, 0
.while:
			mov		r13b, [rdi]
			cmp		byte [rsi], r13b
			jne		.exit_diff
			cmp		byte [rdi], 0
			je		.exit_diff
			cmp		byte [rsi], 0
			je		.exit_diff
			inc		rdi
			inc		rsi
			jmp		.while
.exit_diff:
			cmp		byte [rsi], r13b
			je		.exit_nodiff
			cmp		byte [rsi], r13b
			jg		.exit_neg
			cmp		byte [rsi], r13b
			jl		.exit_pos
.exit_pos:
			mov		rax, 1
			jmp		.exit
.exit_neg:
			mov		rax, -1
			jmp		.exit
.exit_nodiff:
			mov		rax, 0

.exit:
			ret
