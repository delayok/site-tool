# 清除Zone.Identifier - 解除Windows安全警告
# 用法: 右键 -> 使用PowerShell运行, 或拖拽文件夹到本脚本

param(
    [string]$Path = $PWD.Path
)

Write-Host "=============================================="
Write-Host "清除Zone.Identifier (解除安全警告)"
Write-Host "=============================================="
Write-Host ""

if (-not (Test-Path $Path)) {
    Write-Host "错误: 路径不存在: $Path" -ForegroundColor Red
    exit 1
}

Write-Host "处理路径: $Path" -ForegroundColor Cyan
Write-Host ""

$files = Get-ChildItem -Path $Path -File -Recurse
$total = $files.Count
$processed = 0

foreach ($file in $files) {
    $processed++
    
    try {
        # 删除Zone.Identifier备用数据流
        $streams = Get-Item -Path $file.FullName -Stream * -ErrorAction SilentlyContinue
        foreach ($stream in $streams) {
            if ($stream.Stream -ne ':$DATA') {
                Remove-Item -Path "$($file.FullName):$($stream.Stream)" -ErrorAction SilentlyContinue
            }
        }
        
        # 解除文件锁定 (使用Unblock-File替代方案)
        $acl = Get-Acl -Path $file.FullName
        $acl.UnsetAccessRules()
        Set-Acl -Path $file.FullName -AclObject $acl
        
        if ($processed % 10 -eq 0) {
            Write-Host "进度: $processed / $total"
        }
    }
    catch {
        # 忽略无法处理的流
    }
}

Write-Host ""
Write-Host "完成! 已处理 $processed 个文件" -ForegroundColor Green
Write-Host ""
Write-Host "提示: 如果仍有警告,尝试:" -ForegroundColor Yellow
Write-Host "  1. 右键文件 -> 属性 -> 取消阻塞"
Write-Host "  2. 或使用: Get-ChildItem -Recurse | Unblock-File"
pause
