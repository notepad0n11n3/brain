
require 'digest'
wowowo = 'Hello'

cifrado_MD5 = Digest::MD5.hexdigest wowowo      # 32    
cifrado_SHA1 = Digest::SHA1.hexdigest wowowo    # 40
cifrado_SHA256 = Digest::SHA256.hexdigest wowowo # 64
cifrado_SHA512 = Digest::SHA512.hexdigest wowowo # 128

print cifrado_MD5 , "  <<==" , cifrado_MD5.length, "\n"
print cifrado_SHA1, "  <<==" , cifrado_SHA1.length, "\n"
print cifrado_SHA256, "  <<==" , cifrado_SHA256.length, "\n" 
print cifrado_SHA512, "  <<==" , cifrado_SHA512.length, "\n"

puts "\n ---------------------- \n"

# NTLMv1
require 'openssl'
ntlmDes = OpenSSL::Digest::MD4.hexdigest "passwordHere".encode('UTF-16LE')

print ntlmDes, "  <<==" , ntlmDes.length, "\n"


# NTLMv2
ntlmWo = OpenSSL::Digest::MD4.hexdigest "passwordHere".encode('UTF-16LE')

userdomain = "administrator".encode('UTF-16LE')

ntlmV2 = OpenSSL::HMAC.digest(OpenSSL::Digest::MD5.new, ntlmWo, userdomain)

print ntlmV2, "  <<==" , ntlmV2.length, " \n"


# MYSQL
puts "*" + Digest::SHA1.hexdigest(Digest::SHA1.hexdigest('password'))

