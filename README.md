# MarkovMidi
Sends Midi messages based on Markov Chain models

Uses RTmidi as the library for generating midi events and opening midi ports on various platforms. To compile this project, you may need to change the compile flag found in the CMakeLists.txt file and replace it, in accordance to this page: http://www.music.mcgill.ca/~gary/rtmidi/index.html#compiling

From an API perspective: 
- The Pitch Class represent a midi pitch (value from 0 to 127) but has some helper conversion functions to allow writing musical notes such as C#5
- The Note Class is an aggregate that represents a single midi note with Pitch, Velocity and Duration attributes
- The MidiPlayer class simply allows you to send simple "Note On/Off" midi messages.
- The MarkovState class represents a state in a Markov chain. It is agnostic with repect to any Midi-related classes, and uses a callback system to determine what will happen when that state gets navigated to.
- The MarkovChain class is a collection of States. It can be inherited from to ovverride the intialization method, which determines how the states get linked together and with what probabilities.
- The Percentage Probability struct is a simple representation of a fixed point percentage value. Ranges from 0 to 100 with integer values.
- Random.hpp contains a  global variable for generating randomness.
- MusicalFunctions is where you can find functions that generate the msuical callbacks for Markov States.

Main.cpp contains an example usage of these features. Uploaded below is a video of this exmaple used to create a four chord loop randomised arpeggiator with Vital.
