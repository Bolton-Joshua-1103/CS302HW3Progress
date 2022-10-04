 StackExe: driver.o 
	g++ driver.o -o StackExe
 driver.o: driver.cpp Stack.h
	g++ -c driver.cpp
 clean:
	rm *.o StackExe