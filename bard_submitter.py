import sys

import requests
from bs4 import BeautifulSoup

import numpy as np
import pandas as pd
import datetime
import openai
import time
import pyautogui as pag
import re


bard_tab=(749,20)
text_area=(608,919)
submit=(1727,911)

the_length=4657

lang=['c++','java','python']
extensions=['cpp','java','py']
chrome=(1156,1053)
pycharm=(642,1059)

df=pd.read_csv('filtered_df.csv')

def remove_new_lines(code):
    return re.sub('\n',' ',code)




limit=468

def send(code):

    # take text as ctrl+c
    pag.moveTo(chrome[0],chrome[1])
    pag.click(duration=1)
    new_code=remove_new_lines(code)
    message = f"solve the following problem in C++ : " +new_code+ \
                  ". And please  never explain anything before or after the code nor recommend any thing"
    pag.moveTo(text_area[0],text_area[1],duration=.2)
    pag.click()

    pag.typewrite(message)
    pag.sleep(30)
    pag.press('enter')
    time.sleep(30)
    pag.click(pycharm[0],pycharm[1])
    time.sleep(1)

def new_tab():
    pag.moveTo(chrome[0], chrome[1])
    pag.click(duration=1)
    pag.hotkey('ctrl','t')
    pag.typewrite("https://bard.google.com/")
    pag.press("enter")
    pag.click(pycharm[0], pycharm[1])
    time.sleep(1)



file=open('log.txt','w')
for i in range(967,1000):
    if i%20==0:
        new_tab()
    print(i+1,'/',limit)
    file.write(str(i+1)+'\n')
    code=df.problem_statement[i]
    send(code)
file.close()
print('done')
