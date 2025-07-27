all : church_layout.ps

church_layout.ps : build/church_layout Makefile
	./build/church_layout > $@
	-killall ghostscript
	ghostscript church_layout.ps
