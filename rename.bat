@echo off
set a=00
setlocal EnableDelayedExpansion
for %%n in (*.out) do (
set /A a+=1
ren "%%n" "data!a!.out"
)