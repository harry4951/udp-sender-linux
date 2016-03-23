CC = gcc
LIBS = 
OBJ = udp_sender.o

test: $(OBJ)
	$(CC) udp_sender.c -o udp_sender $(LIBS)


clean:
	rm -f *.o

 
run:
	./udp_sender 192.168.56.2 8888

