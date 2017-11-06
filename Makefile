all:
	$(CC) demo.c cunit-colorful.c -o demo -lcunit
	@echo "\e[36mFailing example:\e[0m"
	-./demo f
	@echo "\e[36mPassing example:\e[0m"
	-./demo
