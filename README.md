# 42 - MINITALK PROJECT

## Mandatory Part
You must create a communication program in the form of a client and a server.
* The server must be launched first, and after being launched it must display its PID
* The client will take as parameters
  * The server PID
  * The string that should be sent
* The client must communicate the string passed as a parameter to the server. Once the string has been received, the server must display it
* Communication between your programs should ONLY be done using UNIX signals
* The server must be able to display the string pretty quickly. By quickly we mean that if you think it is too long, then it is probably too long (hint: 1 second for 100 characters is COLOSSAL)
* Your server should be able to receive strings from several clients in a row, without needing to be restarted
* You can only use the two signals SIGUSR1 and SIGUSR2

### Technical Considerations
* You have to handle errors sensitively. In no way can your program quit unexpectedly (segmentation fault, bus error, double free, etc.)
* Your program cannot have memory leaks
* You may use one global variable but it must be justified
* For the mandatory part, you are allowed to use the following functions:
  * write
  * ft_printf and any equivalent YOU coded
  * signal
  * sigemptyset
  * sigaddset
  * sigaction
  * kill
  * getpid
  * malloc
  * free
  * pause
  * sleep
  * usleep
  * exit 

## Bonus Part
* The server confirms every signal received by sending a signal to the client
* Support Unicode characters
