import tkinter as tk
import os
from turtle import width
from pyautogui import *
from ppadb.client import Client as AdbClient
from tkinter import simpledialog

client = AdbClient(host="127.0.0.1", port=5037) # Default is "127.0.0.1" and 5037
devices = client.devices()

os.system('cmd /c "adb devices"')


def on():
    

    if len(devices) == 0:
        tk.messagebox.showerror("Error", "No Devices Connected!!")
    
    device = devices[0]
    print(f'Connected to {device}')

    #press power and swipe
    device.shell('input keyevent 26')
    sleep(0.5)
    device.shell('input touchscreen swipe 930 880 930 380')

    #input password
    device.shell('input tap 562 1055')
    sleep(0.2)
    device.shell('input tap 800 1030')
    sleep(0.2)
    device.shell('input tap 800 1215')
    sleep(0.2)
    device.shell('input tap 500 1215')
    sleep(1)


def off():

    if len(devices) == 0:
        tk.messagebox.showerror("Error", "No Devices Connected!!")
    
    device = devices[0]
    print(f'Connected to {device}')

    #press power and swipe
    device.shell('input keyevent 26')

def closeApp():

    if len(devices) == 0:
        tk.messagebox.showerror("Error", "No Devices Connected!!")
    
    device = devices[0]
    print(f'Connected to {device}')

    device.shell('input keyevent 3')
    device.shell('input keyevent KEYCODE_APP_SWITCH')
    device.shell('input tap 555 2153')



def wtsapp():

    if len(devices) == 0:
        tk.messagebox.showerror("Error", "No Devices Connected!!")

    device = devices[0]
    print(f'Connected to {device}')

    name = tk.simpledialog.askstring('Name Dialog', 'Enter Name', parent=canvas)

    message = tk.simpledialog.askstring('Message Dialog', 'Enter Message', parent=canvas)

    #open whatsapp
    device.shell('input tap 760 1730')
    sleep(1)
    device.shell('input tap 875 1310')
    sleep(1)

    # whatsapp password
    device.shell('input tap 552 1228')
    sleep(0.2)
    device.shell('input tap 855 1228')
    sleep(0.2)
    device.shell('input tap 840 1447')
    sleep(0.2)
    device.shell('input tap 558 1447')
    sleep(1)

    #search for name
    device.shell('input tap 890 202')
    sleep(0.5)
    device.shell('input text "{}"'.format(name))
    sleep(1)
    device.shell('input tap 400 370')
    sleep(0.5)

    #enter and send text
    device.shell('input tap 350 2300')
    sleep(0.5)
    device.shell('input text "{}"'.format(message))
    sleep(1)
    device.shell('input tap 1000 1400')
    sleep(1)


root = tk.Tk()

root.title('Phone Tasker')


canvas = tk.Canvas(root, height=600, width=800, bg="#FFE2E2")
canvas.create_text(700, 585, text="An app by Sifat Singh", fill="black", font=('Helvetica 10'))
canvas.pack()

frame = tk.Frame(root, bg="#F6F6F6")
frame.place(relheight=0.8, relwidth=0.8, relx=0.1, rely=0.1)


#button frames

frame1 = tk.Frame(frame, bg="#F6F6F6")
frame1.place(relheight=0.2, relwidth=0.2, relx=0.2, rely=0.2)

frame2 = tk.Frame(frame, bg="#F6F6F6")
frame2.place(relheight=0.2, relwidth=0.2, relx=0.6, rely=0.2)

frame3 = tk.Frame(frame, bg="#F6F6F6")
frame3.place(relheight=0.2, relwidth=0.2, relx=0.2, rely=0.6)

frame4 = tk.Frame(frame, bg="#F6F6F6")
frame4.place(relheight=0.2, relwidth=0.2, relx=0.6, rely=0.6)


#buttons

turnOn = tk.Button(frame1, command=on, text = "Turn On", height=15, width=10, padx = 10, pady = 10, fg="#8785A2", bg="#FFC7C7")
turnOn.pack()

turnOff = tk.Button(frame2, command=off, text = "Turn Off", height=15, width=10, padx = 10, pady = 10, fg="#8785A2", bg="#FFC7C7")
turnOff.pack()

close = tk.Button(frame3, command=closeApp, text = "Close App", height=15, width=10, padx = 10, pady = 10, fg="#8785A2", bg="#FFC7C7")
close.pack()

whatsapp = tk.Button(frame4, command=wtsapp, text = "Whatsapp", height=15, width=10, padx = 10, pady = 10, fg="#8785A2", bg="#FFC7C7")
whatsapp.pack()

root.mainloop()