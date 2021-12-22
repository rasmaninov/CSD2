CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++14
LDFLAGS= -ljack
SOURCE=jack_module.o sine.o square.o saw.o writeToFile.o synth.o oscillator.o simplesynth.o  complex.o melodygen.o ui.o main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
