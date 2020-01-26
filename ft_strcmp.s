			global		_ft_strcmp
			section		.text
_ft_strcmp:	
			mov		rax, 0
.while:
			mov		dl, [rdi]
			cmp		byte [rsi], dl
			jne		.exit_diff
			cmp		byte [rdi], 0
			je		.exit_diff
			cmp		byte [rsi], 0
			je		.exit_diff
			inc		rdi
			inc		rsi
			jmp		.while
.exit_diff:
			cmp		byte [rsi], dl
			je		.exit_nodiff
			cmp		byte [rsi], dl
			jg		.exit_neg
			cmp		byte [rsi], dl
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
