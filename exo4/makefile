CC    = gcc
RM    = rm -Rf
SRC   = ./exo4.c 
CFLAGS= -Wall -Werror -ggdb
LFLAGS= -ggdb
EXEC  = demo4
OBJ  := $(SRC:.c=.o) 

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS) 


$(EXEC):$(OBJ)
	$(CC) -o $(EXEC) $^ $(LFLAGS) 

clean:
	$(RM) $(EXEC)
