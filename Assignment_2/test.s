.global func

func:
    # %rdi -> array
    # %rsi -> array length

    movq    $0, %rax
    movq    %rsi, (%rdi, %rax, 8) # array[0] = array length
    ret













add:
    pushq   %rbp
    movq    %rsp, %rbp     # rbx register stores the value of rsp

    movq    %rdi, %rax     # rax = rdi

    addq    %rsi, %rdi     # rdi = rdi + rsi
    movq    %rdi, %rax     # rax -> return value

    movq %rbp, %rsp
    popq %rbp
    retq


