@echo off

echo copying res...

echo %1 SolutionDir
echo %2 OutDir

del "%~2CrazyMemotest.pdb"

xcopy "%~1res" "%~2res" /i/y/s

echo succesfully copied res