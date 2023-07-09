import time
from selenium.webdriver.support.ui import Select
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
import os
from selenium.webdriver.common.by import By

driver = webdriver.Chrome()
def register(email='abdelrahim.abdelaal@student.guc.edu.eg',password='ilovecode303'):

	url = "https://codeforces.com/enter?back=%2F"
	driver.get(url)
	driver.find_element(By.ID,"handleOrEmail").send_keys(email)
	driver.find_element(By.ID,"password").send_keys(password)
	time.sleep(1)
	str="/html/body/div[7]/div[4]/div/div/div/form/table/tbody/tr[4]/td/input"
	str2=r'//*[@id="enterForm"]/table/tbody/tr[4]/td/div[1]/input'
	driver.find_element(By.XPATH,str2).click()
	time.sleep(5)
	print("done")

register()




def solve(id):
	languages = ["GNU G++17 7.3.0","Java 17 64bit","PyPy 3.6.9 (7.3.0)"]
	# extensions = ['cpp','java','py']
	part1=""
	part2=""
	l=len(id)
	for x in range(l):
		if id[x].isdigit():
			part1+=id[x]
		else :
			part2=id[x:]
			break


	driver.get('https://codeforces.com/problemset/submit' )

	path_of_the_problem=f"C:\\Users\DELL\\Desktop\solutions\\bard\\cpp\\{id}.cpp"


	#to submit file

	driver.find_element(By.XPATH,'//*[@id="pageContent"]/form/table/tbody/tr[1]/td[2]/input').send_keys(id)
	dropDown=Select(driver.find_element(By.XPATH,'//*[@id="pageContent"]/form/table/tbody/tr[3]/td[2]/select'))
	dropDown.select_by_visible_text(languages[0])
	file_input=driver.find_element(By.XPATH,'//*[@id="pageContent"]/form/table/tbody/tr[5]/td[2]/input')
	time.sleep(5)
	file_input.send_keys(path_of_the_problem)
	time.sleep(5)
	driver.find_element('xpath',"//input[@value='Submit']").click()
	time.sleep(6)
cnt=0
for root_dir, cur_dir, files in os.walk(f"C:\\Users\\DELL\\Desktop\\solutions\\bard\\cpp"):
	for i in range(len(files)):
		print(files[i].split(".")[0])
		solve(files[i].split('.')[0])
		cnt+=1
		print(cnt,'/',len(files))



