all: gettimeofday clock_gettime rdtsc


gettimeofday:
	gcc gettimeofday.c -o gday

clock_gettime:
	gcc clock_gettime.c -o cget -lrt

rdtsc:
	gcc rdtsc.c -o rdtsc -lrt


test:all
	./gday 1000000
	./cget 1000000
	./rdtsc 1000000

clean:
	rm -f gday cget rdtsc
	
