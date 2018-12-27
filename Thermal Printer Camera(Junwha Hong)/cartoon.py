#!/usr/bin/env python

from picamera import PiCamera
import os
import sys
import cv2
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(21, GPIO.IN)

try:
		while True:
			if GPIO.input(21) == True:				
				camera = PiCamera()

				#camera.start_preview()
				#sleep(5)
				camera.capture('/home/pi/Desktop/image.jpg')
				#camera.stop_preview


				img = cv2.imread('image.jpg')

				gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
				gray = cv2.medianBlur(gray,5)
				edges = cv2.adaptiveThreshold(gray, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 13, 2)

				color = cv2.bilateralFilter(img, 9, 300, 300)

				cartoon =cv2.bitwise_and(color, color, mask=edges)



				cv2.imwrite('image1.png',cartoon)
				cv2.waitKey(0)
				cv2.destroyAllWindows()


				os.system('lp -o fit-to-page image1.png')

except KeyboardInterrupt:
	GPIO.cleanup()
