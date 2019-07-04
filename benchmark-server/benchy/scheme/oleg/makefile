CC=cl
OPT=-EHsc

#CC=g++
#OPT=-std=c++14

all: key.exe test.exe

key.exe: key.cpp *.h
	$(CC) $(OPT) $<
	rm -f *.obj

test.exe: main.cpp oleg.cpp *.h
	$(CC) $(OPT) main.cpp oleg.cpp -o $@
	rm -f *.obj


clean c:
	rm -f *.exe *.o *.obj *.key
