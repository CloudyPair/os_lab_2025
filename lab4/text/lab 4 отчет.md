# №1

~/uni/os/os_lab_2025/lab4/src master*
❯ ./parallel_min_max --seed 123 --array_size 100 --pnum 4
Min: 7523372
Max: 2097911480
Elapsed time: 0.671000ms

~/uni/os/os_lab_2025/lab4/src master*
❯ ./parallel_min_max --seed 123 --array_size 100 --pnum 4 --timeout 5
Min: 7523372
Max: 2097911480
Elapsed time: 0.749000ms

~/uni/os/os_lab_2025/lab4/src master*
❯ ./parallel_min_max --seed 123 --array_size 100 --pnum 4 --by_files --timeout 5
Min: 7523372
Max: 2097911480
Elapsed time: 1.213000ms

# №2

~/uni/os/os_lab_2025/lab4/src master*
❯ make zombie
gcc -o zombie zombie.c -I.

~/uni/os/os_lab_2025/lab4/src master*
❯ ./zombie
Parent PID: 757367, child PID: 757368

вовремя sleep во втором терминале:

~/uni/os/os_lab_2025 master*
❯ ps -o pid,ppid,stat,cmd -C zombie
    PID    PPID STAT CMD
 757367  654642 S<+  ./zombie
 757368  757367 Z<+  [zombie] <defunct>

# №3

~/uni/os/os_lab_2025/lab4/src master* 30s
❯ make process_memory
gcc -std=gnu89 -o process_memory process_memory.c -I.

~/uni/os/os_lab_2025/lab4/src master*
❯ ./process_memory

Address etext: E7607459 
Address edata: E760A060 
Address end  : E760A090 
ID main          is at virtual address: E76071B9
ID showit        is at virtual address: E7607362
ID cptr          is at virtual address: E760A058
ID buffer1       is at virtual address: E760A070
ID i     is at virtual address: 15FDF8C4
A demonstration
ID buffer2       is at virtual address: 15FDF8A0
Alocated memory at FBA80420
This message is output by the function showit()


~/uni/os/os_lab_2025/lab4/src master*
❯ ./process_memory

Address etext: 0x5628f01af459 
Address edata: 0x5628f01b2060 
Address end  : 0x5628f01b2090 
ID main          is at virtual address: 0x5628f01af1b9
ID showit        is at virtual address: 0x5628f01af362
ID cptr          is at virtual address: 0x5628f01b2058
ID buffer1       is at virtual address: 0x5628f01b2070
ID i     is at virtual address: 0x7ffc9385b6a4
A demonstration
ID buffer2       is at virtual address: 0x7ffc9385b680
Alocated memory at 0x562926c61420
This message is output by the function showit()

# №4

~/uni/os/os_lab_2025/lab4/src master*
❯ make clean
rm -f utils.o find_min_max.o sum.o libsum.a parallel_min_max process_memory zombie psum

~/uni/os/os_lab_2025/lab4/src master*
❯ make parallel_min_max process_memory
gcc -o utils.o -c utils.c -I.
gcc -o find_min_max.o -c find_min_max.c -I.
gcc -o parallel_min_max utils.o find_min_max.o parallel_min_max.c -I.
gcc -std=gnu89 -o process_memory process_memory.c -I.

# №5

~/uni/os/os_lab_2025/lab4/src master*
❯ ./psum --threads_num 1 --seed 5 --array_size 10000000
Total: 10736305130812854
Elapsed time: 43.316000ms

~/uni/os/os_lab_2025/lab4/src master*
❯ ./psum --threads_num 4 --seed 5 --array_size 10000000
Total: 10736305130812854
Elapsed time: 10.683000ms

~/uni/os/os_lab_2025/lab4/src master*
❯ ./psum --threads_num 8 --seed 5 --array_size 10000000
Total: 10736305130812854
Elapsed time: 7.970000ms


# №6

~/uni/os/os_lab_2025/lab4/src master*
❯ make clean
rm -f utils.o find_min_max.o sum.o libsum.a parallel_min_max process_memory zombie psum

~/uni/os/os_lab_2025/lab4/src master*
❯ make psum
gcc -o utils.o -c utils.c -I.
gcc -o sum.o -c sum.c -I.
ar rcs libsum.a sum.o
gcc -o psum utils.o parallel_sum.c -L. -lsum -lpthread -I.
