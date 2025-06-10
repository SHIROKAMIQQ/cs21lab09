# WINDOWS 11 SETUP

This submission did not make use of a machine that is running Linux. Rather, this submission was done on a Windows 11 machine using an MSYS2 MinGW 64-bit Shell in order to simulate multithreading via OpenMP. 

Additionally, I used `time`, which is shell-provided, in order to get the machine's execution time of each task.

# Compiling
These commands were used to compile the C files for each task:
```
gcc -O2 task1.c -o task1
gcc -O2 -mavx2 task2.c -o task2
gcc -O2 task3.c -o task3 -fopenmp
gcc -O2 -mavx2 task4.c -o task4 -fopenmp
```

# Running via shell script

I made use of the shell-provided `time` instruction in order to get execution time for running a task. I then made a shell script `execution_time.sh` which runs a task 10 times, and then gets the average run time of the runs. For example, for running task 1:
```
./execution_time.sh ./task1
```