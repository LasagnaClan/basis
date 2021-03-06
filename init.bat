
call settings.bat

mkdir %moddir%\cl_dlls\
mkdir %moddir%\dlls\
:: need to create these, otherwise the compile scripts don't copy correctly
mkdir %moddir%\maps\
mkdir %moddir%\models\
mkdir %moddir%\sprites\

:: compile the utilities - build as release as they shouldn't need to be debugged
%visualstudio%\Common7\IDE\devenv.exe  utils\qcsg\qcsg-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\qbsp2\qbsp2-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\qrad\qrad-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\vis2x\vis-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\makels\makels-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\qlumpy\qlumpy-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\sprgren\sprgen-2008.sln /Build Release
%visualstudio%\Common7\IDE\devenv.exe  utils\studiomdl\studiomdl-2008.sln /Build Release

:: make sure qrad has a lights file
mkdir utils\qrad\Release
copy mapsrc\lights.rad utils\qrad\Release

pause
