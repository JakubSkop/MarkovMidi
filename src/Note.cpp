#include "Note.hpp"
#include <iostream>
#include <string>

Pitch::operator unsigned char() const{
    return MidiNumber;
};

Pitch::Pitch(unsigned char MidiValue){
    MidiNumber = MidiValue;
}

Pitch::Pitch(const char * WrittenPitch){
    unsigned char baseNote;
    switch(WrittenPitch[0]){
        case 'C':
            baseNote = 0;
            break;
        case 'D':
            baseNote = 2;
            break;
        case 'E':
            baseNote = 4;
            break;
        case 'F':
            baseNote = 5;
            break;
        case 'G':
            baseNote = 7;
            break;
        case 'A':
            baseNote = 9;
            break;
        case 'B':
            baseNote = 11;
            break;
    };

    {
        unsigned int i;
        for(i=1; WrittenPitch[i] != '\0'; i++){
            switch(WrittenPitch[i]){
            case '#':
                baseNote++;
                break;
            case 'b':
                baseNote--;
                break;
            };
        };

        unsigned char octave = WrittenPitch[i-1] - 48;
        baseNote += (octave * 12);
    }

    MidiNumber = baseNote;
    //std::cout << MidiNumber;

};