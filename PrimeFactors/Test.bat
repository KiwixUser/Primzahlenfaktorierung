@echo off
set F=..\Test\Test_

start ..\x64\Release\PrimeFactors %F%1e00                                                   1 1000
start ..\x64\Release\PrimeFactors %F%1e03                                               1.000 1000
start ..\x64\Release\PrimeFactors %F%3e04                                              30.000 1000
start ..\x64\Release\PrimeFactors %F%1e06                                           1.000.000 1000
start ..\x64\Release\PrimeFactors %F%1e09                                       1.000.000.000 1000
start ..\x64\Release\PrimeFactors %F%1e12                                   1.000.000.000.000 1000
start ..\x64\Release\PrimeFactors %F%1e15                               1.000.000.000.000.000 1000
start ..\x64\Release\PrimeFactors %F%1e18                           1.000.000.000.000.000.000 1000
start ..\x64\Release\PrimeFactors %F%1e21                       1.000.000.000.000.000.000.000  200
start ..\x64\Release\PrimeFactors %F%1e24                   1.000.000.000.000.000.000.000.000   40

set p=1.000.000.000.000.000.000.000.000.0
start ..\x64\Release\PrimeFactors %F%1e27 %p%00 %p%01 %p%03 %p%04 %p%05 %p%06 %p%07 %p%08 %p%09 %p%10 %p%11 %p%12 %p%13 %p%14 %p%16 %p%17 %p%20 %p%21 %p%22 %p%23 %p%24 %p%25 %p%27 %p%28 %p%29 %p%30 %p%34 %p%35 %p%36 %p%37 %p%38 %p%39 %p%40 %p%41 %p%42 %p%43 %p%44 %p%45 %p%46 %p%47 %p%48 %p%49

set p=1.000.000.000.000.000.000.000.000.000.0
start ..\x64\Release\PrimeFactors %F%1e30 %p%00 %p%01 %p%02 %p%04 %p%05 %p%07 %p%08 %p%12 %p%13 %p%19 %p%20 %p%22 %p%24 %p%26 %p%27 %p%29 %p%30 %p%31 %p%32 %p%33 %p%38 %p%40 %p%41 %p%42 %p%43 %p%44 %p%45 %p%46 %p%48

set p=1.000.000.000.000.000.000.000.000.000.000.0
start ..\x64\Release\PrimeFactors %F%1e33 %p%00 %p%01 %p%03 %p%04 %p%05 %p%07 %p%08 %p%10 %p%11 %p%13 %p%15 %p%17 %p%19 %p%20 %p%24 %p%25 %p%27 %p%29 %p%31 %p%35 %p%36 %p%37 %p%40 %p%41 %p%45 %p%47 %p%52 %p%54 %p%55 %p%58 %p%64 %p%65 %p%66 %p%68

set p=1.000.000.000.000.000.000.000.000.000.000.000.0
start ..\x64\Release\PrimeFactors %F%1e36 %p%00 %p%01 %p%04 %p%05 %p%10 %p%11 %p%12 %p%14 %p%16 %p%17 %p%23 %p%26 %p%27 %p%29 %p%34 %p%36 %p%38 %p%40 %p%45 %p%46 %p%53 %p%58 %p%61 %p%63 %p%64 %p%60

set p=340.282.366.920.938.463.463.374.607.431.768.211.4
start ..\x64\Release\PrimeFactors %F%3e38 %p%00 %p%03 %p%05 %p%07 %p%08 %p%13 %p%14 %p%16 %p%17 %p%18 %p%19 %p%20 %p%24 %p%27 %p%31 %p%33 %p%36 %p%38 %p%40 %p%41 %p%45 %p%47 %p%48 %p%52 %p%55
