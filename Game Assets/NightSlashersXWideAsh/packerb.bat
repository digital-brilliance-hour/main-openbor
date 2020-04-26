:: Name: packer
:: Author: Plombo
:: Frontend for borpak that emulates Senile Team's "packer" utility.
:: Put this file in the same directory as the borpak executable.
@echo off

if (%1) == () goto USAGE
if (%2) == () goto USAGE
if not (%3) == () goto USAGE

%0\..\borpak -b -d %2 %1
goto END

:USAGE
echo Usage: %0 ^<ngh^> ^<Z:\00 Games\Night Slashers x\night-slashers-x-en-win\NIGHT SLASHERS - WidescreenASH\data^>
goto END

:END
