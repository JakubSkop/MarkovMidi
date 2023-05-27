#pragma once

#include "MidiPlayer.hpp"
#include "Note.hpp"
#include "Markov.hpp"
#include <memory>
#include <functional>

using midiPlayerPtr = std::shared_ptr<MidiPlayer>;
using chainPtr = std::shared_ptr<MarkovChain>;

std::function<void()> NotePlayFunctionCreator(midiPlayerPtr player, Note note);

std::function<void()> CountedMarkovFunctionCreator(chainPtr markovChain, size_t length);