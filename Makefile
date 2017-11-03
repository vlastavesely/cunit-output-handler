all:
	$(CC) test.c cunit-minimal.c -o test -lcunit
	./test f
	./test
