run: main.o data.o segnalazione.o queue.o BST.o gestione.o
	gcc main.o data.o segnalazione.o queue.o BST.o gestione.o -o run

main.o: src/main.c include/gestione.h include/data.h include/segnalazione.h
	gcc -c src/main.c -Iinclude

data.o: src/data.c include/data.h
	gcc -c src/data.c -Iinclude

segnalazione.o: src/segnalazione.c include/segnalazione.h include/data.h
	gcc -c src/segnalazione.c -Iinclude

queue.o: src/queue.c include/queue.h include/segnalazione.h
	gcc -c src/queue.c -Iinclude

BST.o: src/BST.c include/BST.h include/segnalazione.h
	gcc -c src/BST.c -Iinclude

gestione.o: src/gestione.c include/gestione.h include/BST.h include/queue.h
	gcc -c src/gestione.c -Iinclude

clean: 
	rm -rf *.o run