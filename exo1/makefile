CC    = gcc
RM    = rm -Rf
SRC   = ./exo1.c 
CFLAGS= -Wall -Werror -ggdb
LFLAGS=
EXEC  = demo.exe 
OBJ  := $(SRC:.c=.o) 

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS) 


$(EXEC):$(OBJ)
	$(CC) -o $(EXEC) $^ $(LFLAGS) 


clean:
	$(RM) $(EXEC)
