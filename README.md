# Splitfile

Splitfile is a terminal utility that I created for personal use.

It splits large text files into smaller files of 5000 characters each.

## Prerequisites

- clang: for clang compilations
- make: frontend to handle compilation/install process

## Usage

> Note: you will need to use sudo to make install/uninstall as the program is being installed to /usr/local/bin to avoid breaking user space.

### Install the program

```
sudo make install
```


### Uninstall the program

```
sudo make uninstall
```

### Run the binary
```
splitfile
```
> Note: you may need to restart your terminal after the install to update your configs or use the `source` command.

Currently the program has to be run in the same directory as the file you want to split.

Simply provide the name of the text file you want to split when prompted to do so.

## Notice

The code is AGPLv3 - see license for more info.

### Legal Notice

I am not liable for how you use the splitfile program.
Any losses you incur are solely your own.
This program is provided expressly, as is, and without any warranty.
