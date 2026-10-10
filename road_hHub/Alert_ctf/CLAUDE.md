# Laboratorio controlado de practica para Pentesting en HackTheBox.com, flujo de trabajo IA + tmux + vim + kali linux
	- step by step y bitacora personal del ctf en el archivo ./00__MaP__00
	- Lenguajes favoritos ( C, bash, python ) para script propios, siempre ve paso a paso y explicando el codigo, este es un entorno controlado de aprendisaje y refuerzo de fundamentos a temas avanzados
	- El output de nmap esta en ./01__recon/* , archivos *_N tienen formato -oN de nmap , archivos *_G tienen formato -oG de nmap, con la info de ./recon/* Indica tecnologias sospechosas y posibles vulnerabilidades comunes
	- el archivo ./hosts es una copia del archivo /etc/hosts , aveces necesitamos agregar url a la ip del target para poder ver cosas extra
	- si falta algun programa pedir al operador la instalacion antes de continuar(sudo apt install), no instalar nada sin perdir confirmacion
	- el objetivo es el aprendisaje profundo, se muy tecnico y didactico al explicar vulnerabilidades y codigo, da ejemplos sencillos si es necesario para maximizar el aprendisaje
	- si no encuentras un dato dilo, no lo inventes.

	## ESTRUCTURA DEL REPO
	
	00__ReadmE__00				# Documentacion de tecnicas aprendidas y usadas, vulnerabilidades, fuente de repaso de conocimientos (vista rapida)
	00__MaP__00				# Bitacora personal y progreso del operador (no modificar, solo lectura)
	00___o___00				# Dashboard /Registry - Hallazgos
	00__UrL__00				# Urls/Ips Target, http/https, subdominios
	01__recon/				# Reconocimiento 
	 /01__recon/a01_smell_N				# Archivo de salida nmap con formato -oN
	 /01__recon/a01_smell_G				# Archivo de salida nmap con formato -oG
	 /01__recon/a02_bite_N				# Archivo de salida nmap profundo con formato -oN
	02__extra				# Contenido Externo, github, gitlab, etc...
	03__Autopwn				# Script propio, Autopwn
	session.md				# Contexto de sesion IA

	##	WORKFLOW
	* el recon inicia por parte del operador hasta tener los archivos necesarios en 01__recon/
	* Recomendar vertores de ataque con la informacion obtenida del recon
	* Testear la plataforma en busca de fallos comunes o fallos de configuracion
	* El primer objetivo es obtener rce y obtener acceso
	* Una vez dentro del sistema escalar privilegios y llegar a ser ROOT para poder leer la ctf_flag 

