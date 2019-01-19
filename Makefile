TARGET = tp1
OBJECTS = lista_adj.o fila.o grafo.o fluxo.o main.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

defaulf: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

lista_adj.o: lista_adj.c lista_adj.h
	$(CC) $(CFLAGS) -c lista_adj.c

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c fila.c

grafo.o: grafo.c grafo.h lista_adj.h
	$(CC) $(CFLAGS) -c grafo.c

fluxo.o: fluxo.c fluxo.h grafo.h fila.h lista_adj.h
	$(CC) $(CFLAGS) -c fluxo.c	

main.o: main.c fluxo.h grafo.h
	$(CC) $(CFLAGS) -c main.c

clean:
	-rm -f *.o