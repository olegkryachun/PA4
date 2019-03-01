pa4: pa4.c function.o shortFuncs.o loop.o stuff.h
	gcc -o pa4 pa4.o function.o shortFuncs.o loop.o -g
function.o: function.c stuff.h
	gcc -c function.c
shortFuncs.o: shortFuncs.c stuff.h
	gcc -c shortFuncs.c
loop.o: loop.c stuff.h
	gcc -c loop.c

