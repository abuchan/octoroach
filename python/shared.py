<<<<<<< HEAD
DEST_ADDR = '\x20\x72'
xb = []
ser = []

#Base station
BS_COMPORT = 'COM1'
BS_BAUDRATE = 230400
#XBee
#BS_COMPORT = 'COM4'
#BS_BAUDRATE = 57600

motor_gains_set = False
steering_gains_set = False
steering_rate_set = False
flash_erased = 0
pkts = 0
deg2count = 14.375
count2deg = 1/deg2count
bytesIn = 0

last_packet_time = 0
readback_timeout = 2 #seconds

awake = True;

# Cross-module variable sharing; these need default values
imudata = []
dataFileName = ''
leadinTime = 0
leadoutTime = 0
angRateDeg = "NOT SET"  #This is only for writing the file header
angRate = "NOT SET"
motorGains = "NOT SET"
steeringGains = "NOT SET"
runtime = 0
numSamples = 0
moveq = "NOT SET"

robotQueried = False
maxQueries = 8
=======
#Base station
#BS_COMPORT = 'COM3'
#BS_BAUDRATE = 230400
#XBee
BS_COMPORT = 'COM4'
BS_BAUDRATE = 57600

deg2count = 14.375
count2deg = 1/deg2count

#For download timeout
last_packet_time = 0
pkts = 0

ROBOTS = []
>>>>>>> 59b60439f05fcbe8104c44109cf3f13111cd2be7
