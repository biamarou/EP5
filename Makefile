CC:=gcc
CFLAGS:=-Wall -pedantic -ansi -g 

ep5: hex.c simulaBrancas.c simulaPretas.c simulaMovimento.c vetorJogadas.c
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o