# 04-Setup-ConsoleUTF8.ps1 - Fix garbled Thai text / Unicode box-drawing characters in Console
# Description: Sets the default Code Page of Console (conhost) on this machine to UTF-8 (65001)
#              so that new Console windows correctly read UTF-8-encoded printf output.
#              (Does not modify any .c files - this is a machine-level setting for the
#               current Windows user only.)
#
# NOTE: This file is intentionally written using ASCII-only text (no Thai, no box-drawing
#       characters). Non-ASCII characters in a .ps1 file depend on the file being saved
#       with a UTF-8 BOM; if that BOM is lost (e.g. re-saved by an editor, downloaded via
#       a tool that strips it), Windows PowerShell 5.1 falls back to the system ANSI code
#       page and misreads the multi-byte characters - which can corrupt output and even
#       break script parsing ("Missing closing '}'", "The string is missing the terminator").
#       Keeping this script ASCII-only avoids that failure mode entirely.

param(
    [switch]$Revert
)

# --- Styling ---
$Esc = [char]27
$Style = @{
    Reset  = "$Esc[0m"
    Bold   = "$Esc[1m"
    Cyan   = "$Esc[36m"
    Green  = "$Esc[32m"
    Yellow = "$Esc[33m"
    Red    = "$Esc[31m"
}

function Write-Info    { param([string]$msg) Write-Host "$($Style.Cyan)[i] $msg$($Style.Reset)" }
function Write-Success { param([string]$msg) Write-Host "$($Style.Green)[OK] $msg$($Style.Reset)" }
function Write-Warn    { param([string]$msg) Write-Host "$($Style.Yellow)[!] $msg$($Style.Reset)" }
function Write-ErrorMsg { param([string]$msg) Write-Host "$($Style.Red)[X] $msg$($Style.Reset)" }

$consoleKey  = "HKCU:\Console"
$backupFile  = Join-Path $PSScriptRoot "console-utf8-backup.json"

Write-Host "$($Style.Bold)$($Style.Cyan)=== Setup Console UTF-8 (DG111) ===$($Style.Reset)"
Write-Host ""

# --- Revert mode: restore the previous value ---
if ($Revert) {
    if (-not (Test-Path $backupFile)) {
        Write-ErrorMsg "Backup file not found ($backupFile) - this script has never been run to set up UTF-8, or the backup was deleted."
        exit 1
    }
    $backup = Get-Content $backupFile -Raw | ConvertFrom-Json
    if ($backup.HadCodePage) {
        Set-ItemProperty -Path $consoleKey -Name "CodePage" -Value $backup.OldCodePage -Type DWord
        Write-Success "Restored the previous CodePage ($($backup.OldCodePage))."
    } else {
        Remove-ItemProperty -Path $consoleKey -Name "CodePage" -ErrorAction SilentlyContinue
        Write-Success "Removed the CodePage setting (restored to system default)."
    }
    Remove-Item $backupFile -Force
    Write-Info "Open a new Console/Terminal window for this to take effect."
    exit 0
}

Write-Info "Problem: Thai text and Unicode box/block characters in .c files are encoded as UTF-8,"
Write-Info "but the Windows Console (cmd.exe / PowerShell host) usually opens with an older code"
Write-Info "page (437/874), so printf output for these characters is garbled (mojibake)."
Write-Host ""
Write-Warn "This script will set HKCU:\Console\CodePage = 65001 (UTF-8)."
Write-Warn "Effect: every new Console window for this Windows user (cmd.exe, PowerShell, and the"
Write-Warn "VS Code Debug Console) will open with UTF-8 as the default - this does not affect any"
Write-Warn "project files, and can be undone with -Revert."
Write-Host ""

$confirm = Read-Host "$($Style.Bold)Set Console to UTF-8 now? (Y/N)$($Style.Reset)"
if ($confirm -notmatch '^(y|yes)$') {
    Write-Info "Cancelled - no changes made."
    exit 0
}

if (-not (Test-Path $consoleKey)) {
    New-Item -Path $consoleKey -Force | Out-Null
}

# --- Back up the current value before changing it (used by -Revert) ---
$existing = Get-ItemProperty -Path $consoleKey -Name "CodePage" -ErrorAction SilentlyContinue
$backup = @{
    HadCodePage = $null -ne $existing
    OldCodePage = if ($existing) { $existing.CodePage } else { $null }
}
$backup | ConvertTo-Json | Set-Content -Path $backupFile -Encoding UTF8
Write-Info "Previous value backed up to: $backupFile"

Set-ItemProperty -Path $consoleKey -Name "CodePage" -Value 65001 -Type DWord
Write-Success "Set HKCU:\Console\CodePage = 65001 successfully!"

Write-Host ""
Write-Info "Close every Console/Terminal window and reopen (or restart VS Code) for this to take effect."
Write-Warn "Note: if the Console font is an old Raster Font (e.g. 'Terminal'), Unicode box/block"
Write-Warn "characters may still not display correctly - change the Console font to Consolas or"
Write-Warn "Cascadia Mono (right-click the window title bar > Properties > Font)."
Write-Host ""
Write-Info "To revert this change later, run: .\04-Setup-ConsoleUTF8.ps1 -Revert"
