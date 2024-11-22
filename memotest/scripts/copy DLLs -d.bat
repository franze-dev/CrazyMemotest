@echo off

echo copying DLLs...

echo %1 SolutionDir
echo %2 OutDir

copy "%~1dlls\debug\*.dll" "%~2" /y
copy "%~1dlls\*.dll" "%~2" /y

echo succesfully copied DLLs