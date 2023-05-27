#include <chrono>
#include <memory>
#include <thread>
#include "Initialization.hpp"
#include "Note.hpp"
#include "MidiPlayer.hpp"
#include <iostream>


MidiPlayer::MidiPlayer(){
    midiOut = InitializeMidiOut();
    std::cout << "No. of Available Ports:" << midiOut->getPortCount() << "\n";
    midiOut->openPort(1,"C++Port");
};

void MidiPlayer::PlayNote(Note note) const{
    std::vector<unsigned char> message;
    message.push_back(144); //Note On Midi Message
    message.push_back(note.pitch);
    message.push_back(note.velocity);
    midiOut->sendMessage( &message );
    std::this_thread::sleep_for(note.duration); 
    // Note Off: 128, 64, 40
    message[0] = 128; //Note Off Midi Message
    message[1] = note.pitch;
    message[2] = note.velocity/2; //Velocity with which current Note should be removed
    midiOut->sendMessage( &message );
};

void MidiPlayer::SetupMidi(){
    // Send out a series of MIDI messages.
    // Program change: 192, 5
    std::vector<unsigned char> message;
    message.push_back( 192 );
    message.push_back( 5 );
    midiOut->sendMessage( &message );
    // Control Change: 176, 7, 100 (volume)
    message[0] = 176;
    message[1] = 7;
    message.push_back( 100 );
    midiOut->sendMessage( &message );
};
