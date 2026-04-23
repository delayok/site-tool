@echo off
chcp 65001 >nul
echo ================================================
echo 文件过滤分类工具 - 测试运行脚本
echo ================================================
echo.

:: 设置路径
set "SOURCE_DIR=%~dp0testFiles"
set "TARGET_DIR=%~dp0output"

:: 创建输出目录
if not exist "%TARGET_DIR%" mkdir "%TARGET_DIR%"

echo 源文件夹: %SOURCE_DIR%
echo 目标文件夹: %TARGET_DIR%
echo.
echo 请在程序中选择:
echo 1. 源文件夹: %SOURCE_DIR%
echo 2. 目标文件夹: %TARGET_DIR%
echo 3. 勾选"按文件名分类"
echo 4. 点击"开始"
echo.
echo 按任意键打开程序...
pause >nul

:: 查找并运行程序
if exist "%~dp0release\fileFilter.exe" (
    start "" "%~dp0release\fileFilter.exe"
) else if exist "%~dp0debug\fileFilter.exe" (
    start "" "%~dp0debug\fileFilter.exe"
) else if exist "%~dp0fileFilter.exe" (
    start "" "%~dp0fileFilter.exe"
) else (
    echo 错误: 未找到 fileFilter.exe
    echo 请先编译项目
    pause
)
