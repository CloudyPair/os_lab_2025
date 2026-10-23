# №1

~/uni/os/os_lab_2025/lab3/src master*
❯ gcc -o sequential_min_max sequential_min_max.c find_min_max.c utils.c

~/uni/os/os_lab_2025/lab3/src master*
❯ ./sequential_min_max 123 100
min: 7523372
max: 2097911480


# №2

~/uni/os/os_lab_2025/lab3/src master*
❯ gcc -o parallel_min_max parallel_min_max.c find_min_max.c utils.c

~/uni/os/os_lab_2025/lab3/src master*
❯ ./parallel_min_max --seed 123 --array_size 100 --pnum 4
Min: 7523372
Max: 2097911480
Elapsed time: 0.700000ms

~/uni/os/os_lab_2025/lab3/src master*
❯ ./parallel_min_max --seed 123 --array_size 100 --pnum 4 --by_files
Min: 7523372
Max: 2097911480
Elapsed time: 1.142000ms


# №3

~/uni/os/os_lab_2025/lab3/src master*
❯ make sequential_min_max
gcc -o utils.o -c utils.c -I.
gcc -o find_min_max.o -c find_min_max.c -I.
gcc -o sequential_min_max find_min_max.o utils.o sequential_min_max.c -I.

~/uni/os/os_lab_2025/lab3/src master*
❯ make clean
rm -f utils.o find_min_max.o sequential_min_max parallel_min_max run_sequential

~/uni/os/os_lab_2025/lab3/src master*
❯ make all
gcc -o utils.o -c utils.c -I.
gcc -o find_min_max.o -c find_min_max.c -I.
gcc -o sequential_min_max find_min_max.o utils.o sequential_min_max.c -I.
gcc -o parallel_min_max utils.o find_min_max.o parallel_min_max.c -I.
gcc -o run_sequential run_sequential.c -I.

# №4

~/uni/os/os_lab_2025/lab3/src master*
❯ ./run_sequential 123 100
min: 7523372
max: 2097911480