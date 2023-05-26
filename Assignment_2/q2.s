.global binarySearch

binarySearch:
    # %rdi -> array
    # %rsi -> left index
    # %rdx -> right index
    # %rcx -> target

    # Function prelude
    pushq   %rbp                        # save base pointer
    movq    %rsp, %rbp                  # set base pointer

    # Not needed since we need to save %rcx and %r10 across calls
    # pushq   %r10
    # pushq   %rcx

    cmpq    %rsi, %rdx                  # if left > right
    jl      .not_found                  # return -1
    je      .single_element             # if left == right, check if target

    cmpq    %rcx, (%rdi, %rsi, 8)       # if array[left] == target
    je      .found_single_element       # return left

    cmpq    %rcx, (%rdi, %rdx, 8)       # if array[right] == target
    je      .found_at_end               # return right

    movq    %rdx, %r12                  # r12 = right
    subq    %rsi, %r12                  # r12 = right - left
    cmpq    $1, %r12                    # if right - left == 1
    je      .two_elements               # subarray of two elements

    movq    %rsi, %r10                  # r10 = left
    addq    %rdx, %r10                  # r10 = left + right
    shrq    $1, %r10                    # r10 = (left + right) / 2 i.e. mid

    .L1:
        movq    (%rdi, %r10, 8), %r8        # r8 = array[mid]
        cmpq    %r8, %rcx                   
        je      .found                      # if array[mid] == target, return mid
        jl      .lesser                     # if array[mid] > target, search left
        jg      .greater                    # if array[mid] < target, search right

    # this helper function does a binary search on the left half of the array
    .lesser:
        movq    %r10, %rdx              # right = mid
        call    binarySearch            # binarySearch(array, left, right, target)
        cmpq    $-1, %rax               # if binarySearch(...) == -1
        je      .not_found              # return -1
        jne     .found                  # else return index

    # this helper function does a binary search on the right half of the array
    .greater:
        movq    %r10, %rsi              # left = mid
        call    binarySearch            # binarySearch(array, left, right, target)
        cmpq    $-1, %rax               # if binarySearch(...) == -1
        je      .not_found              # return -1
        jne     .found                  # else return index
    
    # this helper function checks if the single element is the target
    .single_element:
        cmpq    (%rdi, %rsi, 8), %rcx   # if array[left] == target
        je      .found_single_element   # return left
        jmp     .not_found              # else return -1
    
    # this helper function checks if the target is in the two element subarray
    .two_elements:
        cmpq    %rcx, (%rdi, %rsi, 8)   # if array[left] == target
        je      .found_single_element   # return left
        cmpq    %rcx, (%rdi, %rdx, 8)   # if array[right] == target
        je      .found_at_end           # return right
        jmp     .not_found              # else return -1
    
    # this helper function returns the index of the target
    .found:
        movq    %r10, %rax              # return mid
        jmp     .end
    
    # this helper function returns the index of the target
    .found_at_end:
        movq    %rdx, %rax              # return right
        jmp     .end

    # this helper function returns the index of the target
    .found_single_element:
        movq    %rsi, %rax              # return left
        jmp     .end

    # this helper function returns -1
    .not_found:
        movq    $-1, %rax               # return -1
        jmp     .end
    
    .end:
        # removed since we need to save %rcx and %r10 across calls
        # popq    %rcx
        # popq    %r10

        # Function conclude
        movq    %rbp, %rsp              # restore stack pointer 
        popq    %rbp                    # restore base pointer

        ret


