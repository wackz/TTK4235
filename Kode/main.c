#include "elev.h"
#include <stdio.h>
#include "heis.h"


int main() {
    // Initialize hardware
    if (!elev_init()) {
		//printSystemMessage("boot", "could not initialize driver");
        return 1;
    }

	mainElevatorLoop();
    return 0;
}
