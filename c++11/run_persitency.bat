@echo off
set "SECOND_CMD=rtipersistenceservice -cfgFile PersistenceServiceConfig.xml -cfgName defaultPersistent -verbosity 5"
cmd /k "%NDDSHOME%\resource\scripts\rtisetenv_x64Win64VS2017.bat && %SECOND_CMD%"