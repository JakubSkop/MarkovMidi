#include <iostream>
#include <memory>
#include "RtMidi.h"
#include "Initialization.hpp"
std::unique_ptr<RtMidiOut> InitializeMidiOut()
{
    std::unique_ptr<RtMidiOut> midiout = nullptr;
    // RtMidiOut constructor
    try {
        midiout = std::make_unique<RtMidiOut>();
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
    }
    return midiout;
}

std::unique_ptr<RtMidiIn> InitializeMidiIn()
{
    std::unique_ptr<RtMidiIn> midiIn = nullptr;
    // RtMidiIn constructor
    try {
        midiIn = std::make_unique<RtMidiIn>();
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
    }
    return midiIn;
}