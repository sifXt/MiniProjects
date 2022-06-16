#https://aimtrainer.io/challenge



from turtle import width
from pyautogui import *
import pyautogui
import time
import keyboard
import random
import win32api, win32con

time.sleep(2)

def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0)


while keyboard.is_pressed('q') == False:
    pic = pyautogui.screenshot(region=(463,266,997,595))
    width, height = pic.size
    for x in range(0,width,5):
        for y in range(0,height,5):

            r,g,b = pic.getpixel((x,y))

            if(r == 255 and b == 34 and g == 87):
                click((x+463),(y+266))
                x = 463
                y = 266
                time.sleep(0.05)
                break
