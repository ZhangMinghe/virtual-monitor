/*
    VirtualMonitor.cpp
    Main file for controlling the virtual monitor.
*/

#include "VirtualMonitor.h"

#include <signal.h>
#include <cstdlib>
#include <iostream>

#include "InteractionDetector.h"

using namespace virtualMonitor;

// Signal handlers
bool global_shutdown;
void sigintHandler(int s) {
    global_shutdown = true;
}

// Main
int main(int argc, char *argv[]) {
    global_shutdown = false;
    signal(SIGINT, sigintHandler);

    InteractionDetector *interactionDetector = new InteractionDetector();

#ifdef VIRTUALMONITOR_TEST_INPUTS
    // Use test inputs for interaction detection
    interactionDetector->testDetectInteraction();
#else
    // Use the Kinect sensor for continuous interaction detection
    bool displayViewer = false;
#ifdef VIRTUALMONITOR_VIEWER
    displayViewer = true;
#endif
    interactionDetector->start(displayViewer);
    while (!global_shutdown) {
        Interaction *interaction = interactionDetector->detectInteraction();
        if (interaction == NULL) {
            global_shutdown = true;
        }
    }
    interactionDetector->stop();
#endif

    delete interactionDetector;
    return 0;
}
