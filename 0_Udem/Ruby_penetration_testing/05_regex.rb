
mac = "asdfasd fs:as  00:0c:29:63:67:06 asdflkjsadf hello"

mac_regularExpresion = /(?:[0-9A-F][0-9A-F][:\-]{5}[0-9A-F][0-9A-F])/i

mac = mac.scan mac_regularExpresion

puts mac
            ## ROOR RROR RROR RROR RROR
