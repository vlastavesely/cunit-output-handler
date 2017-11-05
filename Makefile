all:
	$(CC) demo.c cunit-colorful.c -o demo -lcunit
	-./demo f
	-./demo
