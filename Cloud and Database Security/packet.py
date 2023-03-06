from scapy.all import *
import time

def icmp(address):
    packet = IP(dst=address)/ICMP()
    send(packet)

def tcpSYN(address):
    packet = IP(dst=address/TCP(dport=80, flags="S"))
    send(packet)

def HTTP(address):
    packet = IP(dst=address)/TCP(dport=80)/"GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n"
    send(packet)

def ARP(address):
    packet = Ether(dst="ff:ff:ff:ff:ff:ff")/ARP(pdst=address, hwsrc="7a:6c:00:af:eb:89")
    send(packet)


if __name__ == "__main__":
    address = "8.8.8.8"
    time.sleep(2)
    icmp(address)
    time.sleep(3)
    tcpSYN(address)
    time.sleep(5)
    HTTP(address)
    time.sleep(1)
    ARP(address)