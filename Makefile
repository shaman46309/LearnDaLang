CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++0x # also known as c++11

OBJS =		LearnDaLang.o case1.o case2.o case3.o

LIBS =

TARGET =	LearnDaLang

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
