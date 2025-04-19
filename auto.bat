@echo off
setlocal enabledelayedexpansion

:: تعيين المجلد الذي يحتوي على الملفات
set "SOURCE_FOLDER=C:\Users\T-Hunter\Desktop\CP"

:: التبديل إلى المجلد المصدر
cd /d "%SOURCE_FOLDER%"

:: التحقق من وجود ملفات .txt في المجلدات الفرعية
echo البحث عن ملفات .txt في المجلدات الفرعية لـ: %SOURCE_FOLDER%
for /r %%F in (*.txt) do (
    :: تعيين اسم الملف بدون الامتداد
    set "FILENAME=%%~nF"
    :: إعادة تسمية الملف إلى .cpp
    ren "%%F" "!FILENAME!.cpp"
    echo تم إعادة تسمية %%F إلى !FILENAME!.cpp
)

echo تم التحويل بنجاح!
pause
