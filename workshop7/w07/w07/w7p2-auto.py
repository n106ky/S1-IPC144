import pyautogui as gui
import time

# pause 3 seconds while you set focus to the terminal/console window:
print('Click on the terminal/console window where the automated keyboard data needs to be entered...')
print('NOTE: You have 3 seconds to do this!')
time.sleep(3)

# auto type test data from text file:
with open('w7p2-inputs.txt', 'r') as tst:
	time.sleep(1)
	tst = tst.readlines()
	for i in range(0, len(tst), 1):
		print(tst[i])
		gui.typewrite(tst[i])

print('Auto data input completed.')