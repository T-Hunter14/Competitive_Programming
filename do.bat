#!/bin/bash

# تحديد المسار للمجلد المحلي
cd "C:\Users\T-Hunter\Desktop\CP"

# تهيئة Git للمشروع إذا لم يكن تم تهيئته بالفعل
git init

# إضافة المستودع البعيد
git remote remove origin
git remote add origin https://github.com/T-Hunter14/Competitive_Programming.git

# سحب التغييرات من المستودع البعيد باستخدام rebase لتجنب التعارضات
git pull --rebase origin main

# إضافة كل الملفات التي تم تعديلها أو إضافتها
git add .

# تنفيذ commit للتغييرات
git commit -m "Auto add CP solutions"

# دفع التغييرات إلى المستودع البعيد
git push -u origin main
