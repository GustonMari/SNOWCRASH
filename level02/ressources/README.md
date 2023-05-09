you can see we have a .pcap file. Files .pcap are files readen by WireShark.

use scp -P 4242 level02@192.168.56.101:/home/user/level02/level02.pcap .
to copy locally the file then use WireShark
Give the right to level02.pcap file with chmod 777

now install WireShark --> sudo apt install wireshark

We can Run WireShark with the file with the following command :
WireShark level02.pcap

Wireshark is a network protocol analyzer,
or an application that captures packets from a network connection.
We are going to use it to show all the TCP stream.
With this we are going to see what the user entered with his keyboard... Maybe his password ?

In WhireShark : Anyalse --> Follow --> TCP stream
https://www.wireshark.org/docs/wsug_html_chunked/ChAdvFollowStreamSection.html


We have this : Password: ft_wandr...NDRel.L0L
Non-printable characters are replaced by dots so we have to see what is the ... and the .

So Show HEX dump --> 7f
https://manpages.ubuntu.com/manpages/bionic/en/man7/ascii.7.html
It s the DEL key, so we have ft_wandr minus 3 letters plus NDRel.L0L and delete l
--> ft_waNDReL0L
