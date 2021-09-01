# libft
## Description
Re-implementation of Standard C Library functions.

## Requirement
- gcc or Clang
- GNU Make

## Usage
```sh
git clone https://github.com/tkomatsu/libft
make -c libft
```

Compiling with your source code.
```sh
gcc -I libft/includes <source code> -lft -L libft
```

example.c
```c
#include "libft.h"

int main()
{
	ft_putendl_fd("Hello world", STDOUT_FILENO);
	return 0;
}
```

## Author
- Tatushiro Komatsu

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details