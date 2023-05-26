.global divide

divide:
    #m = % rdi, n = % rsi, arr = % rdx
    cmpq $0, %rsi
    je checkzero
    movq $0, %r15           # r15 is for q
    cmpq $0, %rdi           
    jl negm
    cmpq $0, %rsi
    jl posmnegn
    jmp posmposn

checkzero:
    movq $-1, %rdx
    addq $8, %rdx
    movq $-1, %rdx
    ret

negm:
    cmpq $0, %rsi
    jl negmnegn
    jmp negmposn


posmposn:
    cmpq $0, %rdi
    jl endie
    incq %r15
    subq %rsi, %rdi
    jmp posmposn


posmnegn:
    cmpq $0, %rdi
    jl endie
    decq %r15
    addq %rsi, %rdi
    jmp posmnegn
    

negmposn:
    cmpq $0, %rdi
    jg endie
    decq %r15
    addq %rsi, %rdi
    jmp negmposn


negmnegn:
    neg %rdi
    neg %rsi
    jmp loop

loop:
    cmpq $0, %rdi
    jl endie
    incq %r15
    subq %rsi, %rdi
    jmp loop

endie:
    movq %r15, (%rdx)
    addq $8, %rdx
    movq %rdi, (%rdx)
    ret
