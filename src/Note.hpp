#pragma once

#include <chrono>
#include <string>


struct Pitch{
    uint8_t MidiNumber;

    operator uint8_t() const;
    Pitch(const char * WrittenPitch);
    Pitch(const uint8_t MidiValue);

};

Pitch operator +(const Pitch& P, const int step);

struct Note{

    Pitch pitch;
    unsigned char velocity;
    std::chrono::milliseconds duration;

};