A very basic TaskManager-esque program made as a proof of concept. 

Run with the command: $ TaskManager 

The program prints a list of currently running processes on the user's system, then brings up a command prompt. 
Options then include: 
    - help (list commands) 
    - kill (kill a process) 
    - info (list further information about a process) 
    - refresh (reprint the list of processes) 
    - quit 

The program requires the user to know the Process ID of the process they wish to affect. With more time, I would've liked to also 
take the file location, name, or another identifer that is more easily accessable. There is also very little room for user error, 
so I would add more error cases. 

I tested everything with a simple zombie program on a class server, which made things a bit difficult, but it should work on a 
standard system so long as the user has permissions.
