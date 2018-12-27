from picamera import PiCamera
from time import sleep
import os
import sys
import cv2

camera = PiCamera()

camera.start_preview()
sleep(5)
camera.capture('/home/pi/Desktop/image.jpg')
camera.stop_preview

#os.system('lp -o fit-to-page image.jpg')

