@echo off
setlocal

:: 文件路径
set "filePath=C:\Program Files\JetBrains\IntelliJ IDEA 2021.1.3\plugins\maven\lib\maven3\conf\settings.xml"

:: 清空文件
echo. > "%filePath%"

:: 写入新的内容
echo ^<?xml version="1.0" encoding="UTF-8"?^> >> "%filePath%"
echo.
echo ^<settings xmlns="http://maven.apache.org/SETTINGS/1.0.0" >> "%filePath%"
echo          xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" >> "%filePath%"
echo          xsi:schemaLocation="http://maven.apache.org/SETTINGS/1.0.0 http://maven.apache.org/xsd/settings-1.0.0.xsd"^> >> "%filePath%"
echo.  
echo  ^<pluginGroups^> >> "%filePath%"
echo.    
echo  ^</pluginGroups^> >> "%filePath%"
echo.
echo  ^<proxies^> >> "%filePath%"
echo.    
echo  ^</proxies^> >> "%filePath%"
echo.
echo  ^<servers^> >> "%filePath%"
echo.    
echo  ^</servers^> >> "%filePath%"
echo.
echo  ^<mirrors^> >> "%filePath%"
echo        ^<mirror^> >> "%filePath%"
echo            ^<id^>huaweicloud^</id^> >> "%filePath%"
echo            ^<mirrorOf^>*^</mirrorOf^> >> "%filePath%"
echo            ^<url^>https://repo.huaweicloud.com/repository/maven/^</url^> >> "%filePath%"
echo        ^</mirror^> >> "%filePath%"
echo  ^</mirrors^> >> "%filePath%"
echo.
echo  ^<profiles^> >> "%filePath%"
echo. 
echo  ^</profiles^> >> "%filePath%"
echo.
echo ^</settings^> >> "%filePath%"

endlocal
:: 复制设置文件到指定目录，并替换（如果存在）
copy /Y "%filePath%" "C:\Users\Administrator\.m2\settings.xml"