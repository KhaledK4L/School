OBJ_FILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
OBJ_COMP  := g++ -Wall -O2 -s -c
OBJ_LINK  := g++ -Wall -O2 -s

Main: $(OBJ_FILES)
	$(OBJ_LINK) $(OBJ_FILES) -o email

run: email
	./email

%.o: %.cpp
	$(OBJ_COMP) $< -o $@

clean:
	rm -f *.o email email.exe