.global compute_result

compute_result:
    # %rdi -> size of array
    # %rsi -> size of sliding window
    # %rdx -> array

    movq    $0, %r8                     # %r8 -> i
    movq    $0, %r9                     # %r9 -> arr[i]

    movq    $0, %r10                    # current window sum
    movq    $0, %r11                    # max window sum

    cmpq    $0, %rdi                    # if size of array == 0
    je      .end                        # jump to end

    cmpq    $0, %rsi                    # if size of window == 0
    je      .end                        # jump to end

    cmpq    %rdi, %rsi                  # if size of window > size of array
    jg      .smaller_than_window        # jump to end
    jmp     .initial_window             # jump to initial window

    .smaller_than_window:
        cmpq    %r8, %rdi               # i < size
        jle     .end                    # if not, jump to end

        movq    (%rdx, %r8, 8), %r9     # arr[i]
        addq    %r9, %r11               # current window sum += arr[i]
        incq    %r8                     # i++
        jmp     .smaller_than_window         # jump to initial window

    .initial_window:
        cmpq    %rsi, %r8               # i < window size
        jge     .window_loop            # if not, jump to window loop

        movq    (%rdx, %r8, 8), %r9     # arr[i]
        addq    %r9, %r10               # current window sum += arr[i]
        incq    %r8                     # i++
        jmp     .initial_window         # jump to initial window

    .window_loop:
        cmpq    %rdi, %rsi
        je      .array_same_size_as_window

        movq    %r10, %r11              # max window sum = current window sum

        movq    %rdi, %r12              # %r12 -> j : tracks element to be added
        decq    %r12                    # j--
        decq    %r8                     # i-- : Now tracks element to be removed

    .compute_remaining_windows:
        cmpq    $0, %r8                 # if i == 0
        jl      .end                    # jump to end

        movq    (%rdx, %r8, 8), %r9     # arr[i]
        subq    %r9, %r10               # current window sum -= arr[i]
        movq    (%rdx, %r12, 8), %r9    # arr[j]
        addq    %r9, %r10               # current window sum += arr[j]

        cmpq    %r10, %r11              # if current window sum > max window sum
        jge     .next_iteration         # jump to next iteration

        movq    %r10, %r11              # max window sum = current window sum

    .next_iteration:
        decq    %r12                    # j--
        decq    %r8                     # i--
        jmp     .compute_remaining_windows


    .array_same_size_as_window:
        movq    %r10, %r11              # max window sum = current window sum
        jmp     .end

    .end:
        movq    %r11, %rax              # return max window sum
        ret












