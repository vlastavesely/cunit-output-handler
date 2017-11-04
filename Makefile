all:
	$(CC) test.c cunit-colorful.c -o test -lcunit
	-./test f
	-./test
