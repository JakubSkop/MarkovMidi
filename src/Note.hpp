#pragma once

#include <chrono>
#include <string>


struct Pitch{
    unsigned char MidiNumber;

    operator unsigned char() const;
    Pitch(const char * WrittenPitch);
    Pitch(unsigned char MidiValue);

};

struct Note{

    Pitch pitch;
    unsigned char velocity;
    std::chrono::milliseconds duration;

};