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

"cnt" : Integer register containing the result of the cnt instruction.  
"eq" : Boolean register containing the result of the eq instruction.  
"neq" : Boolean register containing the result of the neq instruction.  
"lt" : Boolean register containing the result of the lt instruction.  
"st" : Boolean register containing the result of the st instruction.  


"ptr" : Integer register containing the position of the text pointer.  
"mrk" : Integer register containing the position of the text marker.

"size" : Integer register containing the size returned by the size instruction.  
"next" : Character returned by the "next" instruction.  
"prev" : Character returned by the "prev" instruction.

"and" : Boolean result of the AND operator instruction.  
"or" : Boolean result of the OR operator instruction.  
"xor" : Boolean result of the XOR operator instruction.  
"not" : Boolean result of the NOT operator instruction.  

"capt" : String of the captured data between ptr and mrk.  
"drf" : Character of a dereferenced integer.  

"cntnt" : The content that is being operated upon.  
"rdf" : The content read by rdf.  


#### Instructions ####

 - note: delta means change.  
 - Examples will contain frames of each instruction.  
 - "||" denotes ptr and mrk position respectively. (mrk > ptr).  
 - ">" denotes a sequence of statements, 1 or more.  
 - "register : "x"" denotes the contents of a register.  

##### ins #####

Argument: 1 register.  
Output: delta in "cntnt".  
Uses: ptr, mrk.  

Description:
Inserts text at the position of ptr-mrk. Behaviour is easier to explain by an example, so here is one:  
	
We see that ptr and mrk = 0.  

	cntnt: "||this is data"
	> push x
	> cpy x "Hello"
	> ins x
	cntnt: "Hello||this is data"
	> cpy x 5
	> add mrk x
	cntnt: "Hello|this |is data"
	> ins ptr
	cntnt: "Hello5||is data"

We observe that it works exactly like a standard text editor. If you press a character when we have nothing selected, it is inserted. If we have selected text, that text is deleted, and your new character inserted.  

##### del #####

Argument: void.  
Output: void.  
Uses: ptr, mrk.  

Description:
Implements the "delete" button behaviour.  

	cntnt: "||this is data"
	> cpy x 5
	> add mrk x
	cntnt: "|this |is data"
	> del
	cntnt: "||is data"
	> del
	cntnt: "||s data"


##### bck ##### 

Argument: void.  
Output: void.  
Uses: ptr, mrk.  

Description:
Implements the "backspace" button behaviour.  

	cntnt: "||this is data"
	> push x
	> cpy x 5
	> add mrk x
	> cpy x 3
	> add ptr x
	cntnt: "thi|s |is data"
	> bck
	cntnt: "thi||is data"
	> bck
	cntnt: "th||is data"


##### cnt #####

Argument: 1 register.  
Output: cnt register.  
Uses: ptr, mrk, cntnt.  

Description:  
Counts the elements matching the argument within ptr and mrk. If ptr = mrk, then the text is scouted from ptr until the end.  

##### find #####

Argument: 1 register.  
Output: ptr, mrk.  
Uses: ptr, mrk, cntnt.  

Description:  
Finds the nearest instance of the string that matches the register. Searches between ptr and mrk. If ptr = mrk, then it searches from ptr to the end of cntnt.  

##### size #####

Argument: 1 register.  
Output: size.  
Uses: void.  

Description:  
Stores the size of the argument register in the size register. If you have 100 characters in cntnt, and you run:

	> size cntnt

size will then contain the number 100.

##### capt #####

Argument: void.  
Output: capt.  
Uses: ptr, mrk, cntnt.  

Description:  
Captures the marked piece on cntnt into the capt register.  


##### trim #####

Argument: 1 register.  
Output: 1 register.  
Uses: void.  

Description:  
Trim all whitespace from the edges of a register.  

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