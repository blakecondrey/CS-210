# CS-210
University C++ course


For this project, I was tasked with developing a Wildlife Zoo application. The application allowed the "Wildlife Zoo" organization manage their animal inventory 
through adding, deleting, and updating records of animals. The project's requirements and instructions tasked a user menu to be displayed, showing mulitple options 
for the user to load, generate display, add, delete, update, and save data on the animals in the zoo. Also, the project utilized a Java Native Interface (JNI) by 
integrating both Java and C++. The Java code was already provided and did not require any changes.

<strong>What did you do particularly well?</strong> <br><br> 
In this project, I did particularly well in adding functions that were not required, but that performed the leg work necessary for capturing user input and 
determining that the input was valid given the project requirements, ensuring accurate and unique data for each unique animal. Also, the bulk of the code in this 
project utlizes exception handling - a fantastic housekeeping tool for any programmer.

<strong>Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?</strong><br><br>
As a programmer, I could always enhance my code. There is never one right answer, and even the best code could be improved. As I'm continually growing as a 
developer, I tend to find improvements as time progresses. In this project, I utilized pointers for the animal class within a vector. Pointers are still a challenge
and if I research some more, I'm almost certain I could have done it better. Enhancing that aspect would ensure accuracy of the data, as well as utilizing memory
expert memory management - a necessity as a program grows larger and larger.

<strong>Did you find writing any piece of this code challenging, and how did you overcome this? What tools and/or resources are you adding to your support network?</strong><br><br>
Coding is a challenging skill that no one is inherently born with. It takes years of practice, failures, and research to become a master. In this project, I found
the necessity of validating the user's input to ensure the input met the length constraints, as well as ensuring the track numbers were not repeated. To solve this
problem, I researched how to collect the user input in string, then convert to int, and later converting back into string to prepend track numbers with as many 
zeroes as necessary so that, within the zoodata.txt file, the track numbers were always six digits long and started with zeroes. I overcame this by digging and
digging to find a solution. This mostly included cplusplus.com and stackoverflow.

<strong<What skills from this project will be particularly transferable to other projects and/or course work?</strong><br><br>
As i mentioned earlier, employing a lot of exception handling proved to be incredible for capturing accurate data. This will almost certainly be necessary for all
code that I write in my career. Also, employing a JNI when necessary is a fantastic tool to add to C++ development.

<strong>How did you make this program maintainable, readable, and adaptable?</strong><br><br>
Most notably, lots and lots of commenting. Apart from that, I created several functions that were not required from the spec that resulted in virtually no redundant
code. On the enterprise scale, this is necessary as extra coding, digging, debugging, all result in dollars spent. Creating maintainable, easy-to-read code not only
saves the company money, but simply makes a faster program while ensuring that the next programmer won't be left in a mess while updating the code.
