:: %%d is a variable - why isn't %%dir valid?
for /D %%d in (*) do (
	echo Compiling %%~nd
	
	..\utils\makels\Release\makels.exe %%~nd %%~nd %%~nd.ls
	..\utils\qlumpy\Release\qlumpy %%~nd.ls

	copy %%~nd.wad ..\basis
)