
all: bof bof2 uaf
	
bof:
	gcc -fno-stack-protector bof.c -o bof -m32

bof2:
	gcc -fno-stack-protector bof2.c -o bof2 -m32

uaf:
	gcc uaf.c -o uaf
clean:
	rm uaf bof bof2
