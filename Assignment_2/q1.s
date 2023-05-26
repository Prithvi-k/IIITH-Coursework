.global is_balanced

is_balanced:
        pushq   %rbp
        movq    %rsp, %rbp     # rbx register stores the value of rsp

        # rdi -> n, string length
        # rsi -> s, string pointer
        movq    $0, %r8         # r8 -> counter

        movq    $0, %rax

        sub     $8, %rsp
        
        xor     %edx, %edx

        .L1:
            cmpq    $0, %rdi
            jle      .L2

            movb    (%rsi), %dl

            cmp     $'{', %dl
            jz .open_parenthesis

            cmp     $'[', %dl
            jz .open_parenthesis

            cmp     $'(', %dl
            jz .open_parenthesis

            cmp     $'}', %dl
            jz .closed_parenthesis

            cmp     $']', %dl
            jz .closed_parenthesis

            cmp     $')', %dl
            jz .closed_parenthesis
            
            addq    $1, %rsi
            decq    %rsi
            jmp     .L1

        .open_parenthesis:
            pushq   %rdx
            addq    $1, %rsi
            decq    %rsi
            incq    %r8
            jmp     .L1
        
        .closed_parenthesis:
            cmpq    $0, %r8
            jle      .L3
            popq    %rax
            cmp     %al, %dl
            jne     .L3
            addq    $1, %rsi
            decq    %rsi
            decq    %r8
            jmp     .L1


        .L2:
            cmpq    $0, %r8
            jne     .L3
            movq $1, %rax
            movq %rbp, %rsp
            popq %rbp
            ret 

        .L3:
            movq $0, %rax
            movq %rbp, %rsp
            popq %rbp
            ret        

