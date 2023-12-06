.global main

main:
    movq %rsp, %r9
    push $2
    push $4
    push $10
    movq (%rsp), %rax       # rax = 10
    addq 8(%rsp), %rax      # rax = 10 + 4 = 14
    addq 16(%rsp), %rax     # rax = 14 + 2 = 16
    pop %rbp
    pop %rbp
    pop %rbp
    movq %r9, %rsp
    ret


