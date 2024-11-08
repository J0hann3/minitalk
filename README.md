# minitalk

>The purpose of this project is to code a small data exchange program
>using UNIX signals.

[Subject Minitalk Project 42](Minitalk.pdf)

## Compilation

```
git clone https://github.com/J0hann3/minitalk.git
cd minitalk
make
```

Then you run th program `./client`, he will print a PID.  
New you need to run `./server <PID client>`.

You can type anything and it will be send to the client using the **Unix Signals** `SIGUSR1` and `SIGUSR2`.
The message it send using binairy signals.
