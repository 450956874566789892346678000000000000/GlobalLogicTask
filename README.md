# GlobalLogicTask
TEST FOR AUTOSAR ENGINEERS task for job application


 # First task

A random ASCII character is received every 100ms. We need to find a sequence of "GLROX" characters. There can be other characters in between! Main function waits for user's input and send every character one by one in Process function.

Function:  Process 
Called every 100 ms, inserts input character to buffer and check for sequence "GLROX", letters between are allowed.
 
Parameters :
input : character from input.
buffer: array of characters received.
position: counter of positions in buffer.
Returning value : 
Returns: noneReturning value : 
Returns: none


Function: Found
Called when sequence is found, print notification to console, restarts buffer and his position counter
 
Parameters :
Buffer: array of characters received
Position: counter of positions in buffer
Returning value : 
Returns: none

Function:  Timeout
Called when there is no received input for 2 seconds, print notification to console, restarts buffer and his position counter

Parameters :
buffer: array of characters received
position: counter of positions in buffer

Returning value : 
Returns: none

# Second task

Main function generate random numbers from defined range and process them by rules given in task description. 
