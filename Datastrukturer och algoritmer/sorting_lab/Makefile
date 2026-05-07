CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic

OBJS = main.o sorting.o data_gen.o stats.o report.o experiment.o

sorting_lab: $(OBJS)
	$(CXX) $(CXXFLAGS) -o sorting_lab $(OBJS)

main.o: main.cpp experiment.h report.h
	$(CXX) $(CXXFLAGS) -c main.cpp

sorting.o: sorting.cpp sorting.h
	$(CXX) $(CXXFLAGS) -c sorting.cpp

data_gen.o: data_gen.cpp data_gen.h
	$(CXX) $(CXXFLAGS) -c data_gen.cpp

stats.o: stats.cpp stats.h
	$(CXX) $(CXXFLAGS) -c stats.cpp

report.o: report.cpp report.h stats.h
	$(CXX) $(CXXFLAGS) -c report.cpp

experiment.o: experiment.cpp experiment.h sorting.h data_gen.h stats.h
	$(CXX) $(CXXFLAGS) -c experiment.cpp

clean:
	rm -f *.o sorting_lab
