			global		_ft_read
			section		.text
_ft_read:
			mov			rax, 0x02000003
			syscall
			jb			.error
			jmp			.exit
.error:
			mov			rax, -1
.exit:
			ret
