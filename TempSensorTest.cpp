/*
 * Author: Rona Kosumi
 * March 2020
 */
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

char path[47];
float getTemp();

int main() {
    ofstream file;
    file.open("TemperatureData.txt");
    
    char* address_ = strdup("28-01191ba87a9b"); //This changes if you change the device!
	snprintf(path, 46, "%s%s%s", "/sys/bus/w1/devices/", address_, "/w1_slave");
    
    double tempNow;
    
    
    while(true)
    {
        tempNow = getTemp();
        cout << "The current temperature is " << tempNow << " *C" <<endl;
        char buf[7];
        sprintf(buf, "%0.3f", tempNow);
        file << buf << endl;
    }
    file.close();
    return 0;
}


float getTemp() {
	FILE *devFile = fopen(path, "r");
	if (devFile == NULL) {
		printf("Count not open %s\n", path);
		perror("\n");
	}
	float temp = -1;
	if (devFile != NULL) {
		if (!ferror(devFile)) {
			unsigned int tempInt;
			char crcConf[5];
			fscanf(devFile, "%*x %*x %*x %*x %*x %*x %*x %*x %*x : crc=%*x %s", crcConf);
			if (strncmp(crcConf, "YES", 3) == 0) {
				fscanf(devFile, "%*x %*x %*x %*x %*x %*x %*x %*x %*x t=%5d", &tempInt);
				temp = (float) tempInt / 1000.0;
			}
		}
	}
	fclose(devFile);
    return temp;
}
