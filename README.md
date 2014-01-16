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

## TODO ##

"Det tenkende mennesket"
"Ethics and Science"

Parse statement:

m_content = file.content();

#cxy start
#cxy <eq>

#cxy stop

Maybe the header file needs to take note of the stop statement...
It can not; due to the fact that the parser erases all #cxy statements...

Need to insert statement:


#cxy start // Found first
	#cxy start
		#cxy start
			push ax
			cpy ax "=="
			find ax
			eq ptr mrk
			if eq
				cpy ax " "
				ins ax
			stop
		#cxy stop // find #cxy stop from 0, then find the last start...
 		// Scope 1
		push ax
		push bx
		cpy ax "32"
		mov bx ax
		ax == bx
	#cxy stop
	// Scope 2
#cxy stop

// Scope 3

m_statements:

nest3, 
	nest2,
		outer

m_content->
pop->nest2
	pop->outer
		pop->raw


I can, at every #cxy start increment the "nest counter"






(- (-5*sqrt(3) / 2 - 7 * cos(atan(3/4)))  + (5 / 2 - 7 * sin(atan(3 / 4))) * cos(pi/4)) / (cos(pi/6) * sin(pi/4) - sin(pi/6) * cos(pi/4))


