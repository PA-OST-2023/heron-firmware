import pyaudio
import numpy as np

# Parameters
samplerate = 44100
frequency = 440
duration = 1  # seconds

# Generate a square wave
t = np.linspace(0, duration, int(samplerate * duration), endpoint=False)
wave = 0.5 * np.sign(np.sin(2 * np.pi * frequency * t)) * 32767
wave = wave.astype(np.int16)

# Initialize PyAudio
p = pyaudio.PyAudio()

# Open Stream
stream = p.open(format=pyaudio.paInt16,
                channels=1,
                rate=samplerate,
                output=True)

# Play the square wave
stream.write(wave.tostring())

# Close the stream
stream.stop_stream()
stream.close()
p.terminate()
