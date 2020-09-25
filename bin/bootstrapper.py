import subprocess
from os import getcwd
from time import sleep
import tkinter as tk

window = tk.Tk()
window.title('cRSA bootstrapper')

#labelm = tk.Label(window, text = "Enter mode [ed]")
#labelm.grid(row=0, column=0)
#entrym = tk.Entry(window)
#entrym.grid(row=0, column=1)
mode = ''

def eButton():
    global mode
    mode = 'e'
    ebutton = tk.Button(window, text="Encrpyt", bg='grey', command=eButton)
    ebutton.grid(row=0, column=0)
    dbutton = tk.Button(window, text="Decrpyt", bg='white', command=dButton)
    dbutton.grid(row=0, column=1)
def dButton():
    global mode
    mode = 'd'
    ebutton = tk.Button(window, text="Decrpyt", bg='grey', command=dButton)
    ebutton.grid(row=0, column=1)
    dbutton = tk.Button(window, text="Encrpyt", bg='white', command=eButton)
    dbutton.grid(row=0, column=0)

eButton()

label1 = tk.Label(window, text = "Enter text:")
label1.grid(row=1, column=0)
entry1 = tk.Entry(window)
entry1.grid(row=1, column=1)

label2 = tk.Label(window, text = "Enter key:")
label2.grid(row=2, column=0)
entry2 = tk.Entry(window)
entry2.grid(row=2, column=1)

label3 = tk.Label(window, text = "Enter modulo:")
label3.grid(row=3, column=0)
entry3 = tk.Entry(window)
entry3.grid(row=3, column=1)

def return_button():
    cmd = getcwd() + "\\rsa\\rsa.exe " + mode + " " + entry1.get() + " " + entry2.get() + " " + entry3.get()
    result = subprocess.check_output(cmd, shell=True)
    output = tk.Label(window, text=result)
    output.grid(row=4, column=1)

return_button = tk.Button(window, text='Return', command=return_button)
return_button.grid(row=4, column=0)

window.mainloop()