driver:	driver.o log.o
	cc -o $@ driver.o log.o

driver.o: driver.c log.h 
	cc -c driver.c

log.o: log.c log.h
	cc -c log.c

clean:
	rm *.o driver
