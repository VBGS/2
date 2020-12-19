# What is this?
This is a set of programs to quickly convert numbers in base 2, 4, 8, 10 or 16 to numbers in base 2, 4, 8 or 16.

# How to install it?
```sh
git clone https://github.com/VBGS/2.git
cd 2
sudo make install
```

# How to use it?
Each base has a corresponding letter:
  - b for binary
  - q for quaternary
  - o for octal
  - d for decimal
  - x for hexadecimal

Here's how to convert from hexadecimal to binary for example:
```sh
$ x2b F
1111
```

# How to uninstall?
```sh
sudo make clean
```
