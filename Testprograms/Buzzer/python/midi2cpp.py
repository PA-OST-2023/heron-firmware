from mido import MidiFile       # pip install mido

speedModifier = 2.1
pauseDuration = 35

# Complete MIDI note number to C++ tone mapping
note_mappings = {
    21: "NOTE_A0", 22: "NOTE_AS0", 23: "NOTE_B0",
    24: "NOTE_C1", 25: "NOTE_CS1", 26: "NOTE_D1",
    27: "NOTE_DS1", 28: "NOTE_E1", 29: "NOTE_F1",
    30: "NOTE_FS1", 31: "NOTE_G1", 32: "NOTE_GS1",
    33: "NOTE_A1", 34: "NOTE_AS1", 35: "NOTE_B1",
    36: "NOTE_C2", 37: "NOTE_CS2", 38: "NOTE_D2",
    39: "NOTE_DS2", 40: "NOTE_E2", 41: "NOTE_F2",
    42: "NOTE_FS2", 43: "NOTE_G2", 44: "NOTE_GS2",
    45: "NOTE_A2", 46: "NOTE_AS2", 47: "NOTE_B2",
    48: "NOTE_C3", 49: "NOTE_CS3", 50: "NOTE_D3",
    51: "NOTE_DS3", 52: "NOTE_E3", 53: "NOTE_F3",
    54: "NOTE_FS3", 55: "NOTE_G3", 56: "NOTE_GS3",
    57: "NOTE_A3", 58: "NOTE_AS3", 59: "NOTE_B3",
    60: "NOTE_C4", 61: "NOTE_CS4", 62: "NOTE_D4",
    63: "NOTE_DS4", 64: "NOTE_E4", 65: "NOTE_F4",
    66: "NOTE_FS4", 67: "NOTE_G4", 68: "NOTE_GS4",
    69: "NOTE_A4", 70: "NOTE_AS4", 71: "NOTE_B4",
    72: "NOTE_C5", 73: "NOTE_CS5", 74: "NOTE_D5",
    75: "NOTE_DS5", 76: "NOTE_E5", 77: "NOTE_F5",
    78: "NOTE_FS5", 79: "NOTE_G5", 80: "NOTE_GS5",
    81: "NOTE_A5", 82: "NOTE_AS5", 83: "NOTE_B5",
    84: "NOTE_C6", 85: "NOTE_CS6", 86: "NOTE_D6",
    87: "NOTE_DS6", 88: "NOTE_E6", 89: "NOTE_F6",
    90: "NOTE_FS6", 91: "NOTE_G6", 92: "NOTE_GS6",
    93: "NOTE_A6", 94: "NOTE_AS6", 95: "NOTE_B6",
    96: "NOTE_C7", 97: "NOTE_CS7", 98: "NOTE_D7",
    99: "NOTE_DS7", 100: "NOTE_E7", 101: "NOTE_F7",
    102: "NOTE_FS7", 103: "NOTE_G7", 104: "NOTE_GS7",
    105: "NOTE_A7", 106: "NOTE_AS7", 107: "NOTE_B7",
    108: "NOTE_C8", 109: "NOTE_CS8", 110: "NOTE_D8",
    111: "NOTE_DS8", 112: "NOTE_E8", 113: "NOTE_F8",
}

def midi_note_to_cpp(note):
    return note_mappings.get(note, "0")

def midi_to_cpp(midi_path, cpp_path):
    mid = MidiFile(midi_path)
    with open(cpp_path, "w") as cpp_file:
        cpp_file.write("#include <buzzer.h>\n\n")
        cpp_file.write("Tone jingleBells[] = {\n")
        note = 0
        for i, msg in enumerate(mid.tracks[1]):
            if msg.type == 'note_on' and msg.time > 0:
                duration = int((msg.time - pauseDuration) / mid.ticks_per_beat * 1000 / speedModifier)  # Convert duration to milliseconds
                cpp_file.write(f"  {{0, {duration}}},\n")
            if msg.type == 'note_off':
                note = midi_note_to_cpp(msg.note)
                duration = int((msg.time - pauseDuration) / mid.ticks_per_beat * 1000 / speedModifier)  # Convert duration to milliseconds
                cpp_file.write(f"  {{{note}, {duration}}},\n")
                cpp_file.write(f"  {{0, {pauseDuration}}},\n")
            if msg.type == 'control_change' and msg.time > 0:
                cpp_file.write(f"// Long,\n")

        cpp_file.write("  {0, 0}    // End of Melody\n};")

# Usage example
midi_to_cpp("jinglebells.mid", "output.h")
