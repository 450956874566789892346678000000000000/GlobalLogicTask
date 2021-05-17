# GlobalLogicTask
TEST FOR AUTOSAR ENGINEERS task for job application


#First task

A random ASCII character is received every 100ms. We need to find a sequence of "GLROX" characters. There can be other characters in between! Main function waits for user's input and send every character one by one in Process function.

Function:  Process
  called every 100 ms, inserts input character to buffer and check for sequence "GLROX", letters between are allowed.
Parameters :
  input : character from input.
  buffer: array of characters received.
  position: counter of positions in buffer.
  
Return value :
  returns: none
