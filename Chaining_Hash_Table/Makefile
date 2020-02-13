main: main.o linked.o readFile.o hashFunctions.o userInput.o hash.h
	gcc -g -o main main.o linked.o readFile.o hashFunctions.o userInput.o
main.o: main.c linked.c readFile.c hashFunctions.c userInput.c hash.h
	gcc -g -c main.c linked.c readFile.c hashFunctions.c userInput.c
linked.o: linked.c hashFunctions.c hash.h
	gcc -g -c linked.c hashFunctions.c
hashFunctions.o: hashFunctions.c hash.h linked.c
	gcc -g -c hashFunctions.c linked.c
readFile.o: readFile.c linked.c hashFunctions.c hash.h
	gcc -g -c readFile.c linked.c hashFunctions.c
userInput.o: userInput.c linked.c hashFunctions.c hash.h
	gcc -g -c userInput.c linked.c hashFunctions.c
clean:
	rm main main.o linked.o hashFunctions.o readFile.o userInput.o
