@@ Basic Startup Code
.global reset
reset:
	ldr sp, =Stack_Top @@Load Stack Pointer
	bl Intery_Function @@Branch Main
stop:
	b stop
