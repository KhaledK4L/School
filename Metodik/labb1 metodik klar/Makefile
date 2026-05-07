OBJ_FILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
OBJ_COMP  := g++ -Wall -O2 -s -c
OBJ_LINK  := g++ -Wall -O2 -s

Merge: $(OBJ_FILES)
	$(OBJ_LINK) $(OBJ_FILES) -o Merge

run: Merge
	./Merge

%.o: %.cpp
	$(OBJ_COMP) $< -o $@

clean:
	rm -f *.o Merge Merge.exe
