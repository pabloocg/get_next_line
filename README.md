[![License][license-logo]][license-url]

<br />
<p align="center">
  <h1 align="center">get_next_line</h1>
  <p align="center">
    Reading a line on a fd is way too tedious
    <br />
    <a href="https://github.com/pabloocg/get_next_line/tree/master/"><strong>Explore the docs »</strong></a>
  </p>
</p>

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

## About The Project

The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

### Mandatory part

| Function name    	| get_next_line                                                                           	|
|------------------	|-----------------------------------------------------------------------------------------	|
| Prototype        	| int get_next_line(int fd, char **line);                                                 	|
| Turn in files    	| get_next_line.c, get_next_line_utils.c, get_next_line.h                                 	|
| Parameters       	| #1.  file descriptor for reading</br>#2.  The value of what has been read                   	|
| Return value     	| 1 :  A line has been read</br>0 :  EOF has been reached</br>-1 :  An error happened             	|
| External functs. 	| read, malloc, free                                                                      	|
| Description      	| Write a function which returns a line read from a file descriptor, without the newline. 	|

</br>
<hr>

- Calling your function get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the EOF.
- Your program must compile with the flag -D BUFFER_SIZE=XX. which will be used as the buffer size for the read calls in your get_next_line.
- Your read must use the BUFFER_SIZE defined during compilation to read froma file or from stdin.


### Bonus Part

- To succeed get_next_line with a single static variable.
- To be able to manage multiple file descriptor with your get_next_line. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.

## Getting Started

### Installation

1. Clone the repo
    ```sh
    git clone https://github.com/pabloocg/get_next_line.git
    ```
2. Enter the repository
    ```sh
    cd get_next_line
    ```

## Usage

Now you can use the get_next_line function in your projects!</br>
You must compile your program with the files belong to the function, and set the BUFFER_SIZE you want (by default BUFFER_SIZE is 1).
```sh
gcc -D BUFFER_SIZE=32 <your_program.c> get_next_line.c get_next_line_utils.c
```
Don't forget to include the get_next_line.h file in your project
```
#include "library_path/get_next_line.h"
```
An example of a call to the get_next_line function to read a file line by line would be the following:
```
char  *line;
int   fd;

fd = open("file.txt", O_RDONLY)
while (get_next_line(fd, &line))
{
  printf("%s\n", line);
  free(line);
}
```
## License

Distributed under the Apache License 2.0. See `LICENSE.txt` for more information.

## Contact

Pablo Cuadrado García </br>
[Linkedin][linkedin-url] - pablocuadrado97@gmail.com

[license-logo]: https://img.shields.io/hexpm/l/plug?style=for-the-badge
[license-url]: https://github.com/pabloocg/get_next_line/LICENSE.txt
[linkedin-url]: https://linkedin.com/in/pablo-cuadrado97

