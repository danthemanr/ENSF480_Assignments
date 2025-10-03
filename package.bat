FOR /D %%G IN ("%1\*") DO (
  echo Processing subfolder: %%G
  if exist "%%G.zip" (del "%%G.zip")
  if exist "%%G\%%~nG.txt" (del "%%G\%%~nG.txt")
  type %%G\*.h %%G\*.cpp > %%G\%%~nG.txt
  powershell -command "Compress-Archive '%%G\*.cpp', '%%G\*.h' '%%G.zip'"
)