.global is_balanced
is_balanced:
    pushq %rbp
    movq %rsp , %rbp

    movq $0, %r11 #Loop variable
    movq $0 , %r12 #Check for the balanced thing

    .loop:
        movq (%rsi, %r11, ), %r14
        andq $0xff, %r14
        cmpq $'{', %r14
        je .push
        cmpq $'(', %r14
        je .push
        cmpq $'[', %r14
        je .push 
        jmp .next

        .push:
            pushq %r14
            incq %r12
            jmp .loopend

        .next:
            cmpq $0, %r12
            je .neq
            cmpq $'}', %r14
            je .curly
            cmpq $']', %r14
            je .sqr
            cmpq $')', %r14
            je .brac
            jmp .end

        .curly:
            popq %r15
            cmpq $'{', %r15
            je .popc
            jne .end
            .popc:
                decq %r12
                jmp .loopend
        .sqr:
            popq %r15
            cmpq $'[', %r15
            je .pops
            jne .end
            .pops:
                decq %r12
                jmp .loopend
        .brac:
            popq %r15
            cmpq $'(', %r15
            je .popb
            jne .end
            .popb:
                decq %r12
                jmp .loopend

        .loopend:
            incq %r11
            cmpq %rdi, %r11
            jne .loop
            je .end

    .end:
        cmpq $0, %r12
        je .eq
        jne .neq
        .eq:
            movq $1, %rax
            jmp .endend
        .neq:
            movq $0, %rax
            jmp .endend 
        .endend:        
        movq %rbp, %rsp
        popq %rbp
        ret
