#Jared Migneco cs4760 proj6 makefile
# due 05-05-22
CC = gcc
CFLAGS = -g

all: oss.c user_proc.c

OSS: oss.c
        gcc -o oss oss.c
user_proc: user_proc.c.c
        gcc -o user_proc user_proc.c

clean:
        -rm *.o $(objects)
~
