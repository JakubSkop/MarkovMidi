#include "MusicalFunctions.hpp"

std::function<void()> NotePlayFunctionCreator(midiPlayerPtr player, Note note){
    return [player, note](){player->PlayNote(note);};
};

std::function<void()> CountedMarkovFunctionCreator(chainPtr markovChain, size_t length){
    return [markovChain,length](){for(size_t i=0; i<length; i++){markovChain->Advance();};};
};




std::vector<Pitch> CreateMajorScale(Pitch Base){
    return std::vector<Pitch>{Base, Base+2, Base+4, Base+5, Base+7, Base+9, Base+11};
};

std::vector<Pitch> CreateMinorScale(Pitch Base){
    return std::vector<Pitch>{Base, Base+2, Base+3, Base+5, Base+7, Base+8, Base+10};
};