# Cxy #

Official Cxy interpreter and compiler.

Version numbering not applied.

## About ##

Cxy is an interpreted; as well as compiled, imperative-declarative, non-functional procedural recursive programming language.  
The language is a translator of a piece of text. This text could also be itself. Thereby, Cxy can define a higher level of itself. Cxy can also define a new language by translating small units of change in another language into that language.  

Not implemented:
What if we wanted to have a folder with tonnes of small statements. Instead of having to manually add each statement to a switch and .hpp file, we could put all these little files into a single folder which is read by cxy. For each file, cxy can copy the necessary information into header files and makefiles.
The best example of this is the compiler/interpreter itself. There are quite a few small assembly-like mnemonic statements all in the src/File folder. 

Implemented:
An example of changing some language-related parameters:

	std::function<void(std::shared_ptr<Base>)> func([](std::shared_ptr<Base> x){/*statements*/});
	add_object(std::make_shared<Derived>()); // uses func on each object

In some cases, it may be hard or impossible to make the compiler deduce how to case the Derived class into the Base class.  
One could therefore let add_object be a template function. By reading what type we put in, we can add the string "<Derived>" 
right after the "add_object" string. Thus, we have solved a problem. 




# Quick Overview #

## Language ##

### Hello World ###

Tier 0 Cxy is an assembly-like language.
Data in Tier 0 is put into a tree of stacks.
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

### Reference ###

In this reference, I will briefly discuss the language syntax, then explain what a register is, as well as the standard registers. After that, instructions will be explained.  

#### Language Syntax ####

The syntax of cxy is defined by space-separated tokens. A single token can contain spaces if it is enclosed by quotation marks "".  

#### Registers ####

A register is simply a stack with a name. We always work on the top of the register.
We can put numeric or string data in a register. A register is operated upon by instructions.

The standard registers:
"register_name" : <explanation>

"cnt" : Register containing the result of the cnt instruction.
"eq" : Register containing the result of the eq instruction.
"neq" : Register containing the result of the neq instruction.



#### Instructions ####

##### ins #####

Argument: 1 register
Output: into register "cntnt"
Uses: ptr, mrk

## TODO ##

~~ Implement recursivity ~~  
Escape sequences  

Tier 1 functionality:  
Functions  
if  
while  
operators  
do-while  
scope  

Tier 2 functionality:
structs  
classes  
lambdas  