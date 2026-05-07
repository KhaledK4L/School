CXX      = g++
CXXFLAGS = -std=c++17 -Wall
TARGET   = labb1
SRCS     = main.cpp reader.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	$(TARGET)

clean:
	del /f $(TARGET).exe svar.txt
