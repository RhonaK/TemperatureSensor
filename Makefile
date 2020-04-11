all: 	TempSensorTest.cpp
	g++ -Wall TempSensorTest.cpp -o TempTest
clean:
	rm -rf TempTest