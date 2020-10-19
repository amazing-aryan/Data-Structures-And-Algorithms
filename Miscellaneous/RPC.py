---Implement RPC mechanism for a file transfer across a network
==>
SERVER SIDE:
from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import SimpleXMLRPCRequestHandler
import xmlrpc.client as cl

def get_file(fp):
  handel = open(fp, "rb")
  return cl.Binary(handel.read())
  handel.close()

# creating the server
server =  SimpleXMLRPCServer(('localhost', 9999))
print("Server Started (ctrl + c will close the server) !!")

server.register_function(get_file, "get_file")
server.serve_forever()

-----------------------------------------------------
CLIENT SIDE:
import xmlrpc.client

s = xmlrpc.client.ServerProxy('http://localhost:9999')
print("Connected To the Server")
fp = input("enter filepath : ")

try:
  print("Downloading ... ")
  handel = open("downloads/" + fp, "wb")
  sm = s.get_file(fp)
  handel.write(sm.data)
  handel.close()
  print("Downloaded ..")
except:
  print("Download Failed !!")
