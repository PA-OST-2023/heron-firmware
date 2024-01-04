import numpy as np
import time
from threading import Thread


UPDATE_RATE = 5.0 # Hz


startTime = time.time() * 1000000

# create a thread to simulate the RTC
class RTC(Thread):
    def __init__(self):
        Thread.__init__(self)
        self.running = True
        self.rtcTime = 0
        self.rtcOffset = 3 * 1000000
        self.initialTime = int(time.time()) * 1000000 + self.rtcOffset

    def run(self):
        while self.running:
            self.rtcTime = int(time.time()) * 1000000
            time.sleep(1.0/UPDATE_RATE)

    def get_time(self):
        return self.rtcTime

    def stop(self):
        self.running = False

    
# create thread to simulate inaccurate program execution time in microseconds
class ProgramTime(Thread):
    def __init__(self):
        Thread.__init__(self)
        self.running = True
        self.programTime = 0
        self.startTime = time.time() * 1000000 + np.random.randint(-10000, 10000)

    def run(self):
        while self.running:
            self.programTime = int(time.time() * 1000000) + np.random.randint(-1000, 1000)
            time.sleep(0.01)

    def get_time(self):
        return self.programTime - self.startTime

    def stop(self):
        self.running = False


class PLL():
    def __init__(self, rtc, programTime, kp=0.1, ki=0.01):
        self.rtc = rtc
        self.programTime = programTime
        self.kp = kp
        self.ki = ki
        self.timeOffset = 0
        self.error = 0
        self.errorSum = 0

    def run(self):
            rtcRead = self.rtc.get_time() - rtc.initialTime
            self.error = self.programTime.get_time() - (rtcRead + self.timeOffset)
            self.errorSum += self.error
            self.timeOffset = self.kp * self.error + self.ki * self.errorSum

    def get_time(self):
        return self.programTime.get_time() + rtc.initialTime - self.timeOffset + 0.5 * 1000000
     

rtc = RTC()
programTime = ProgramTime()

rtc.start()
programTime.start()

pll = PLL(rtc, programTime, kp=0.0, ki=0.005)


rtcList = []
sysList = []
pllList = []
effectList = []

diffList = []

try:
    while True:
        pll.run()
        rtcList.append(rtc.get_time() - startTime)
        sysList.append(programTime.get_time())
        pllList.append(pll.get_time() - startTime)
        referenceTime = time.time() * 1000000
        effectList.append(referenceTime - startTime)
        diffList.append((referenceTime - pll.get_time()) / 1000000)
        print(pll.error / 1000000, pll.timeOffset / 1000000)
        
        time.sleep(0.1)
except KeyboardInterrupt:
    print("Keyboard Interrupt")
finally:
    rtc.stop()
    programTime.stop()
    rtc.join()
    programTime.join()
    print("Threads stopped")


import matplotlib.pyplot as plt
plt.plot(rtcList, label="RTC", marker="o")
plt.plot(sysList, label="System", marker="o")
plt.plot(effectList, label="Effect", marker="o")
plt.plot(pllList, label="PLL", marker="o")
plt.legend()
plt.grid()

# new figure
plt.figure()
plt.plot(diffList, label="Difference", marker="o")
plt.legend()
plt.grid()
plt.show()
