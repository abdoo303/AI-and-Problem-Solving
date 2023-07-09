import pandas as pd
import requests
from bs4 import BeautifulSoup
import numpy as np


def return_answer(cnt,handle):
    url = f"https://codeforces.com/submissions/{handle}/page/"
    'https://codeforces.com/submissions/bal.bla.bla/page/20'
    dictionary={}
    for i in range(1,cnt+1):
        text=BeautifulSoup(requests.get(url+str(i)).text,'html.parser')
        trs=text.find('div',class_="datatable")
        trs=trs.find_all('tr')
        trs=trs[1:]
        for tr in trs:
            tds=tr.find_all('td')
            ans=tds[5].find('span',class_="submissionVerdictWrapper").get_text().strip()
            sub=tds[3].find('a').get("href").split('/')
            ind=sub[-3]+sub[-1]
            ind=ind.strip()
            dictionary[ind]=ans
    return dictionary



handles=["codeudcker",'bal.bla.bla'] # two fake accounts to test the results
sites=['gpt','bard']
df=pd.read_csv('filtered_df.csv')
dict1=None
dict2=None
for i in range(2):
    dictionary=return_answer(20,handles[i])
    df[sites[i]+"_ans"]=df.serial.map(dictionary)
    print(i)



df.tags=df.tags.map(np.array)

df.to_csv("research_data.csv",index=False)






