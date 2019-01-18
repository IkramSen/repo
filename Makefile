## Premier exemple de Makefile

summ:		psomme.c ptime.c pmain.c ptime.h psomme.h
		gcc -o summ -O3 psomme.c ptime.c pmain.c  -lpthread

summ.db:	psomme.c ptime.c pmain.c ptime.h psomme.h
		gcc -o summ.db -g -O3 psomme.c ptime.c pmain.c 
