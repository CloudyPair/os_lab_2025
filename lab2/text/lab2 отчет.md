# №1

~/uni/os/os_lab_2025/lab2/src/swap master*
❯ gcc main.c swap.c -o swap

~/uni/os/os_lab_2025/lab2/src/swap master*
❯ ./swap
b a


# №2

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ gcc main.c revert_string.c -o program

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ ./program abc123
Reverted: 321cba


# №3

Статическая библиотека

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ gcc -c revert_string.c -o revert_string.o

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ ar rcs librevert_string.a revert_string.o

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ gcc main.c -L. -lrevert_string -o revert_static

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ ./revert_static abc123
Reverted: 321cba


Динамическая библиотека

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ gcc -fPIC -c revert_string.c -o revert_string.o

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ gcc -shared -o librevert_string.so revert_string.o

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ gcc main.c -L. -lrevert_string -o revert_dynamic

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ export LD_LIBRARY_PATH=.

~/uni/os/os_lab_2025/lab2/src/revert_string master*
❯ ./revert_dynamic abc123
Reverted: 321cba