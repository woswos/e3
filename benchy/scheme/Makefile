CC        = g++
FLAGS     = -std=c++14
INCLUDES  = -I tfhe_unx/inc/tfhe
LIBRARIES = tfhe_unx/libtfhe.a tfhe_unx/libfftw3.a

all: scheme

%: %.cpp
	$(CC) $(FLAGS) $(INCLUDES) $@.cpp $(LIBRARIES) -o $@.exe


clean:
	rm *.o || true
	rm *.exe || true
	rm *.key || true
	rm *.data || true
