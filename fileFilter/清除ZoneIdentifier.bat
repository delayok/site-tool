@echo off
chcp 65001 >nul
echo ================================================
echo 清除Zone.Identifier (解除安全警告)
echo ================================================
echo.

if "%~1"=="" (
    echo 用法: 拖拽文件夹到本脚本上，或指定路径
    echo 例如: 清除ZoneIdentifier.bat "C:\TestFiles"
    echo.
    set /p "TARGET=请输入要处理的文件夹路径: "
) else (
    set "TARGET=%~1"
)

if not exist "%TARGET%" (
    echo 错误: 路径不存在: %TARGET%
    pause
    exit /b 1
)

echo 正在处理: %TARGET%
echo.

set "COUNT=0"
set "DELETED=0"

for /r "%TARGET%" %%F in (*) do (
    set "FILE=%%F"
    set /a COUNT+=1
    
    :: 检查并删除Zone.Identifier流
    >nul 2>&1 (
        echo. > "%%F:Zone.Identifier"
    )
    
    :: 方法2: 使用fsutil
    >nul 2>&1 fsutil sparse setflag "%%F" 0
    
    set /a DELETED+=1
    if !DELETED! %% 10 == 0 (
        echo 已处理 !DELETED! 个文件...
    )
)

echo.
echo 完成!
echo 总文件数: %COUNT%
echo 已处理: %DELETED%
echo.
echo 现在可以安全使用这些文件了
pause
