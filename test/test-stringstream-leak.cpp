// https://stackoverflow.com/questions/20731/how-do-you-clear-a-stringstream-variable

#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string payload(16, 'x');

  std::stringstream *ss = new std::stringstream; // Create a memory leak
  (*ss) << payload;                              // Leak more memory

  // Now choose a way to "clear" a string stream
  // std::stringstream().swap(*ss); // Method 1
  // ss->str(std::string());        // Method 2

  /*
   *
streams are no toy. Memory is allocated in two parts:

  The constructed string stream (392 bytes)
  The extra buffer needed for the payload (513 bytes). The extraneous size has
to do with the allocation strategy chosen by the stream and for payloads <= 8
bytes, blocks inside the initial object can be used.

If you enable method 1 (the one shown in this answer) the extra 513 (payload)
bytes are reclaimed, because the stream is actually cleared.

If you enable method2 as suggested in the comments or other answers, you can see
that all 905 bytes are in use by the time we exit.

In terms of program semantics, one may only care that the stream "appears" and
"behaves" as empty, similar to how a vector::clear may leave the capacity
untouched but render the vector empty to the user (of course vector would spend
just 16 bytes here). Given the memory allocation that string stream requires, I
can imagine this approach being often faster. This answer's primary goal is to
actually clear the string stream, given that memory consumption that comes with
it is no joke. Depending on your use case (number of streams, data they hold,
frequency of clearing) you may choose the best approach.

Finally note that it's rarely useful to clear the stream without clearing the
error state and all inherited state. The one liner in this answer does both.
   *
   */
  std::cout << "end" << std::endl;
}
