IF "%1" == "" (
  SET CONFIG=Release
) ELSE (
  SET CONFIG=%1
)
FOR /f "delims=" %%i IN ('python -m site --user-site') DO SET PYTHON_PATH="%%i"
COPY "Libraries\%CONFIG%\rover.pyd" "%PYTHON_PATH%"
