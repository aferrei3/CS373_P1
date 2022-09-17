all: ferreira_p1

ferreira_p1: ferreira_p1.o State.o FSM.o
	g++ ferreira_p1.o State.o FSM.o -o ferreira_p1

ferreira_p1.o: ferreira_p1.cpp
	g++ -c ferreira_p1.cpp

State.o: State.cpp State.h
	g++ -c State.cpp
	
FSM.o: FSM.cpp FSM.h State.h
	g++ -c FSM.cpp

clean:
	rm ferreira_p1 *.o
	
