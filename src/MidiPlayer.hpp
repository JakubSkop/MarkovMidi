#pragma once

#include <iostream>
#include <memory>
#include "RtMidi.h"
#include "Note.hpp"

class MidiPlayer{
    private:
        std::unique_ptr<RtMidiOut> midiOut;
    
    public:
        MidiPlayer();
        void PlayNote(Note note) const;
        void PlayChord() const;
        void SetupMidi();
};