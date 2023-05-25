all:
	gcc main2.c -o main -lGL -lglut -lGLU
	./main
	rm main
