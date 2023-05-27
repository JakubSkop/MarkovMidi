#include <iostream>
#include <memory>
#include "MidiPlayer.hpp"
#include "Note.hpp"
#include "Markov.hpp"
#include "MusicalFunctions.hpp"
#include <memory>

int main()
{
    using namespace std::chrono_literals;
    using statePtr = std::shared_ptr<MarkovState>;
    using chainPtr = std::shared_ptr<MarkovChain>;

    std::shared_ptr<MidiPlayer> MyPlayer = std::make_shared<MidiPlayer>();

    std::vector<statePtr> Scale1{};
    Scale1.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"C4",100,200ms})));
    Scale1.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"Eb4",100,200ms})));
    Scale1.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"G4",100,200ms})));
    Scale1.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"G4",100,200ms})));
    Scale1.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"C5",100,200ms})));

    std::vector<statePtr> Scale2{};
    Scale2.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"D4",100,200ms})));
    Scale2.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"F4",100,200ms})));
    Scale2.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"G4",100,200ms})));
    Scale2.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"B4",100,200ms})));
    Scale2.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"D5",100,200ms})));

    std::vector<statePtr> Scale3{};
    Scale3.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"Eb4",100,200ms})));
    Scale3.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"Eb4",100,200ms})));
    Scale3.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"G4",100,200ms})));
    Scale3.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"Bb4",100,200ms})));
    Scale3.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"Eb5",100,200ms})));

    std::vector<statePtr> Scale4{};
    Scale4.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"Ab3",100,200ms})));
    Scale4.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"C4",100,200ms})));
    Scale4.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"Eb4",100,200ms})));
    Scale4.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"Ab4",100,200ms})));
    Scale4.push_back(std::make_shared<MarkovState>(NotePlayFunctionCreator(MyPlayer, {"Ab4",100,200ms})));


    chainPtr M1 = std::make_shared<Markov1>();
    M1->Initialize(Scale1);
    
    chainPtr M2 = std::make_shared<Markov1>();
    M2->Initialize(Scale4);

    chainPtr M3 = std::make_shared<Markov1>();
    M3->Initialize(Scale3);
    
    chainPtr M4 = std::make_shared<Markov1>();
    M4->Initialize(Scale2);

    std::vector<statePtr> Chords{};
    Chords.push_back(std::make_shared<MarkovState>(CountedMarkovFunctionCreator(M1,16)));
    Chords.push_back(std::make_shared<MarkovState>(CountedMarkovFunctionCreator(M2,16)));
    Chords.push_back(std::make_shared<MarkovState>(CountedMarkovFunctionCreator(M3,16)));
    Chords.push_back(std::make_shared<MarkovState>(CountedMarkovFunctionCreator(M4,16)));

    chainPtr Final = std::make_shared<FourStateLoop>();
    Final->Initialize(Chords);

    while(true){

        Final->Advance();
        
    };
    

}