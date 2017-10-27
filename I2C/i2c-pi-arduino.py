#!/usr/bin/python
import RPI.GPIO as GPIO
import smbus
import time

bus = smbus.SMBus(1)
address = 0x04
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP)

def writeNumber(value):
	bus.write_byte(address, value)
	return -1

def readNumber(channel):
	number = bus.read_byte(address)
	print "Arduino: Hey RPI, I received a digit ", number
	print 

GPIO.add_event_detect(17, GPIO.RISING, callback=readNumber, bouncetime=300)

while True:
	var = input("Enter 1 - 255:")
	if not var:
		continue
	writeNumber(var)
	print "RPI: Hi Arduino, I sent you ", var
	time.sleep(1)

