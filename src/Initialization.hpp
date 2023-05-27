#include <memory>
#include "RtMidi.h"

#pragma once

std::unique_ptr<RtMidiOut> InitializeMidiOut();
std::unique_ptr<RtMidiIn> InitializeMidiIn();