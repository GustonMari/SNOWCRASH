go to root and chmod -R 777 * to get access to all 

find / -user flag00 2>/dev/null permit to find this:
/usr/sbin/john
/rofs/usr/sbin/john

-user flag00 ---> search for files owned by a user named flag00.

cat the file: /usr/sbin/john and /rofs/usr/sbin/john
you will find cdiiddwpgswtgt

We calculate the Index of coincidence.
https://www.dcode.fr/indice-coincidence
here we have the index = 0.07692 --> If the index of coincidence is large (close to 0.070),
which is similar to that of an unencrypted message,
then the message has likely undergone a transposition (letter rearrangement) or monoalphabetic substitution
(where a single letter can only be replaced by one other)."
So we searched a simple encryption algorithm with transposition or monoalphabetic substitution, and we found the "code cesar"
https://www.irif.fr/_media/users/ylg/crypto.pdf
https://www.dcode.fr/chiffre-cesar
Know we can decrypt our text using the "code cesar" --> nottoohardhere

We can get our flag : x24ti5gi3x0ol2eh4esiuxias