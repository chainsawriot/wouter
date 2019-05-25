# Wouter

A very simple R script to replace the session chair. After the countdown (official presentation time + grace period), this program will encourage the audience to clap (in order to stop the presentation.)

Currently it only works on a Mac.

## Usage
wouter [presentation time] [grace period] [countdown] [title]

* presentation time - in s
* grace period - in s
* countdown - in s
* title - announcement before the count down.

e.g.

8 minutes presentation time, 1 minute grace period, 10 second final count down and announcing "I am not Wouter" at the beginning.

```bash
wouter 480 60 10 I  am not Wouter
```
