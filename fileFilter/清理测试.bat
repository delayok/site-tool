@echo off
chcp 65001 >nul
echo ================================================
echo 清理测试输出
echo ================================================
echo.

if exist "%~dp0output" (
    echo 正在删除 output 文件夹...
    rmdir /s /q "%~dp0output"
    echo 删除完成
) else (
    echo output 文件夹不存在，无需清理
)

echo.
if exist "%~dp0testFiles" (
    echo 正在删除 testFiles 文件夹...
    rmdir /s /q "%~dp0testFiles"
    echo 删除完成
) else (
    echo testFiles 文件夹不存在，无需清理
)

echo.
echo 清理完成
pause
