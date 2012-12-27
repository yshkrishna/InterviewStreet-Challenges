INCDIRS=-I/home/matt/Documents/boost_1_45_0
LFLAGS=-lboost_program_options
CFLAGS=-Wall -Wshadow -Wredundant-decls $(INCDIRS)

BIN=results

# CLASSES_IMPLEMENTED=\
#	SaveHumanity.o

Solution: SaveHumanity.cpp
	g++ $(CFLAGS) -o $(BIN) $^ $(LFLAGS)

clean:
	rm -f *.o

realclean: clean
	rm -f $(BIN)
