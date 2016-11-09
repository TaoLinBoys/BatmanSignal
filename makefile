compile: Signal.c
	gcc Signal.c -o signal

run: signal
	./signal
