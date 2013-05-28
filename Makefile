all: gettimeofday clock_gettime rdtsc rdtsc2


gettimeofday:
	gcc gettimeofday.c -o gday

clock_gettime:
	gcc clock_gettime.c -o cget -lrt

rdtsc:
	gcc rdtsc.c -o rdtsc -lrt

rdtsc2:
	gcc rdtsc2.c -o rdtsc2 -lrt

test:all
	./gday 1000000
	./cget 1000000
	./rdtsc 1000000
	./rdtsc2 1000000

clean:
	rm -f gday cget rdtsc rdtsc2
	
