#include <iostream>
#include <memory>
#include "RtMidi.h"
#include "Note.hpp"

#pragma once

class MidiPlayer{
    private:
        std::unique_ptr<RtMidiOut> midiOut;
    
    public:
        MidiPlayer();
        void PlayNote(Note note) const;
        void PlayChord() const;
        void SetupMidi();
};