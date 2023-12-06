.global add

add:
    # Caller
    # Caller saved registers: rax, rcx, rdx, rsi, rdi, r8, r9, r10, r11

    ####################
    # Genral convention - Prelude of a function
    pushq %rbp
    movq %rsp, %rbp     # rbx register stores the value of rsp
    ####################

    movq $4, %rbx
    pushq %rbx          # rbx register stored inn stack
    call actual_add
    popq %rbx           # rbx register restored from stack, hence value of rbx is not modified by actual_add
    addq %rbx, %rax

    ####################
    # Genral convention - Conclude of a function
    movq %rbp, %rsp
    popq %rbp
    ####################
    ret

actual_add:
    # Callee
    # Callee saved registers: rbx, rbp, r12, r13, r14, r15
    pushq %rbp
    pushq %rax
    pushq %rbx
    
    movq %rdi, %rax
    addq %rsi, %rax
    movq $2, %rbx

    popq %rbx
    popq %rax
    popq %rbp
    ret

