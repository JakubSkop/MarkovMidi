#include <iostream>
#include <memory>
#include "MidiPlayer.hpp"
#include "Note.hpp"
#include "Markov.hpp"
#include <memory>

int main()
{
    using namespace std::chrono_literals;
    using statePtr = std::shared_ptr<MarkovState>;
    using chainPtr = std::shared_ptr<MarkovChain>;

    std::shared_ptr<MidiPlayer> MyPlayer = std::make_shared<MidiPlayer>();

    std::vector<statePtr> Scale1{};
    Scale1.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"C4",100,200ms});}));
    Scale1.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"Eb4",100,200ms});}));
    Scale1.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"G4",100,200ms});}));
    Scale1.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"G4",100,200ms});}));
    Scale1.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"C5",100,200ms});}));

    std::vector<statePtr> Scale2{};
    Scale2.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"D4",100,200ms});}));
    Scale2.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"F4",100,200ms});}));
    Scale2.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"G4",100,200ms});}));
    Scale2.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"B4",100,200ms});}));
    Scale2.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"D5",100,200ms});}));

    std::vector<statePtr> Scale3{};
    Scale3.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"Eb4",100,200ms});}));
    Scale3.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"Eb4",100,200ms});}));
    Scale3.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"G4",100,200ms});}));
    Scale3.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"Bb4",100,200ms});}));
    Scale3.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"Eb5",100,200ms});}));

    std::vector<statePtr> Scale4{};
    Scale4.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"Ab3",100,200ms});}));
    Scale4.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"C4",100,200ms});}));
    Scale4.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"Eb4",100,200ms});}));
    Scale4.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"Ab4",100,200ms});}));
    Scale4.push_back(std::make_shared<MarkovState>([MyPlayer](){MyPlayer->PlayNote(Note{"Ab4",100,200ms});}));


    chainPtr M1 = std::make_shared<Markov1>();
    M1->Initialize(Scale1);
    
    chainPtr M2 = std::make_shared<Markov1>();
    M2->Initialize(Scale4);

    chainPtr M3 = std::make_shared<Markov1>();
    M3->Initialize(Scale3);
    
    chainPtr M4 = std::make_shared<Markov1>();
    M4->Initialize(Scale2);

    std::vector<statePtr> Chords{};
    Chords.push_back(std::make_shared<MarkovState>([M1](){for(size_t i=0; i<16; i++){M1->Advance();};}));
    Chords.push_back(std::make_shared<MarkovState>([M2](){for(size_t i=0; i<16; i++){M2->Advance();};}));
    Chords.push_back(std::make_shared<MarkovState>([M3](){for(size_t i=0; i<16; i++){M3->Advance();};}));
    Chords.push_back(std::make_shared<MarkovState>([M4](){for(size_t i=0; i<16; i++){M4->Advance();};}));

    chainPtr Final = std::make_shared<FourStateLoop>();
    Final->Initialize(Chords);

    while(true){

        Final->Advance();
        
    };
    

}