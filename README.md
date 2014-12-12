arduino-drumkit
===============

The code for my Arduino based Drumkit.

This works by having a piezo with a 1M resistor hooked up to the Arduino's analog input. I am using Hairless Serial to MIDI
conversion software to translate the signals from the Arduino, and route them to the Addictive Drums VST plugin, which runs
inside vstLord on my MacBook Pro.
