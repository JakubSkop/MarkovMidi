#include "MusicalFunctions.hpp"

std::function<void()> NotePlayFunctionCreator(midiPlayerPtr player, Note note){
    return [player, note](){player->PlayNote(note);};
};

std::function<void()> CountedMarkovFunctionCreator(chainPtr markovChain, size_t length){
    return [markovChain,length](){for(size_t i=0; i<length; i++){markovChain->Advance();};};
};