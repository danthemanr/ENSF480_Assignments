FOR /D %%G IN ("%1\*") DO (
  echo Processing subfolder: %%G
  if exist "%%G.zip" (del "%%G.zip")
  if exist "%%G\%%~nG.txt" (del "%%G\%%~nG.txt")
  type %%G\*.h %%G\*.cpp %%G\*.java > %%G\%%~nG.txt
  verticalize %%G\%%~nG.txt ::a python program that I wrote to replace some newlines with vertical tabs
  powershell -command "Compress-Archive '%%G\*.cpp', '%%G\*.h', '%%G\*.java' '%%G.zip'"
)