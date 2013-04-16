CC    = gcc
RM    = rm -Rf
SRC   = ./exo2.c 
CFLAGS= -Wall -Werror -ggdb
LFLAGS= -ggdb
EXEC  = demo2 
OBJ  := $(SRC:.c=.o) 

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS) 


$(EXEC):$(OBJ)
	$(CC) -o $(EXEC) $^ $(LFLAGS) 

clean:
	$(RM) $(EXEC)
