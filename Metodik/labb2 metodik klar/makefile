OBJ_FILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
OBJ_COMP  := g++ -Wall -O2 -s -c -std=c++20
OBJ_LINK  := g++ -Wall -O2 -s

Main: $(OBJ_FILES)
	$(OBJ_LINK) $(OBJ_FILES) -o Main

run: Main
	./Main

%.o: %.cpp
	$(OBJ_COMP) $< -o $@

clean:
	rm -f *.o Main Main.exe