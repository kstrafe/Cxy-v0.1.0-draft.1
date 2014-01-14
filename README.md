# Cxy #

Official Cxy interpreter and compiler.

Version numbering not applied.

# Quick Overview #

## Language ##

### Hello World ###

Tier 0 Cxy is an assembly-like language.
There data in Tier 0 is put into a tree of stacks.
Data can be accessed by simply using the stack's name in an operation.
Here's Hello World:

	#cxy start

	push ax
	cpy ax "Hello World"
	show ax
	pop ax

	#cxy stop

push ax: creates a new element on the "ax" stack.  
cpy ax "Hello World": copies the string after ax into the ax register.  
show ax: prints the contents of ax to stdout.  
pop ax: removes the top of the stack of ax.  

